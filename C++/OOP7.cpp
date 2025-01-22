#include <iostream>
using namespace std;

class Student
{
   public:
        Student()
        {
            cout<<"Constructor Called"<<endl;
        }
        ~Student()
        {
            cout<<"Destructor Called"<<endl;
        }
};
int main()
{
    Student s1; //creating an object​​
    Student s2; //creating an object​​
    return 0;
}