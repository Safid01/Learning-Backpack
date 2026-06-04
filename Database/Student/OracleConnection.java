import java.sql.*;

public class OracleConnection {

    private static final String HOST = "jdbc:oracle:thin:@db.freesql.com:1521/23ai_34ui2";
    private static final String USER = "SAFIDH20_SCHEMA_HXCEW";
    private static final String PASS = "b0P30NSW4VSQZ63YUQ63K7!LXK2GTR";

    public static void main(String[] args) {
        System.out.println("Connecting to Oracle Database...");

        try (Connection conn = DriverManager.getConnection(HOST, USER, PASS)) {
            System.out.println("Connected to Oracle Database successfully!");

            // Uncomment lines below one by one to test different operations
            tryCreateTable(conn);

            int generatedId = insertStudent(conn, "Jane Doe", "Electrical Engineering", 3.8);
            System.out.println("Inserted student with ID: " + generatedId);

            // readStudentById(conn, 21);          // ← change ID as needed
            readAllStudents(conn);

            // boolean updated = updateStudentById(conn, 21, "Jane Smith", "Computer Science", 3.9);
            // if (updated) {
            //     System.out.println("Student details updated successfully.");
            // } else {
            //     System.out.println("No student found with the given ID to update.");
            // }

            //boolean deleted = deleteStudentById(conn, 21);   // ← change ID as needed
            //if (deleted) {
                //System.out.println("Student deleted successfully.");
            //} else {
                //System.out.println("No student found with the given ID to delete.");
            //}

        } catch (SQLException e) {
            System.out.println("Connection failed!");
            e.printStackTrace();
        }
    }

    // Method to create a database table (safe to call multiple times)
    private static void tryCreateTable(Connection conn) {
        String ddl = "CREATE TABLE students (" +
                     "id NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY, " +
                     "name VARCHAR2(100) NOT NULL, " +
                     "dept VARCHAR2(100) NOT NULL, " +
                     "cgpa NUMBER(3,2)" +
                     ")";

        try (Statement st = conn.createStatement()) {
            st.executeUpdate(ddl);
            System.out.println("Table 'students' created successfully.");
        } catch (SQLException e) {
            System.out.println("Failed to create table 'students' (probably already exists).");
            // e.printStackTrace();   // uncomment only if you want to see full error
        }
    }

    // Insert a row in student table and return generated ID
    private static int insertStudent(Connection conn, String name, String dept, Double cgpa) throws SQLException {
        String sql = "INSERT INTO students (name, dept, cgpa) VALUES (?, ?, ?)";

        try (PreparedStatement ps = conn.prepareStatement(sql, new String[] {"id"})) {
            ps.setString(1, name);
            ps.setString(2, dept);
            if (cgpa != null) {
                ps.setDouble(3, cgpa);
            } else {
                ps.setNull(3, Types.NUMERIC);
            }

            int rows = ps.executeUpdate();
            if (rows == 0) {
                throw new SQLException("Inserting student failed, no rows affected.");
            }

            // Get the generated ID
            try (ResultSet keys = ps.getGeneratedKeys()) {
                if (keys.next()) {
                    return keys.getInt(1);
                } else {
                    throw new SQLException("Inserting student failed, no ID obtained.");
                }
            }
        }
    }

    // Read student details by ID
    private static void readStudentById(Connection conn, int id) {
        String sql = "SELECT id, name, dept, cgpa FROM students WHERE id = ?";

        try (PreparedStatement ps = conn.prepareStatement(sql)) {
            ps.setInt(1, id);

            try (ResultSet rs = ps.executeQuery()) {
                if (rs.next()) {
                    System.out.println("Student ID: " + rs.getInt("id"));
                    System.out.println("Name: " + rs.getString("name"));
                    System.out.println("Department: " + rs.getString("dept"));
                    System.out.println("CGPA: " + rs.getDouble("cgpa"));
                } else {
                    System.out.println("No student found with ID: " + id);
                }
            }
        } catch (SQLException e) {
            System.out.println("Failed to read student details.");
            e.printStackTrace();
        }
    }

    // Read all students details
    private static void readAllStudents(Connection conn) throws SQLException {
        String sql = "SELECT id, name, dept, cgpa FROM students ORDER BY id";

        try (PreparedStatement ps = conn.prepareStatement(sql);
             ResultSet rs = ps.executeQuery()) {

            System.out.println("All Students:");
            boolean any = false;

            while (rs.next()) {
                any = true;
                int id = rs.getInt("id");
                String name = rs.getString("name");
                String dept = rs.getString("dept");
                double cg = rs.getDouble("cgpa");
                Double cgpa = rs.wasNull() ? null : cg;

                System.out.println("  " + id + " | " + name + " | " + dept + " | " + cgpa);
            }

            if (!any) {
                System.out.println("  (none)");
            }

        } catch (SQLException e) {
            System.out.println("Failed to read all students.");
            e.printStackTrace();
        }
    }

    // Update student details by ID, returns true if successful
    private static boolean updateStudentById(Connection conn, int id, String name, String dept, Double cgpa) {
        String sql = "UPDATE students SET name = ?, dept = ?, cgpa = ? WHERE id = ?";

        try (PreparedStatement ps = conn.prepareStatement(sql)) {
            ps.setString(1, name);
            ps.setString(2, dept);
            if (cgpa != null) {
                ps.setDouble(3, cgpa);
            } else {
                ps.setNull(3, Types.NUMERIC);
            }
            ps.setInt(4, id);

            int rows = ps.executeUpdate();
            return rows > 0;
        } catch (SQLException e) {
            System.out.println("Failed to update student details.");
            e.printStackTrace();
            return false;
        }
    }

    // Delete student by ID
    private static boolean deleteStudentById(Connection conn, int id) {
        String sql = "DELETE FROM students WHERE id = ?";

        try (PreparedStatement ps = conn.prepareStatement(sql)) {
            ps.setInt(1, id);

            int rows = ps.executeUpdate();
            return rows > 0;
        } catch (SQLException e) {
            System.out.println("Failed to delete student.");
            e.printStackTrace();
            return false;
        }
    }
}