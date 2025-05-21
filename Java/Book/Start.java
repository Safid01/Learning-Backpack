public class Start {
    public static void main(String[] args) {
        Book b1 = new Book(1001, "The Great Gatsby", "F. Scott Fitzgerald");
        Book b2 = new Book(1002, "1984", "George Orwell");
        Book b3 = new Book(1003, "To Kill a Mockingbird", "Harper Lee");
        Book b4 = new Book(1004, "Pride and Prejudice", "Jane Austen");
        
        Customer john = new Customer("John Doe", 701, 3);
        Customer sarah = new Customer("Sarah Smith", 702, 2);
        
        john.addBook(b1);
        john.addBook(b2);
        john.addBook(b3);
        john.addBook(b4); // Should fail

        sarah.addBook(b4);
        sarah.addBook(b2);
        
        john.returnBook(b2);
    
        john.searchBook(b3);
        
        john.display();
        sarah.display();
    }
}