#include<iostream>
using namespace std;
struct Student
{
    string stdId;
    string name;
    float cgpa;
    int credit;
    int age;

    //member function
    void intput_st()
    {
      cout<<"ID: ";
      cin>>stdId;
      cout<<"Name: ";
      cin>>name;
      cout<<"Age: ";
      cin>>age;
      cout<<"CGPA: ";
      cin>>cgpa;
      cout<<"Credits completed: ";
      cin>>credit;
    }

    void print_st()
    {
        cout<<name<<"'s record:"<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"ID: "<<stdId<<endl;
        cout<<"CGPA: "<<cgpa<<endl;
        cout<<"Credit completed: "<<credit<<endl<<endl;
    }

    int checkCredit()
    {
        if(credit>30)
           return 1;
        else
            return 0;
    }
}; //end of structure
int main()
{
    int n;
    cout<<"Enter the number of student: ";
    cin>>n;
    Student s[n];
    cout<<"Enter student information:"<<endl;
    for(int i=0; i<n; i++)
    {
        s[i].intput_st();
    }
     cout<<"\nDisplay student info:"<<endl;
     for(int i=0; i<n; i++)
     {
         s[i].print_st();
     }
      // print student name and id and credit with credit > 30 using member funtio
       cout<<"student completed more than 30 credits"<<endl;
       for(int i=0; i<n; i++)
       {
           if(s[i].checkCredit()==1)
           {
               cout<<s[i].name<<" ("<<s[i].stdId<<") "<<endl;
           }
       }
    return 0;
} // end of main