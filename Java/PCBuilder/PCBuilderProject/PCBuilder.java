import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.text.DecimalFormat;
import java.io.*;

public class PCBuilder extends BaseFrame {
    private Map<String, JComboBox<Component>> componentComboBoxes = new HashMap<>();
    private Map<String, ArrayList<Component>> componentOptions = new HashMap<>();
    private JLabel totalLabel;
    private double totalAmount = 0.0;
    private DecimalFormat df = new DecimalFormat("#,##0.00");
    private java.util.List<String> componentOrder = Arrays.asList(
        "Processor*", "Motherboard*", "Graphics Card", "CPU Cooler", "RAM-1*", "RAM-2",
        "SSD", "HDD", "Power Supply", "Casing", "Monitor", "Case fan", "UPS", "Mouse", "Keyboard", "Headphone"
    );

    public PCBuilder() {
        super("PC Builder - TechLand");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        setSize(800, 700);

        // Header Panel with Buttons
        JPanel header = new JPanel(new BorderLayout());
        header.setBackground(Color.WHITE);
        JLabel logo = new JLabel("TECH LAND", SwingConstants.LEFT);
        logo.setFont(new Font("Arial", Font.BOLD, 20));
        header.add(logo, BorderLayout.WEST);

        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        JButton addToCart = new JButton("Add to Cart");
        customizeButton(addToCart);
        JButton loadBuild = new JButton("Load Build");
        customizeButton(loadBuild);
        JButton clearAll = new JButton("Clear All");
        customizeButton(clearAll);
        buttonPanel.add(addToCart);
        buttonPanel.add(loadBuild);
        buttonPanel.add(clearAll);
        header.add(buttonPanel, BorderLayout.EAST);
        add(header, BorderLayout.NORTH);

        // Center Panel with Title, Total, and Components
        JPanel centerPanel = new JPanel(new BorderLayout());
        
        // Title and Total Panel
        JPanel titlePanel = new JPanel(new FlowLayout());
        titlePanel.setBackground(Color.WHITE);
        JLabel title = new JLabel("PC Builder - Build your own PC - TechLand");
        title.setFont(new Font("Arial", Font.BOLD, 18));
        totalLabel = new JLabel("Total Amount: 0৳");
        totalLabel.setForeground(Color.ORANGE);
        totalLabel.setFont(new Font("Arial", Font.BOLD, 16));
        titlePanel.add(title);
        titlePanel.add(totalLabel);
        centerPanel.add(titlePanel, BorderLayout.NORTH);

        // Component Sections
        JPanel content = new JPanel(new GridLayout(3, 1));
        content.add(createComponentSection("CORE COMPONENTS", new String[]{
            "Processor*", "Motherboard*", "Graphics Card", "CPU Cooler", "RAM-1*", "RAM-2",
            "SSD", "HDD", "Power Supply", "Casing"
        }));
        content.add(createComponentSection("PERIPHERALS & OTHERS", new String[]{
            "Monitor", "Case fan", "UPS"
        }));
        content.add(createComponentSection("ACCESSORIES", new String[]{
            "Mouse", "Keyboard", "Headphone"
        }));
        JScrollPane scrollPane = new JScrollPane(content);
        scrollPane.getVerticalScrollBar().setUnitIncrement(16);
        centerPanel.add(scrollPane, BorderLayout.CENTER);
        add(centerPanel, BorderLayout.CENTER);

        // Load Components
        loadComponents();

        // Action Listeners
        addToCart.addActionListener(e -> {
            if (saveBuild()) {
                JOptionPane.showMessageDialog(this, "Build saved and added to cart!");
            } else {
                JOptionPane.showMessageDialog(this, "Error saving build!", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });
        loadBuild.addActionListener(e -> new SavedBuildsFrame());
        clearAll.addActionListener(e -> clearAll());

        setVisible(true);
    }

    private void customizeButton(JButton button) {
        button.setBackground(Color.BLUE);
        button.setForeground(Color.WHITE);
        button.setBorder(BorderFactory.createLineBorder(Color.BLACK, 2));
        button.setFont(new Font("Arial", Font.BOLD, 14));
    }

    private JPanel createComponentSection(String title, String[] components) {
        JPanel panel = new JPanel(new BorderLayout());
        panel.setBackground(new Color(240, 240, 240));
        panel.setBorder(BorderFactory.createTitledBorder(title));
        JPanel grid = new JPanel(new GridLayout(components.length, 1));

        for (String comp : components) {
            JPanel row = new JPanel(new FlowLayout(FlowLayout.LEFT));
            JLabel label = new JLabel(comp);
            label.setFont(new Font("Arial", Font.PLAIN, 14));
            row.add(label);
            ArrayList<Component> options = componentOptions.getOrDefault(comp, new ArrayList<>());
            JComboBox<Component> comboBox = new JComboBox<>(options.toArray(new Component[0]));
            comboBox.setPreferredSize(new Dimension(400, 25));
            comboBox.addActionListener(e -> updateTotal());
            row.add(comboBox);
            grid.add(row);
            componentComboBoxes.put(comp, comboBox);
        }
        panel.add(grid, BorderLayout.CENTER);
        return panel;
    }

    private void loadComponents() {
        Component select = new Component("Select", 0);

        componentOptions.put("Processor*", new ArrayList<>(Arrays.asList(select,
            new Component("Intel i7-12700K", 25000),
            new Component("AMD Ryzen 5 5600X", 20000),
            new Component("Intel i5-12400F", 18000))));
        componentOptions.put("Motherboard*", new ArrayList<>(Arrays.asList(select,
            new Component("ASUS ROG Strix Z690", 15000),
            new Component("Gigabyte B550 Aorus", 12000),
            new Component("MSI MAG B660", 10000))));
        componentOptions.put("Graphics Card", new ArrayList<>(Arrays.asList(select,
            new Component("NVIDIA RTX 3060", 35000),
            new Component("AMD RX 6600 XT", 30000),
            new Component("NVIDIA GTX 1660 Super", 25000))));
        componentOptions.put("CPU Cooler", new ArrayList<>(Arrays.asList(select,
            new Component("Cooler Master Hyper 212", 3000),
            new Component("Noctua NH-D15", 7000))));
        componentOptions.put("RAM-1*", new ArrayList<>(Arrays.asList(select,
            new Component("Corsair Vengeance 8GB DDR4", 4000),
            new Component("G.Skill Ripjaws 16GB DDR4", 8000))));
        componentOptions.put("RAM-2", new ArrayList<>(Arrays.asList(select,
            new Component("Corsair Vengeance 8GB DDR4", 4000),
            new Component("G.Skill Ripjaws 16GB DDR4", 8000))));
        componentOptions.put("SSD", new ArrayList<>(Arrays.asList(select,
            new Component("Samsung 970 EVO 500GB", 8000),
            new Component("Crucial MX500 1TB", 10000))));
        componentOptions.put("HDD", new ArrayList<>(Arrays.asList(select,
            new Component("Seagate Barracuda 1TB", 4000),
            new Component("Western Digital Blue 2TB", 6000))));
        componentOptions.put("Power Supply", new ArrayList<>(Arrays.asList(select,
            new Component("EVGA 600W 80+ Bronze", 5000),
            new Component("Corsair RM750x 80+ Gold", 9000))));
        componentOptions.put("Casing", new ArrayList<>(Arrays.asList(select,
            new Component("NZXT H510", 6000),
            new Component("Fractal Design Meshify C", 8000))));

        componentOptions.put("Monitor", new ArrayList<>(Arrays.asList(select,
            new Component("Dell UltraSharp 24\"", 15000),
            new Component("ASUS TUF Gaming 27\"", 20000))));
        componentOptions.put("Case fan", new ArrayList<>(Arrays.asList(select,
            new Component("Noctua NF-F12", 1500),
            new Component("Corsair LL120 RGB", 2000))));
        componentOptions.put("UPS", new ArrayList<>(Arrays.asList(select,
            new Component("APC Back-UPS 600VA", 5000),
            new Component("CyberPower CP1500 AVR", 10000))));

        componentOptions.put("Mouse", new ArrayList<>(Arrays.asList(select,
            new Component("Logitech G502 Hero", 4000),
            new Component("Razer DeathAdder V2", 3000))));
        componentOptions.put("Keyboard", new ArrayList<>(Arrays.asList(select,
            new Component("Corsair K70 RGB", 8000),
            new Component("Logitech G Pro X", 6000))));
        componentOptions.put("Headphone", new ArrayList<>(Arrays.asList(select,
            new Component("Sony WH-1000XM4", 25000),
            new Component("Bose QuietComfort 35 II", 20000))));

        for (String key : componentComboBoxes.keySet()) {
            JComboBox<Component> comboBox = componentComboBoxes.get(key);
            comboBox.setModel(new DefaultComboBoxModel<>(componentOptions.get(key).toArray(new Component[0])));
        }
    }

    private void updateTotal() {
        totalAmount = 0.0;
        for (JComboBox<Component> comboBox : componentComboBoxes.values()) {
            Component selected = (Component) comboBox.getSelectedItem();
            if (selected != null && !selected.getName().equals("Select")) {
                totalAmount += selected.getPrice();
            }
        }
        totalLabel.setText("Total Amount: " + df.format(totalAmount) + "৳");
    }

    private boolean saveBuild() {
        try (PrintWriter writer = new PrintWriter(new FileWriter("build.txt", true))) {
            for (String comp : componentOrder) {
                JComboBox<Component> comboBox = componentComboBoxes.get(comp);
                if (comboBox != null) {
                    Component selected = (Component) comboBox.getSelectedItem();
                    if (selected != null && !selected.getName().equals("Select")) {
                        writer.println(comp + ": " + selected.getName());
                    } else {
                        writer.println(comp + ": Not selected");
                    }
                }
            }
            writer.println("Total Amount: " + totalAmount + "৳");
            writer.println("-----");
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    private void clearAll() {
        for (JComboBox<Component> comboBox : componentComboBoxes.values()) {
            comboBox.setSelectedIndex(0);
        }
        updateTotal();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(PCBuilder::new);
    }
}