#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    if (num1 == num2) {
        cout << "Number1 and Number2 are equal." << endl;
    } else {
        cout << "Number1 and Number2 are not equal." << endl;
    }

    return 0;
}