public class CoreComponent extends Component {
    public CoreComponent(String name, double price) {
        super(name, price);
    }

    @Override
    public String getCategory() {
        return "Core";
    }
}