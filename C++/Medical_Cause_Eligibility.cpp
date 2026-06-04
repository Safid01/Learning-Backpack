#include <iostream>
using namespace std;

int main() {
    int classesHeld, classesAttended;
    char medicalCause;
    cout << "Enter number of classes held and attended: ";
    cin >> classesHeld >> classesAttended;

    cout << "Do you have a medical cause? (Y/N): ";
    cin >> medicalCause;

    float attendance = (float)classesAttended / classesHeld * 100;
    cout << "Attendance percentage: " << attendance << "%" << endl;

    if (attendance >= 75 || medicalCause == 'Y' || medicalCause == 'y') {
        cout << "Allowed to sit in the exam." << endl;
    } else {
        cout << "Not allowed to sit in the exam." << endl;
    }

    return 0;
}