import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

// Base Component class
abstract class Component {
    private String name;
    private double price;

    public Component(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public String getName() { return name; }
    public double getPrice() { return price; }
    @Override
    public String toString() { return name + " (" + price + "৳)"; }
}

// Specific Component subclass (example)
class Processor extends Component {
    public Processor(String name, double price) {
        super(name, price);
    }
}

public class PCBuilder extends JFrame {
    private Map<String, JTextField> componentFields = new HashMap<>();
    private Map<String, ArrayList<Component>> componentOptions = new HashMap<>();
    private JLabel totalLabel;
    private double totalAmount = 0.0;
    private DecimalFormat df = new DecimalFormat("#,##0.00");

    public PCBuilder() {
        // Frame setup
        setTitle("PC Builder");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        setSize(600, 700);

        // Header Panel
        JPanel header = new JPanel(new BorderLayout());
        header.setBackground(Color.WHITE);
        JLabel logo = new JLabel("PC BUILDER", SwingConstants.LEFT);
        logo.setFont(new Font("Oswald", Font.BOLD, 20));
        header.add(logo, BorderLayout.WEST);

        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        JButton addToCart = new JButton("Add to Cart");
        JButton saveBuild = new JButton("Save Build");
        JButton screenshot = new JButton("Screenshot");
        JButton clearAll = new JButton("Clear All");
        buttonPanel.add(addToCart);
        buttonPanel.add(saveBuild);
        buttonPanel.add(screenshot);
        buttonPanel.add(clearAll);
        header.add(buttonPanel, BorderLayout.EAST);
        add(header, BorderLayout.NORTH);

        // Title and Total Panel
        JPanel titlePanel = new JPanel(new FlowLayout());
        titlePanel.setBackground(Color.WHITE);
        JLabel title = new JLabel("PC Builder - Build your own PC");
        totalLabel = new JLabel("Total Amount: 0৳");
        totalLabel.setForeground(Color.GREEN);
        titlePanel.add(title);
        titlePanel.add(totalLabel);
        add(titlePanel, BorderLayout.CENTER);

        // Main Content Panel
        JPanel content = new JPanel(new GridLayout(2, 1));
        content.add(createComponentSection("CORE COMPONENTS", new String[]{
            "Processor*", "Motherboard*", "Graphics Card", "CPU Cooler", "RAM-1*", "RAM-2",
            "SSD", "HDD", "Power Supply", "Casing"
        }));
        content.add(createComponentSection("PERIPHERALS & OTHERS", new String[]{"Monitor"}));
        add(new JScrollPane(content), BorderLayout.SOUTH);

        // Load component options
        loadComponents();

        // Action Listeners
        addToCart.addActionListener(e -> JOptionPane.showMessageDialog(this, "Added to Cart!"));
        saveBuild.addActionListener(e -> saveBuild());
        screenshot.addActionListener(e -> takeScreenshot());
        clearAll.addActionListener(e -> clearAll());

        setVisible(true);
    }

    private JPanel createComponentSection(String title, String[] components) {
        JPanel panel = new JPanel(new BorderLayout());
        panel.setBorder(BorderFactory.createTitledBorder(title));
        JPanel grid = new JPanel(new GridLayout(components.length, 1));
        
        for (String comp : components) {
            JPanel row = new JPanel(new FlowLayout(FlowLayout.LEFT));
            row.add(new JLabel("[Icon]")); // Placeholder for icon
            row.add(new JLabel(comp));
            JTextField field = new JTextField(20);
            field.setEditable(false);
            row.add(field);
            JButton choose = new JButton("Choose");
            choose.setBackground(Color.BLUE.darker());
            choose.setForeground(Color.WHITE);
            row.add(choose);
            grid.add(row);
            componentFields.put(comp, field);

            choose.addActionListener(e -> chooseComponent(comp, field));
        }
        panel.add(grid, BorderLayout.CENTER);
        return panel;
    }

    private void loadComponents() {
        // Simulate loading from a file (components.csv)
        componentOptions.put("Processor*", new ArrayList<>(Arrays.asList(
            new Processor("Intel i7", 25000), new Processor("AMD Ryzen 5", 20000))));
        componentOptions.put("Motherboard*", new ArrayList<>(Arrays.asList(
            new Processor("ASUS ROG", 15000), new Processor("Gigabyte B550", 12000))));
        componentOptions.put("Graphics Card", new ArrayList<>(Arrays.asList(
            new Processor("NVIDIA RTX 3060", 35000), new Processor("AMD RX 6600", 30000))));
        // Add more options for other components similarly
    }

    private void chooseComponent(String componentName, JTextField field) {
        ArrayList<Component> options = componentOptions.getOrDefault(componentName, new ArrayList<>());
        if (options.isEmpty()) {
            JOptionPane.showMessageDialog(this, "No options available for " + componentName);
            return;
        }
        JComboBox<Component> comboBox = new JComboBox<>(options.toArray(new Component[0]));
        int result = JOptionPane.showConfirmDialog(this, comboBox, "Select " + componentName, JOptionPane.OK_CANCEL_OPTION);
        if (result == JOptionPane.OK_OPTION) {
            Component selected = (Component) comboBox.getSelectedItem();
            field.setText(selected.getName());
            updateTotal(selected.getPrice());
        }
    }

    private void updateTotal(double price) {
        totalAmount += price;
        totalLabel.setText("Total Amount: " + df.format(totalAmount) + "৳");
    }

    private void saveBuild() {
        try (PrintWriter writer = new PrintWriter("build.txt")) {
            for (Map.Entry<String, JTextField> entry : componentFields.entrySet()) {
                writer.println(entry.getKey() + ": " + entry.getValue().getText());
            }
            writer.println("Total Amount: " + totalAmount + "৳");
            JOptionPane.showMessageDialog(this, "Build saved successfully!");
        } catch (FileNotFoundException e) {
            JOptionPane.showMessageDialog(this, "Error saving build!", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void takeScreenshot() {
        JOptionPane.showMessageDialog(this, "Screenshot functionality not implemented in this demo.");
        // Use Robot class for actual screenshot if needed
    }

    private void clearAll() {
        componentFields.values().forEach(field -> field.setText(""));
        totalAmount = 0.0;
        totalLabel.setText("Total Amount: 0৳");
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(PCBuilder::new);
    }
}