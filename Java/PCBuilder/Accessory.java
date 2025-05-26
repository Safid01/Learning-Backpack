public class Accessory extends Component {
    public Accessory(String name, double price) {
        super(name, price);
    }

    @Override
    public String getCategory() {
        return "Accessory";
    }
}