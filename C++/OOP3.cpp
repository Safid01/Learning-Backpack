#include <iostream>
using namespace std;

class Student {
  private:
    float cgpa;
    int salary;
  public:
    void setCgpa(float c) {
      cgpa = c; }
    void setSalary(float s) {
      salary = s; }
    float getCgpa() {
      return cgpa; }
    float getSalary() {
      return salary; }
};
int main() {
  Student obj1;
  Student obj2;
  obj1.setCgpa(3.55);
  obj2.setCgpa(3.25);
  obj1.setSalary(30000);
  obj2.setSalary(50000);
  cout << obj1.getCgpa()<<endl;
  cout << obj2.getCgpa()<<endl;
  cout << obj1.getSalary()<<endl;
  cout << obj2.getSalary();
  return 0;
}