public class Student {
    private int id;
    private String name;
    private Course[] courses;

    public Student(int id, String name, int maxCourses) {
        this.id = id;
        this.name = name;
        this.courses = new Course[maxCourses];
    }

    public void enroll(Course course) {
        // Check for existing enrollment
        for (int i = 0; i < courses.length; i++) {
            if (courses[i] == course) {
                System.out.println(name + " already enrolled in " + course.getName());
                return;
            }
        }
        
        // Find empty slot
        for (int i = 0; i < courses.length; i++) {
            if (courses[i] == null) {
                courses[i] = course;
                course.addStudent(this);
                System.out.println(name + " enrolled in " + course.getName());
                return;
            }
        }
        System.out.println(name + " cannot enroll: Max courses reached");
    }

    public void unenroll(Course course) {
        boolean removed = false;
        for (int i = 0; i < courses.length; i++) {
            if (courses[i] == course) {
                courses[i] = null;
                course.removeStudent(this);
                System.out.println(name + " unenrolled from " + course.getName());
                removed = true;
                break;
            }
        }
        if (!removed) System.out.println(name + " not enrolled in " + course.getName());
    }

    public void displayCourses() {
        System.out.println("\n" + name + "'s Courses:");
        for (Course c : courses) {
            if (c != null) System.out.println("- " + c.getName());
        }
    }

    public int getId() { return id; }
    public String getName() { return name; }
}