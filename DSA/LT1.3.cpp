#include <iostream>
using namespace std;

int main() {
    int arr[6] = {5, 6, 7, 5, 8, 9};
    int result[6];
    int input;
    int k = 0;
    int non_input_count = 0;

    cout << "Initial Array: ";
    for (int i=0; i<6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter the number to move to the end: ";
    cin >> input;

    for (int i=0; i<6; i++) {
        if (arr[i] != input) {
            result[k] = arr[i];
            k++;
        }
    }
    non_input_count = k;

    for (int i=0; i<6; i++) {
        if (arr[i] == input) {
            result[k] = arr[i];
            k++;
        }
    }

    cout << "Modified Array: ";
    for (int i=0; i<6; i++) {
        cout << result[i] << " ";
    }
    cout << endl;


    int min = result[0];
    int max = result[0];

    for (int i=0; i<non_input_count; i++) {
        if (result[i] < min)
            min = result[i];
        if (result[i] > max)
            max = result[i];
        }

    cout << "Maximum Value: " << max << endl;
    cout << "Minimum Value: " << min << endl;
    cout << "Difference: " << max - min << endl;

    return 0;
}
