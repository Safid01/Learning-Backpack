import javax.swing.*;
import java.awt.*;

public class ImageFrame {
    private JFrame f;

    public ImageFrame() {
        ImageIcon image = new ImageIcon("me.jpg");
        JLabel label = new JLabel(image);
        label.setBounds(10, 10, 300, 300);

        f = new JFrame("Image Frame");
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setResizable(false);
        f.setSize(600, 600);
        f.setLayout(null);
        f.getContentPane().setBackground(Color.gray);
        f.add(label);
        f.setVisible(true);
    }
}