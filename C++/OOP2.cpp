#include <iostream>
using namespace std;

class Student{
    private: //access modifier
    int id;
    string name;  //attributes
    float cgpa;
    public:
    //set_id , get_id// set_cgpa, get_cgpa// set_id, get_id
    void set_info(string n, int i, float cg){
        name = n;
        id = i;
        cgpa = cg;
    }
    void show_details(){    //methods
        cout<<"Name: "<<name<<endl;
        cout<<"Id: "<<id<<endl;
        cout<<"cgpa: "<<cgpa<<endl;
    }
};
int main() {
    Student s1; //class object;
    s1.set_info("Rahman",2763, 3.67);
    s1.show_details();
    return 0;
}