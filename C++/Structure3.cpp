#include <iostream>
using namespace std;
struct student{
    int id;
    string name;
    float cgpa;
 
    void show_info (){
        cout << "Name: " << name << endl;
        cout << "id: " << id << endl;
        cout << "cgpa: " << cgpa << endl;
    }
};
int main () {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    student students[n];
    for (int i = 0; i < n; i++){
        cout << "Enter name of the student " << i+1 << " : ";
        cin >> students[i].name;
        cout << "Enter Id of the student "<< i+1 <<" : ";
        cin >> students[i].id;
        cout << "Enter cgpa of the student "<< i+1 <<" : ";
        cin >> students[i].cgpa;
    }
 
    for (int i = 0; i < n; i++){
        cout << "Showing info of the student "<< i+1 << endl;
        students[i].show_info();
        cout << endl;
    }
 
    for (int i = 0; i < 3; i++){
        if(students[i].cgpa >= 3.8){
            cout << students[i].name <<" (Id: " << students[i].id << ") is eligible for scholarship" << endl;
        }
    }
    return 0;
 
}