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
        void show()
        {
            cout<<"Function Called"<<endl;
        }
};
int main()
{
    Student s1;
    Student s2; 
    s1.show();
    return 0;
}