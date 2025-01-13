#include <iostream>
using namespace std;

void hellomsg(){
     cout << "Good Morning" << endl;
}
void hellomsg2 (string st) {
     cout << "Good Morning" << st << endl;
}
string hellomsg3 (string st) {
     string text = "Good Morning IP" +st;
     return text;
}
int add (int op1, int op2) {
    int sum = op1 + op2;
    return sum;
}
void swapV(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside SwapV: ";
    cout << "a = " << a << "\t b = " << b << endl;
}
//Pass by value
void swapR(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "Inside SwapV: ";
    cout << "a = " << *a << "\t b = " << *b << endl;
}
int factorial (int n) {
    int fact = 1;
    for (int i=1; i<=n; i++) {
        fact = fact*i;
    }
    return fact;
}
int main() {
    hellomsg();
    hellomsg2 (" everyone.");
    string t = hellomsg3 (" sec-H students");
    cout << t << endl;
    cout << "Addition: " << add(5, 8) << endl;
    int aa = 10, bb = 20;
    swapV (aa, bb);
    cout << "Inside Main: ";
    cout << "a = " << aa << "\t b = " << bb << endl;
    cout << "Pass by value," << endl;
    swapR (&aa, &bb);
    cout << "Inside Main: ";
    cout << "a = " << aa << "\t b = " << bb << endl;
    cout << "Sum of two fact: " << add(factorial(5), factorial(8)) << endl;

    int fact5 = factorial(5);
    int fact8 = factorial(8);
    int fact_sum = add (fact5, fact8);
    cout << "Sum of two fact: " << fact_sum << endl;
    return 0;
}
