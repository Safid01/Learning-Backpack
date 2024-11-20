#include <iostream>
using namespace std;
 

int main()
{
    int a = 5, b = 15, c = 2;

   if (a>b && a>c) {
      cout<<"A is the largest number"<<a<<endl; 
   }
   else if (b>a && b>c) {
      cout<<"B is the largest number"<<b<<endl; 
   }
   else {
      cout<<"A is the largest number"<<c<<endl; 
   }
    return 0;
}