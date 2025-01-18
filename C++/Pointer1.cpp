#include<iostream>
using namespace std;

int main () {
    int x = 10;
    int y = 10;
    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Address of y: " << &y << endl;
    
    int *ax = &x;
    cout << "Ax: " << ax << endl;
    cout << "Value of x: " << *ax << endl;
    *ax = 15;
    cout << "Value of x: " << x << endl;
    *(ax-1) = 30;
    cout << "Value of x: " << x << endl;
    cout << "Value of *(ax-1): " << y << endl;
    cout << "Address of *(ax-1): " << &y << endl;

return 0;
}