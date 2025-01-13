#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num % 2 == 0) {
        cout << num << " is an even integer." << endl;
    } else {
        cout << num << " is an odd integer." << endl;
    }

    return 0;
}