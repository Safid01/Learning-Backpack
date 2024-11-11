#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num < 0) {
        cout << "Absolute value: " << -num << endl;
    } else {
        cout << "Absolute value: " << num << endl;
    }

    return 0;
}
