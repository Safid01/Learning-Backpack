#include <iostream>
using namespace std;

int main() {
    int x = 2, y = 5, z = 0;

    if (x == 2) {
        cout << "a. x == 2 is true" << endl;
    } else {
        cout << "a. x == 2 is false" << endl;
    }

    if (x != 5) {
        cout << "b. x != 5 is true" << endl;
    } else {
        cout << "b. x != 5 is false" << endl;
    }

    if (x != 5 && y >= 5) {
        cout << "c. x != 5 && y >= 5 is true" << endl;
    } else {
        cout << "c. x != 5 && y >= 5 is false" << endl;
    }

    if (z != 0 || x == 2) {
        cout << "d. z != 0 || x == 2 is true" << endl;
    } else {
        cout << "d. z != 0 || x == 2 is false" << endl;
    }

    if (!(y < 10)) {
        cout << "e. !(y < 10) is false" << endl;
    } else {
        cout << "e. !(y < 10) is true" << endl;
    }

    return 0;
}