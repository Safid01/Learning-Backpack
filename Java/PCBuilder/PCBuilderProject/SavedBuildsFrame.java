import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class SavedBuildsFrame extends BaseFrame {
    private PCBuilder pcBuilder;

    public SavedBuildsFrame(PCBuilder pcBuilder) {
        super("Saved Builds");
        this.pcBuilder = pcBuilder;
        setSize(500, 600);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        ArrayList<String> builds = BuildIO.loadBuilds();
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

                JButton loadButton = new JButton("Load");
                loadButton.addActionListener(e -> {
                    if (pcBuilder != null) {
                        pcBuilder.loadBuild(build);
                        dispose();
                    }
                });
                buildPanel.add(loadButton, BorderLayout.WEST);

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
        this(null); // Default constructor calls parameterized constructor with null
    }

    private void deleteBuild(String buildToDelete) {
        int confirm = JOptionPane.showConfirmDialog(this, "Are you sure you want to delete this build?", "Confirm Delete", JOptionPane.YES_NO_OPTION);
        if (confirm == JOptionPane.YES_OPTION) {
            BuildIO.deleteBuild(buildToDelete);
            dispose();
            new SavedBuildsFrame(pcBuilder);
        }
    }
}