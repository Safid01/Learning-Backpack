public class Peripheral extends Component {
    public Peripheral(String name, double price) {
        super(name, price);
    }

    @Override
    public String getCategory() {
        return "Peripheral";
    }
}
