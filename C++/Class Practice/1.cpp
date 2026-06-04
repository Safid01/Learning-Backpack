#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int roll_no;
};
int main() {
    Student s;
    s.name = "John";
    s.roll_no = 2;
    cout << "Name: " << s.name << ", Roll No: " << s.roll_no << endl;
    return 0;
}