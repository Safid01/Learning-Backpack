public abstract class Component {
    private String name;
    private double price;

    public Component(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public String getName() {
        return name;
    }
    public double getPrice() {
        return price;
    } 
    public abstract String getCategory();

    @Override
    public String toString() { return name + " (" + price + "৳)"; }
}