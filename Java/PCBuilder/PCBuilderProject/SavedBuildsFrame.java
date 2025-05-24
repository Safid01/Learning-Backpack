import javax.swing.*;
import java.awt.*;
import java.util.*;
import java.io.*;

public class SavedBuildsFrame extends BaseFrame {
    private PCBuilder pcBuilder;

    public SavedBuildsFrame(PCBuilder pcBuilder) {
        super("Saved Builds");
        this.pcBuilder = pcBuilder;
        setSize(500, 600);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        ArrayList<String> builds = readBuilds();
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));

        if (builds.isEmpty()) {
            mainPanel.add(new JLabel("No saved builds."));
        } else {
            for (String build : builds) {
                JPanel buildPanel = new JPanel(new BorderLayout());
                JTextArea buildText = new JTextArea(build);
                buildText.setEditable(false);
                buildPanel.add(buildText, BorderLayout.CENTER);
                JButton deleteButton = new JButton("Delete");
                deleteButton.addActionListener(e -> deleteBuild(build));
                buildPanel.add(deleteButton, BorderLayout.EAST);
                mainPanel.add(buildPanel);
            }
        }
        add(new JScrollPane(mainPanel));
        setVisible(true);
    }

    public SavedBuildsFrame() {
        this(null); // Call the parameterized constructor with null for backward compatibility
    }

    private ArrayList<String> readBuilds() {
        ArrayList<String> builds = new ArrayList<>();
        File file = new File("SavedBuilds.txt");
        if (!file.exists()) {
            return builds; // Return empty list if file doesn't exist
        }
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            StringBuilder build = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                if (line.equals("-----")) {
                    builds.add(build.toString());
                    build = new StringBuilder();
                } else {
                    build.append(line).append("\n");
                }
            }
            if (build.length() > 0) {
                builds.add(build.toString());
            }
        } catch (IOException e) {
            JOptionPane.showMessageDialog(this, "Error reading builds!", "Error", JOptionPane.ERROR_MESSAGE);
        }
        return builds;
    }

    private void deleteBuild(String buildToDelete) {
        int confirm = JOptionPane.showConfirmDialog(this, "Are you sure you want to delete this build?", "Confirm Delete", JOptionPane.YES_NO_OPTION);
        if (confirm == JOptionPane.YES_OPTION) {
            ArrayList<String> builds = readBuilds();
            builds.remove(buildToDelete);
            try (PrintWriter writer = new PrintWriter("SavedBuilds.txt")) {
                for (String build : builds) {
                    writer.print(build);
                    writer.println("-----");
                }
            } catch (FileNotFoundException e) {
                JOptionPane.showMessageDialog(this, "Error deleting build!", "Error", JOptionPane.ERROR_MESSAGE);
            }
            dispose();
            new SavedBuildsFrame(pcBuilder);
        }
    }
}