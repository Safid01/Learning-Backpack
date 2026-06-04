#include <iostream>
using namespace std;

struct student {
    string name;
    double gpa;
    bool enrolled;
};

int main () {
    student stu1;
    stu1.name = "Safid";
    stu1.gpa = 3.77;
    stu1.enrolled = true;

    cout << stu1.name << endl;
    cout << stu1.gpa << endl;
    if (stu1.enrolled == true) {
        cout << "Enrolled";
    }
   return 0;
}