import javax.swing.SwingUtilities;
import javax.swing.UIManager;

public class Main {
   public Main() {
   }

   public static void main(String[] var0) {
      try {
         UIManager.setLookAndFeel("javax.swing.plaf.nimbus.NimbusLookAndFeel");
      } catch (Exception var4) {
         try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
         } catch (Exception var3) {
            var3.printStackTrace();
         }
      }

      SwingUtilities.invokeLater(PCBuilder::new);
   }
}