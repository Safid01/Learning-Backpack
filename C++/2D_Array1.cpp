#include <iostream>
using namespace std;

int main () {
    int arr1 [3][3] = {{6, 4, 2}, {3, 2, 1}, {5, 1, 7}};

    cout << "1st Array" << endl;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            cout << arr1[row][column] << "\t";
        }
        cout << endl;
    }
    return 0;
}