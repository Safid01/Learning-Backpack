public class Start {
    public static void main(String[] args) {
        Student s1 = new Student(1, "Alice", 2);
        Student s2 = new Student(2, "Bob", 3);
        
        Course c1 = new Course(101, "Math", 2);
        Course c2 = new Course(102, "Physics", 2);
        Course c3 = new Course(103, "History", 1);

        // Enrollments
        s1.enroll(c1);
        s1.enroll(c2);
        s1.enroll(c3); // Should fail (max 2 courses)
        
        s2.enroll(c1);
        s2.enroll(c2);
        s2.enroll(c3);

        // Displays
        c1.displayStudents();
        c3.displayStudents();
        
        // Unenroll
        s1.unenroll(c1);
        c1.displayStudents();
    }
}