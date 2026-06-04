#include <iostream>
using namespace std;

int main() {
    int marks;
    cout << "Enter marks: ";
    cin >> marks;

    if (marks < 25) {
        cout << "Grade: F" << endl;
    } else if (marks < 45) {
        cout << "Grade: E" << endl;
    } else if (marks < 50) {
        cout << "Grade: D" << endl;
    } else if (marks < 60) {
        cout << "Grade: C" << endl;
    } else if (marks < 80) {
        cout << "Grade: B" << endl;
    } else {
        cout << "Grade: A" << endl;
    }

    return 0;
}