#include <iostream>
using namespace std;

int main() {
    int classesHeld, classesAttended;
    cout << "Enter number of classes held and attended: ";
    cin >> classesHeld >> classesAttended;

    float attendance = (float)classesAttended / classesHeld * 100;
    cout << "Attendance percentage: " << attendance << "%" << endl;

    if (attendance >= 75) {
        cout << "Allowed to sit in the exam." << endl;
    } else {
        cout << "Not allowed to sit in the exam." << endl;
    }

    return 0;
}
