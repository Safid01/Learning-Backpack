#include <iostream>
using namespace std;

class Student {// The class​

  private:// Access specifier​
    string name; // Attribute​
    int id; // Attribute​
    string bg; // Attribute​
public:// Access specifier​
    // Constructor with parameters​
    Student(string x, int y, string z) {
      name = x;
      id = y;
      bg = z;
    }
    void show(){ //methods
        cout<<"Name: "<<name<<endl;
        cout<<"Id: "<<id<<endl;
        cout<<"cgpa: "<<bg<<endl;
    }
};
int main() {
  // Create Student objects and call the constructor with different values​
  Student obj1("Padma", 45729, "A+");
  Student obj2("Shetu", 45728, "B+");
  // Print values​
  obj1.show();
  cout<<"\n";
  obj2.show();
  return 0;
}