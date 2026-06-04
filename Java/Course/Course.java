public class Course {
    private int id;
    private String name;
    private Student[] students;

    public Course(int id, String name, int maxStudents) {
        this.id = id;
        this.name = name;
        this.students = new Student[maxStudents];
    }

    public void addStudent(Student student) {
        // Check if already enrolled
        for (int i = 0; i < students.length; i++) {
            if (students[i] == student) return;
        }
        
        // Find empty slot
        for (int i = 0; i < students.length; i++) {
            if (students[i] == null) {
                students[i] = student;
                return;
            }
        }
        System.out.println(name + " is full. Cannot add " + student.getName());
    }

    public void removeStudent(Student student) {
        for (int i = 0; i < students.length; i++) {
            if (students[i] == student) {
                students[i] = null;
                return;
            }
        }
    }

    public void displayStudents() {
        System.out.println("\nStudents in " + name + ":");
        for (Student s : students) {
            if (s != null) System.out.println("- " + s.getName());
        }
    }

    public int getId() { return id; }
    public String getName() { return name; }
}