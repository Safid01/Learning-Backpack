import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;

public class PCBuilder extends BaseFrame {

    private JLabel totalLabel;
    private Map<String, JComboBox<Component>> componentComboBoxes;
    private Map<String, ArrayList<Component>> componentOptions;

    public PCBuilder() {
        super("PC Builder");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        componentComboBoxes = new HashMap<>();
        componentOptions = new HashMap<>();
        loadComponents();

        JPanel mainPanel = new JPanel(new BorderLayout(10, 10));
        mainPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        mainPanel.setBackground(Color.WHITE);

        JPanel titlePanel = new JPanel(new FlowLayout());
        titlePanel.setBackground(Color.WHITE);
        JLabel title = new JLabel("Build your own PC");
        title.setFont(new Font("Segoe UI", Font.BOLD, 18));
        title.setForeground(Color.BLACK);
        totalLabel = new JLabel("Total Amount: 0৳");
        totalLabel.setForeground(Color.ORANGE);
        totalLabel.setFont(new Font("Roboto", Font.BOLD, 16));
        JPanel totalPanel = new JPanel();
        totalPanel.setBackground(Color.WHITE);
        totalPanel.setBorder(BorderFactory.createLineBorder(Color.BLACK, 2));
        totalPanel.add(totalLabel);
        titlePanel.add(title);
        titlePanel.add(totalPanel);

        String[] coreComponents = {"Processor*", "Motherboard*", "CPU Cooler*", "RAM-1*", "RAM-2", "Graphics Card", "Storage*", "Power Supply*", "Case*"};
        String[] peripherals = {"Monitor", "Keyboard", "Mouse"};
        String[] accessories = {"Cooling Fan", "Cables"};

        JPanel coreComponentsPanel = createComponentSection("Core Components", coreComponents);
        JPanel peripheralsPanel = createComponentSection("Peripherals", peripherals);
        JPanel accessoriesPanel = createComponentSection("Accessories", accessories);

        JScrollPane coreScrollPane = new JScrollPane(coreComponentsPanel);
        coreScrollPane.setBorder(BorderFactory.createTitledBorder("Core Components"));
        coreScrollPane.getViewport().setBackground(Color.WHITE);
        JScrollPane peripheralsScrollPane = new JScrollPane(peripheralsPanel);
        peripheralsScrollPane.setBorder(BorderFactory.createTitledBorder("Peripherals"));
        peripheralsScrollPane.getViewport().setBackground(Color.WHITE);
        JScrollPane accessoriesScrollPane = new JScrollPane(accessoriesPanel);
        accessoriesScrollPane.setBorder(BorderFactory.createTitledBorder("Accessories"));
        accessoriesScrollPane.getViewport().setBackground(Color.WHITE);

        JTabbedPane tabbedPane = new JTabbedPane();
        tabbedPane.addTab("Core Components", coreScrollPane);
        tabbedPane.addTab("Peripherals", peripheralsScrollPane);
        tabbedPane.addTab("Accessories", accessoriesScrollPane);
        tabbedPane.setBackground(Color.WHITE);

        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 20, 10));
        buttonPanel.setBackground(Color.WHITE);

        JButton savebuild = new JButton("Save Build");
        JButton loadBuild = new JButton("Load Build");
        JButton clearAll = new JButton("Clear All");

        customizeButton(savebuild);
        customizeButton(loadBuild);
        customizeButton(clearAll);

        savebuild.setIcon(loadIcon("add_to_cart"));
        savebuild.setBackground(new Color(0, 153, 0));
        loadBuild.setIcon(loadIcon("load_build"));
        loadBuild.setBackground(new Color(0, 102, 204));
        clearAll.setIcon(loadIcon("clear_all"));
        clearAll.setBackground(new Color(204, 0, 0));

        buttonPanel.add(savebuild);
        buttonPanel.add(loadBuild);
        buttonPanel.add(clearAll);

        savebuild.addActionListener(e -> savebuild());
        loadBuild.addActionListener(e -> loadBuild());
        clearAll.addActionListener(e -> clearAll());

        mainPanel.add(titlePanel, BorderLayout.NORTH);
        mainPanel.add(tabbedPane, BorderLayout.CENTER);
        mainPanel.add(buttonPanel, BorderLayout.SOUTH);

        add(mainPanel);
        setSize(600, 700);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private JPanel createComponentSection(String title, String[] components) {
        JPanel grid = new JPanel();
        grid.setLayout(new BoxLayout(grid, BoxLayout.Y_AXIS));
        grid.setBackground(Color.WHITE);

        for (String comp : components) {
            JPanel row = new JPanel(new FlowLayout(FlowLayout.LEFT));
            row.setBackground(Color.WHITE);

            JLabel label = new JLabel(comp.replace("*", "") + ":");
            label.setPreferredSize(new Dimension(100, 30));
            label.setForeground(Color.BLACK);
            label.setFont(new Font("Arial", Font.PLAIN, 14));
            ArrayList<Component> options = componentOptions.get(comp);
            JComboBox<Component> comboBox = new JComboBox<>(options.toArray(new Component[0]));
            comboBox.setRenderer(new ComponentRenderer(comp));
            comboBox.setPreferredSize(new Dimension(400, 30));
            comboBox.setBackground(Color.WHITE);
            comboBox.setForeground(Color.BLACK);
            comboBox.setFont(new Font("Tahoma", Font.PLAIN, 12));
            componentComboBoxes.put(comp, comboBox);

            comboBox.addActionListener(e -> updateTotal());

            row.add(label);
            row.add(comboBox);
            grid.add(row);
        }
        return grid;
    }

    private void loadComponents() {
        componentOptions.put("Processor*", new ArrayList<>(Arrays.asList(
            new Component("Not Selected", 0),
            new Component("Intel i9-12900K", 55000),
            new Component("AMD Ryzen 9 5950X", 50000)
        )));
        componentOptions.put("Motherboard*", new ArrayList<>(Arrays.asList(
            new Component("Not Selected", 0),
            new Component("ASUS ROG Strix Z690", 25000),
            new Component("MSI MPG B550 Gaming Edge", 15000)
        )));
        componentOptions.put("CPU Cooler*", new ArrayList<>(Arrays.asList(
            new Component("Not Selected", 0),
            new Component("Noctua NH-D15", 8000),
            new Component("Corsair H100i", 10000)
        )));
        componentOptions.put("RAM-1*", new ArrayList<>(Arrays.asList(
            new Component("Not Selected", 0),
            new Component("Corsair Vengeance 16GB", 8000),
            new Component("G.Skill Ripjaws 32GB", 12000)
        )));
        componentOptions.put("RAM-2", new ArrayList<>(Arrays.asList(
            new Component("Not Selected", 0),
            new Component("Corsair Vengeance 16GB", 8000),
            new Component("G.Skill Ripjaws 32GB", 12000)
        )));
        componentOptions.put("Graphics Card", new ArrayList<>(Arrays.asList(
            new Component("Not Selected", 0),
            new Component("NVIDIA RTX 3080", 70000),
            new Component("AMD Radeon RX 6800 XT", 65000)
        )));
        componentOptions.put("Storage*", new ArrayList<>(Arrays.asList(
            new Component("Not Selected", 0),
            new Component("Samsung 970 EVO 1TB", 15000),
            new Component("Western Digital 2TB HDD", 5000)
        )));
        componentOptions.put("Power Supply*", new ArrayList<>(Arrays.asList(
            new Component("Not Selected", 0),
            new Component("Corsair RM750", 10000),
            new Component("EVGA SuperNOVA 850", 12000)
        )));
        componentOptions.put("Case*", new ArrayList<>(Arrays.asList(
            new Component("Not Selected", 0),
            new Component("NZXT H510", 7000),
            new Component("Cooler Master MasterBox Q300L", 5000)
        )));
        componentOptions.put("Monitor", new ArrayList<>(Arrays.asList(
            new Component("Not Selected", 0),
            new Component("Dell UltraSharp 27\"", 25000),
            new Component("ASUS TUF Gaming 24\"", 18000)
        )));
        componentOptions.put("Keyboard", new ArrayList<>(Arrays.asList(
            new Component("Not Selected", 0),
            new Component("Logitech G Pro", 8000),
            new Component("Razer BlackWidow", 10000)
        )));
        componentOptions.put("Mouse", new ArrayList<>(Arrays.asList(
            new Component("Not Selected", 0),
            new Component("Logitech G502", 5000),
            new Component("Razer DeathAdder", 4000)
        )));
        componentOptions.put("Cooling Fan", new ArrayList<>(Arrays.asList(
            new Component("Not Selected", 0),
            new Component("Noctua NH-D15", 8000),
            new Component("Corsair LL120", 3000)
        )));
        componentOptions.put("Cables", new ArrayList<>(Arrays.asList(
            new Component("Not Selected", 0),
            new Component("SATA Cable Pack", 500),
            new Component("HDMI Cable", 1000)
        )));
    }

    private void updateTotal() {
        int total = 0;
        for (JComboBox<Component> comboBox : componentComboBoxes.values()) {
            Component selected = (Component) comboBox.getSelectedItem();
            if (selected != null) total += selected.getPrice();
        }
        totalLabel.setText("Total Amount: " + total + "৳");
    }

    private void savebuild() {
        StringBuilder build = new StringBuilder();
        boolean allRequiredSelected = true;

        for (String key : componentComboBoxes.keySet()) {
            Component selected = (Component) componentComboBoxes.get(key).getSelectedItem();
            if (selected != null) {
                if (key.contains("*") && selected.getName().equals("Select")) {
                    allRequiredSelected = false;
                    break;
                }
                build.append(key.replace("*", "")).append(": ").append(selected).append("\n");
            }
        }

        if (!allRequiredSelected) {
            JOptionPane.showMessageDialog(this, "Please select all required components marked with *", "Incomplete Build", JOptionPane.WARNING_MESSAGE);
            return;
        }

        try (BufferedWriter bw = new BufferedWriter(new FileWriter("SavedBuilds.txt", true))) {
            bw.write(build.toString());
            bw.newLine();
            bw.write("-----"); // Add separator line
            bw.newLine();
            JOptionPane.showMessageDialog(this, "Build saved successfully!", "Success", JOptionPane.INFORMATION_MESSAGE); // Updated message
        } 
        catch (IOException e) {
        e.printStackTrace();
        }  
    }

    private void loadBuild() {
        new SavedBuildsFrame();
    }

    private void clearAll() {
        for (JComboBox<Component> comboBox : componentComboBoxes.values()) {
            comboBox.setSelectedIndex(0);
        }
        updateTotal();
    }

    public void loadBuild(String build) {
        String[] lines = build.split("\n");
        for (String line : lines) {
            String[] parts = line.split(": ", 2);
            if (parts.length == 2) {
                String category = parts[0];
                String componentName = parts[1].substring(0, parts[1].indexOf(" ("));
                JComboBox<Component> comboBox = componentComboBoxes.get(category + "*");
                if (comboBox == null) comboBox = componentComboBoxes.get(category);
                if (comboBox != null) {
                    for (int i = 0; i < comboBox.getItemCount(); i++) {
                        Component item = comboBox.getItemAt(i);
                        if (item.getName().equals(componentName)) {
                            comboBox.setSelectedIndex(i);
                            break;
                        }
                    }
                }
            }
        }
        updateTotal();
    }

    private void customizeButton(JButton button) {
        button.setBackground(new Color(0, 120, 215));
        button.setForeground(Color.WHITE);
        button.setFocusPainted(false);
        button.setFont(new Font("Verdana", Font.BOLD, 14));
        button.setPreferredSize(new Dimension(120, 40));
    }

    private ImageIcon loadIcon(String name) {
        return new ImageIcon("icons/" + name + ".png");
    }

    private class ComponentRenderer extends DefaultListCellRenderer {
        private String category;

        public ComponentRenderer(String category) {
            this.category = category;
        }

        @Override
        public java.awt.Component getListCellRendererComponent(JList<?> list, Object value, int index, boolean isSelected, boolean cellHasFocus) {
            super.getListCellRendererComponent(list, value, index, isSelected, cellHasFocus);
            if (value instanceof Component) {
                Component comp = (Component) value;
                if (comp.getName().equals("Select")) {
                    setIcon(null);
                } else {
                    String iconName = category.replace("*", "").replace(" ", "_").toLowerCase();
                    setIcon(loadIcon(iconName));
                }
            }
            setFont(new Font("Tahoma", Font.PLAIN, 12));
            setBackground(isSelected ? new Color(0, 120, 215) : Color.WHITE);
            setForeground(Color.BLACK);
            return this;
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(PCBuilder::new);
    }
}