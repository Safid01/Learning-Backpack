#include <iostream>
using namespace std;

int main () {
    int arr1 [3][3] = {{2, 1, 3}, {9, 2, 11}, {4, 4, 6}};
    int arr2 [3][3] = {{6, 2, 4}, {3, 2, 1}, {5, 1, 7}};
    
    cout << "1nd Array" << endl;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            cout << arr1[row][column] << "\t";
        }
        cout << endl;
    }
    cout << "2nd Array" << endl;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            cout << arr2[row][column] << "\t";
        }
        cout << endl;
    }

    int arr3 [3][3];
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            arr3 [row][column] = arr1[row][column] + arr2[row][column];
        }
    }
    cout << "Sum of the 2 Arrays" << endl;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            cout << arr3[row][column] << "\t";
        }
        cout << endl;
    }

    int arr4 [3][3];
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            arr4 [row][column] = arr1[row][column] - arr2[row][column];
        }
    }
    cout << "Substraction of the 2 Arrays" << endl;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            cout << arr4[row][column] << "\t";
        }
        cout << endl;
    }

    int totalSum1 = 0, totalSum2 = 0;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            totalSum1 += arr1[row][column];
            totalSum2 += arr2[row][column];
    }
}
cout << "Total sum of elements in the 1st Array: " << totalSum1 << endl;
cout << "Total sum of elements in the 2nd Array: " << totalSum2 << endl;

    int arr5[3][3] = {0};
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            for (int k = 0; k < 3; k++) {
                arr5[row][column] += arr1[row][k] * arr2[k][column];
            }
        }
    }
    cout << "Multiplication of the 2 Arrays" << endl;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            cout << arr5[row][column] << "\t";
        }
        cout << endl;
    }
    
    int leftsum = 0;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (row == column) {
                leftsum += arr1 [row] [column];
            }
        }
    }
    cout << "Left diagonal sum of Array 1 :" << leftsum << endl;
    
    int rightsum = 0;
    int column = 3-1;
    int row = 0;
    while (column >= 0 || row < 3) {
        rightsum += arr1 [row] [column];
        column--;
        row++;
    }
    cout << "Right diagonal sum of Array 1 :" << rightsum << endl;
    return 0;
}