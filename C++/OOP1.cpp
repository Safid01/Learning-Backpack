#include <iostream>
using namespace std;
class Student{
    public: //access modifier 
    string id;
    string name;  //attributes
    float cgpa;
 
    void show_details(){    //methods
        cout<<"Name: "<<name<<endl;
        cout<<"Id: "<<id<<endl;
        cout<<"cgpa: "<<cgpa<<endl;
    }
};
int main() {
    Student s1; //class object;
    s1.name = "Safid";
    s1.id = "24-58210-2";
    s1.cgpa = 3.77;
    s1.show_details();
    return 0;
}