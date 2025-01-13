#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    float array[rows][cols], sum = 0;
    cout << "Enter elements for the array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> array[i][j];
            sum += array[i][j];
        }
    }

    float average = sum / (rows * cols);
    cout << "Rows: " << rows << ", Columns: " << cols << endl;
    cout << "Sum: " << sum << ", Average: " << average << endl;

    return 0;
}