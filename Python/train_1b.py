import time
import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import Dataset, DataLoader

# Benchmark Settings
BATCH_SIZE = 2
SEQ_LENGTH = 512
VOCAB_SIZE = 32000
HIDDEN_SIZE = 2048
NUM_LAYERS = 14
NUM_HEADS = 16
INTERMEDIATE_SIZE = 8192  # feed-forward dimension
EPOCHS = 3
SAMPLES_PER_EPOCH = 20  # 10 batches of batch_size 2 per epoch

print("=" * 60)
print("1-BILLION-PARAMETER MODEL EPOCH-BASED BENCHMARK ON INTEL ARC GPU")
print("=" * 60)

# Check for XPU
if not torch.xpu.is_available():
    print("ERROR: Intel XPU (GPU) is not available. Please verify your driver and installation.")
    exit(1)

device = torch.device("xpu")
print(f"Device Name: {torch.xpu.get_device_name(0)}")
print(f"Total GPU Memory: {torch.xpu.get_device_properties(0).total_memory / (1024**3):.2f} GB")

# Define a basic Llama-like Transformer Layer for parameter scale
class SimpleTransformerLayer(nn.Module):
    def __init__(self, hidden_size, num_heads, intermediate_size):
        super().__init__()
        self.attn_qkv = nn.Linear(hidden_size, 3 * hidden_size, bias=False)
        self.attn_out = nn.Linear(hidden_size, hidden_size, bias=False)
        
        # SwiGLU MLP: Gate and Up projections
        self.mlp_gate_up = nn.Linear(hidden_size, 2 * intermediate_size, bias=False)
        self.mlp_down = nn.Linear(intermediate_size, hidden_size, bias=False)
        
        self.norm1 = nn.LayerNorm(hidden_size)
        self.norm2 = nn.LayerNorm(hidden_size)

    def forward(self, x):
        # Attention approximation
        norm_x = self.norm1(x)
        qkv = self.attn_qkv(norm_x)
        # Approximate self-attention computation
        attn_out = self.attn_out(norm_x)
        x = x + attn_out
        
        # MLP approximation
        norm_x2 = self.norm2(x)
        gate_up = self.mlp_gate_up(norm_x2)
        gate, up = gate_up.chunk(2, dim=-1)
        # Swish activation approximation
        activated = (gate * torch.sigmoid(gate)) * up
        mlp_out = self.mlp_down(activated)
        x = x + mlp_out
        return x

class OneBillionParamModel(nn.Module):
    def __init__(self, vocab_size, hidden_size, num_layers, num_heads, intermediate_size):
        super().__init__()
        self.embed = nn.Embedding(vocab_size, hidden_size)
        self.layers = nn.ModuleList([
            SimpleTransformerLayer(hidden_size, num_heads, intermediate_size)
            for _ in range(num_layers)
        ])
        self.norm = nn.LayerNorm(hidden_size)
        self.lm_head = nn.Linear(hidden_size, vocab_size, bias=False)

    def forward(self, input_ids):
        x = self.embed(input_ids)
        for layer in self.layers:
            x = layer(x)
        x = self.norm(x)
        logits = self.lm_head(x)
        return logits

# Initialize Model
print("\n[1/5] Initializing model parameters on CPU...")
start_time = time.time()
model = OneBillionParamModel(VOCAB_SIZE, HIDDEN_SIZE, NUM_LAYERS, NUM_HEADS, INTERMEDIATE_SIZE)
init_time = time.time() - start_time

# Count parameters
total_params = sum(p.numel() for p in model.parameters())
trainable_params = sum(p.numel() for p in model.parameters() if p.requires_grad)
print(f"  Total Parameters: {total_params:,} ({total_params / 1e9:.3f} Billion)")
print(f"  Trainable Parameters: {trainable_params:,}")
print(f"  Initialization Time: {init_time:.2f} seconds")

# Move to GPU
print("\n[2/5] Moving model to Intel Arc GPU (XPU)...")
start_time = time.time()
try:
    # Use bfloat16 to optimize memory usage (crucial for 1B parameters on 16GB VRAM)
    model = model.to(device=device, dtype=torch.bfloat16)
    torch.xpu.synchronize()
    gpu_move_time = time.time() - start_time
    print(f"  Moved to GPU in: {gpu_move_time:.2f} seconds")
    print(f"  Allocated VRAM: {torch.xpu.memory_allocated(0) / (1024**3):.2f} GB")
except Exception as e:
    print(f"  Failed to move model to GPU: {e}")
    exit(1)

