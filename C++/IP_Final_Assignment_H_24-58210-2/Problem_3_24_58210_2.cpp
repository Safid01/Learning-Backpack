#include <iostream>
using namespace std;

int main() {
    int a, b, sum;
    int *p1, *p2;

    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter first number: ";
    cin >> b;

    p1 = &a;
    p2 = &b;

    sum = *p1 + *p2;
    cout << "Sum is: " << sum << endl;
    return 0;
}