public class Book {
    private int bookId;
    private String title;
    private String author;

    public Book() {
        System.out.println("Empty Book");
    }

    public Book(int bookId, String title, String author) {
        System.out.println("Parameterized Book");
        this.bookId = bookId;
        this.title = title;
        this.author = author;
    }

    public void setBookId(int bookId) {
        this.bookId = bookId;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public int getBookId() {
        return bookId;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public void display() {
        System.out.println("Book ID: " + bookId);
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
    }
}