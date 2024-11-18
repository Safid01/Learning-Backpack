#include <iostream>
using namespace std;

int main() {
    float mark, totalGPA = 0, gpa;
    
    for (int i = 1; i <= 5; i++) {
        cout << "Enter marks for course " << i << ": ";
        cin >> mark;

        if (mark >= 90 && mark <= 100) {
            gpa = 4.00;
        } else if (mark >= 85 && mark < 90) {
            gpa = 3.75;
        } else if (mark >= 80 && mark < 85) {
            gpa = 3.50;
        } else if (mark >= 75 && mark < 80) {
            gpa = 3.25;
        } else if (mark >= 70 && mark < 75) {
            gpa = 3.00;
        } else if (mark >= 65 && mark < 70) {
            gpa = 2.75;
        } else if (mark >= 60 && mark < 65) {
            gpa = 2.50;
        } else if (mark >= 50 && mark < 60) {
            gpa = 2.25;
        } else if (mark >= 0 && mark < 50) {
            gpa = 0.00;
        } else {
            cout << "Invalid mark entered. Please enter marks between 0 and 100.\n";
            return 1;
        }

        totalGPA += gpa;
    }

    float averageGPA = totalGPA / 5;
    cout << "\nThe average GPA of the 5 courses is: " << averageGPA << endl;

    return 0;
}
