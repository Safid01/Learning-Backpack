#include <iostream>
using namespace std;

class Student {
    public:
        string name;
        int roll_no;
        string phone;
        string address;
};
int main () {
    Student sam, john;
    sam.name = "Sam";
    sam.roll_no = 3123;
    sam.phone = "1234567890";
    sam.address = "123, Main Street, City";
    john.name = "John";
    john.roll_no = 2321;
    john.phone = "0987654321";
    john.address = "456, Main Street, City";

    cout << "Name: " << sam.name << ", Roll No: " << sam.roll_no << ", Phone: " << sam.phone << ", Address: " << sam.address << endl;
    cout << "Name: " << john.name << ", Roll No: " << john.roll_no << ", Phone: " << john.phone << ", Address: " << john.address << endl;
    return 0;
}