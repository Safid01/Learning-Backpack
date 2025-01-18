#include <iostream>
using namespace std;
struct student{
    int id;
    string name;
    float cgpa;
 
    void show(){
        cout<<"Name: "<<name<<endl;
        cout<<"id: "<<id<<endl;
        cout<<"cgpa: "<<cgpa<<endl;
    }
};
 
int main() {
    student s1,s2,s3;
    s1.id = 343;
    s1.name = "Yean sir";
    s1.cgpa = 3.90;
    s1.show();
 
    cout<<"Enter student name: ";
    cin>>s2.name;
    cout<<"Enter student id: ";
    cin>>s2.id;
    cout<<"Enter student cgpa: ";
    cin>>s2.cgpa;
    s2.show();
    return 0;
}