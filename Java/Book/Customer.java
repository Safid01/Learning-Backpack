public class Customer {
    private String name;
    private int customerId;
    private Book[] borrowedBooks;

    public Customer() {
        System.out.println("Empty Customer");
    }

    public Customer(String name, int customerId, int maxBooks) {
        System.out.println("Parameterized Customer");
        this.name = name;
        this.customerId = customerId;
        borrowedBooks = new Book[maxBooks];
    }

    public void addBook(Book book) {
        int check = 0;
        for (int i = 0; i < borrowedBooks.length; i++) {
            if (borrowedBooks[i] == null) {
                borrowedBooks[i] = book;
                check = 1;
                break;
            }
        }
        System.out.println(check == 1 ? "Book added." : "Cannot add book. Limit reached.");
    }

    public void returnBook(Book book) {
        int check = 0;
        for (int i = 0; i < borrowedBooks.length; i++) {
            if (borrowedBooks[i] == book) {
                borrowedBooks[i] = null;
                check = 1;
                break;
            }
        }
        System.out.println(check == 1 ? "Book returned." : "Book not found.");
    }

    public void searchBook(Book book) {
        int check = 0;
        for (Book b : borrowedBooks) {
            if (b == book) {
                check = 1;
                break;
            }
        }
        System.out.println(check == 1 ? "Book found in borrowed list." : "Book not found.");
    }

    public void display() {
        System.out.println("Customer Name: " + name);
        System.out.println("Customer ID: " + customerId);
        System.out.println("Borrowed Books:");
        for (int i = 0; i < borrowedBooks.length; i++) {
            if (borrowedBooks[i] != null) {
                borrowedBooks[i].display();
            } else {
                System.out.println("Slot " + (i+1) + ": Available");
            }
        }
    }
}