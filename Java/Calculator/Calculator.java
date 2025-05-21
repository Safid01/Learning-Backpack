import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calculator implements ActionListener {
    private JFrame calc;
    private JLabel num1Lbl, num2Lbl, resLbl;
    private JTextField num1Txt, num2Txt, resTxt;
    private JButton plusBtn, minusBtn, multiplyBtn, divideBtn, clearBtn;

    public Calculator() {
        calc = new JFrame("Calculator");
        calc.setSize(600, 400);

        num1Lbl = new JLabel("NUMBER1 ");
        num2Lbl = new JLabel("NUMBER2 ");
        resLbl = new JLabel("RESULT ");
        num1Txt = new JTextField();
        num2Txt = new JTextField();
        resTxt = new JTextField();
        plusBtn = new JButton("Add (+)");
        minusBtn = new JButton("Minus (-)");
        multiplyBtn = new JButton("Multiply (×)");
        divideBtn = new JButton("Divide (÷)");
        clearBtn = new JButton("Clear");

        num1Lbl.setBounds(162, 40, 80, 30);
        num2Lbl.setBounds(369, 40, 80, 30);
        resLbl.setBounds(270, 170, 80, 30);
        num1Txt.setBounds(150, 70, 80, 30);
        num2Txt.setBounds(358, 70, 80, 30);
        resTxt.setBounds(252, 210, 80, 30);
        plusBtn.setBounds(38, 120, 100, 30);
        minusBtn.setBounds(143, 120, 100, 30);
        multiplyBtn.setBounds(248, 120, 100, 30);
        divideBtn.setBounds(354, 120, 100, 30);
        clearBtn.setBounds(459, 120, 100, 30);

        calc.add(num1Lbl);
        calc.add(num2Lbl);
        calc.add(resLbl);
        calc.add(num1Txt);
        calc.add(num2Txt);
        calc.add(resTxt);
        calc.add(plusBtn);
        calc.add(minusBtn);
        calc.add(multiplyBtn);
        calc.add(divideBtn);
        calc.add(clearBtn);

        plusBtn.addActionListener(this);
        minusBtn.addActionListener(this);
        multiplyBtn.addActionListener(this);
        divideBtn.addActionListener(this);
        clearBtn.addActionListener(this);

        resTxt.setEditable(false);
        calc.setLayout(null);
        calc.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        calc.setVisible(true);
        calc.setResizable(false);
    }

    public void actionPerformed(ActionEvent e) {
        if (num1Txt.getText().isEmpty() || num2Txt.getText().isEmpty()) {
            JOptionPane.showMessageDialog(calc, "Please fill both fields!", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        if (e.getSource() == clearBtn) {
            num1Txt.setText("");
            num2Txt.setText("");
            resTxt.setText("");
        } else {
            try {
                double num1 = Double.parseDouble(num1Txt.getText());
                double num2 = Double.parseDouble(num2Txt.getText());
                double result = 0;

                if (e.getSource() == plusBtn) {
                    result = num1 + num2;
                } else if (e.getSource() == minusBtn) {
                    result = num1 - num2;
                } else if (e.getSource() == multiplyBtn) {
                    result = num1 * num2;
                } else if (e.getSource() == divideBtn) {
                    if (num2 == 0) {
                        JOptionPane.showMessageDialog(calc, "Cannot divide by zero!", "Information", JOptionPane.INFORMATION_MESSAGE);
                        return;
                    }
                    result = num1 / num2;
                }

                resTxt.setText(String.format("%.2f", result));
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(calc, "Invalid input! Please enter numbers.", "Error", JOptionPane.WARNING_MESSAGE);
            }
        }
    }
}