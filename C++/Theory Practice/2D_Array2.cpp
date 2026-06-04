#include <iostream>
using namespace std;

int main() {
    int matrix[4][4];
    int leftDiagonalSum = 0, rightDiagonalSum = 0;

    cout << "Enter elements for a 4x4 matrix:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> matrix[i][j];
            if (i == j) leftDiagonalSum += matrix[i][j];
            if (i + j == 3) rightDiagonalSum += matrix[i][j];
        }
    }
    cout << "Left diagonal sum: " << leftDiagonalSum << endl;
    cout << "Right diagonal sum: " << rightDiagonalSum << endl;
    if (leftDiagonalSum % 2 == 0) {
        cout << "Left diagonal sum is EVEN."  << endl;
    }
    else {
        cout << "Left diagonal sum is ODD."  << endl;
    }
    if (rightDiagonalSum % 2 == 0) {
        cout << "Right diagonal sum is EVEN."  << endl;
    }
    else {
        cout << "Right diagonal sum is ODD."  << endl;
    }
    return 0;
}