#include <iostream>
using namespace std;

int main() {
    float array[2][4];
    cout << "Enter elements for a 2x4 array:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> array[i][j];
        }
    }

    float search;
    cout << "Enter number to search: ";
    cin >> search;

    bool found;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (array[i][j] == search) {
                found = true;
                break;
            }
        }
    }

    if (found == true) {
        cout << "Number is present in the array.\n";
    } else {
        cout << "Number is not present in the array.\n";
    }

    return 0;
}