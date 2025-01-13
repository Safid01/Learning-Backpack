#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int matrix1[rows][cols], matrix2[rows][cols];
    cout << "Enter elements for first matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter elements for second matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix2[i][j];
        }
    }

    int sum[rows][cols], difference[rows][cols], product[rows][cols];
    cout << "Results:\n";
    cout << "Sum:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
            cout << sum[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Difference:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            difference[i][j] = matrix1[i][j] - matrix2[i][j];
            cout << difference[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Product:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            product[i][j] = matrix1[i][j] * matrix2[i][j];
            cout << product[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}