# Generate dataset and DataLoader
print("\n[3/5] Setting up Dummy Dataset and PyTorch DataLoader...")
class DummyDataset(Dataset):
    def __init__(self, num_samples, seq_length, vocab_size):
        self.num_samples = num_samples
        self.seq_length = seq_length
        self.vocab_size = vocab_size

    def __len__(self):
        return self.num_samples

    def __getitem__(self, idx):
        # Generate random inputs and targets
        x = torch.randint(0, self.vocab_size, (self.seq_length,))
        y = torch.randint(0, self.vocab_size, (self.seq_length,))
        return x, y

dataset = DummyDataset(SAMPLES_PER_EPOCH, SEQ_LENGTH, VOCAB_SIZE)
dataloader = DataLoader(dataset, batch_size=BATCH_SIZE, shuffle=True)
print(f"  Dataset size: {len(dataset)} samples")
print(f"  Batch size: {BATCH_SIZE}")
print(f"  Batches per epoch: {len(dataloader)}")

# Configure Optimizer and Loss
optimizer = optim.AdamW(model.parameters(), lr=1e-5)
criterion = nn.CrossEntropyLoss()

print("\n[4/5] Pre-warming GPU with a single step...")
try:
    # Warmup step to initialize JIT compilation, optimizer states, etc.
    x_warm, y_warm = next(iter(dataloader))
    x_warm, y_warm = x_warm.to(device), y_warm.to(device)
    optimizer.zero_grad()
    with torch.amp.autocast("xpu", dtype=torch.bfloat16):
        out_warm = model(x_warm)
        loss_warm = criterion(out_warm.view(-1, VOCAB_SIZE), y_warm.view(-1))
    loss_warm.backward()
    optimizer.step()
    torch.xpu.synchronize()
    print("  Warmup successful.")
except Exception as e:
    print(f"  Warmup failed: {e}")
    exit(1)

print("\n[5/5] Starting training loop across epochs...")
print("=" * 60)

try:
    global_start_time = time.time()
    for epoch in range(1, EPOCHS + 1):
        epoch_start_time = time.time()
        running_loss = 0.0
        batch_times = []
        
        print(f"\n--- Epoch {epoch}/{EPOCHS} ---")
        
        for batch_idx, (x, y) in enumerate(dataloader):
            batch_start = time.time()
            
            # Move data to GPU
            x, y = x.to(device), y.to(device)
            
            # Zero gradients
            optimizer.zero_grad()
            
            # Forward pass with mixed-precision
            with torch.amp.autocast("xpu", dtype=torch.bfloat16):
                outputs = model(x)
                loss = criterion(outputs.view(-1, VOCAB_SIZE), y.view(-1))
                
            # Backward pass
            loss.backward()
            
            # Optimizer step
            optimizer.step()
            
            # Sync to measure accurate step time
            torch.xpu.synchronize()
            batch_time = time.time() - batch_start
            batch_times.append(batch_time)
            
            running_loss += loss.item()
            
            # Throughput
            tokens_processed = BATCH_SIZE * SEQ_LENGTH
            throughput = tokens_processed / batch_time
            
            allocated_mem = torch.xpu.memory_allocated(0) / (1024**3)
            print(f"  Batch {batch_idx+1}/{len(dataloader)} | Loss: {loss.item():.4f} | Time: {batch_time:.3f}s | Throughput: {throughput:.1f} tokens/s | VRAM: {allocated_mem:.2f} GB")

        epoch_time = time.time() - epoch_start_time
        avg_loss = running_loss / len(dataloader)
        avg_batch_time = sum(batch_times) / len(batch_times)
        avg_throughput = (len(dataloader) * BATCH_SIZE * SEQ_LENGTH) / epoch_time
        
        print(f"Epoch {epoch} Summary:")
        print(f"  Average Loss: {avg_loss:.4f}")
        print(f"  Epoch Duration: {epoch_time:.2f}s (Avg batch time: {avg_batch_time:.3f}s)")
        print(f"  Average Throughput: {avg_throughput:.1f} tokens/s")

    total_training_time = time.time() - global_start_time
    print("\n" + "=" * 60)
    print("EPOCH BENCHMARK COMPLETED SUCCESSFULLY!")
    print(f"Total training time: {total_training_time:.2f} seconds")
    print(f"Peak VRAM Reserved: {torch.xpu.max_memory_reserved(0) / (1024**3):.2f} GB")
    print("=" * 60)

except torch.xpu.OutOfMemoryError as oom:
    print("\n" + "!" * 60)
    print("OUT OF MEMORY ERROR DETECTED!")
    print("!" * 60)
    print("1 Billion parameters requires significant memory for weights, gradients, and optimizer states.")
    print("To run this model on 16GB VRAM, try these optimizations:")
    print("  1. Decrease BATCH_SIZE to 1.")
    print("  2. Decrease SEQ_LENGTH (e.g., to 256).")
    print("  3. Use SGD instead of AdamW.")
    print("  4. Enable gradient checkpointing.")
    print("!" * 60)
except Exception as e:
    print(f"An unexpected error occurred during training: {e}")