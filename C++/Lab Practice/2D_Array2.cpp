#include <iostream>
using namespace std;

int main () {
    int arr1 [3][3];

    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            cout << "Enter the value for row " << row << " and column " << column << ": ";
            cin >> arr1[row][column];
        }
        cout << endl;
    }

    cout << "2nd Array" << endl;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            cout << arr1[row][column] << "\t";
        }
        cout << endl;
    }
    return 0;
}