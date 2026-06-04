#include <iostream>
using namespace std;

struct Student {
    int id;
    int credits;
    float cgpa;
};

int main() {
    const int NUM_STUDENTS = 10;
    // Sample data for 10 students
    Student students[NUM_STUDENTS] = {
        {1001, 60, 3.84},
        {1002, 45, 3.61},
        {1003, 55, 3.95},
        {1004, 30, 2.82},
        {1005, 70, 3.51},
        {1006, 80, 4.0},
        {1007, 40, 3.25},
        {1008, 51, 3.76},
        {1009, 49, 3.12},
        {1010, 52, 3.85}
    };

    cout << "\nStudents with CGPA > 3.75:" << endl;
    cout << "IDs: ";
    bool found = false;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (students[i].cgpa > 3.75) {
            cout << students[i].id << ", ";
            found = true;
        }
    }
    if (!found) {
        cout << "No students found with CGPA > 3.75" << endl;
    }

    cout << "\nStudents with more than 50 credits:" << endl;
    cout << "IDs: ";
    found = false;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (students[i].credits > 50) {
            cout << students[i].id << ", ";
            found = true;
        }
    }
    if (!found) {
        cout << "No students found with more than 50 credits" << endl;
    }
    return 0;
}