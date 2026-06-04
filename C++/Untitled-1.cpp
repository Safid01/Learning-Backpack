#include <iostream>
using namespace std;

int main() {
    int temps[7] = {29, 34, 31, 28, 33, 35, 30};

    cout << "Original Temperatures: ";
    for (int i = 0; i < 7; i++)
        cout << temps[i] << " ";
    cout << "\n";

    for (int i = 1; i < 7; i++) {
        int key = temps[i];
        int j = i - 1;

        while (j >= 0 && temps[j] > key) {
            temps[j + 1] = temps[j];
            j--;
        }
        temps[j + 1] = key;
    }

    cout << "Sorted Temperatures:   ";
    for (int i = 0; i < 7; i++)
        cout << temps[i] << " ";
    cout << "\n";

    int cityTemps[2][3] = {
        {29, 33, 30},  
        {27, 32, 31}
    };

    cout << "Noon Temperatures:\n";
    cout << "Dhaka: " << cityTemps[0][1] << "C\n";
    cout << "Chittagong: " << cityTemps[1][1] << "C\n";

    int target = 33;
    int left = 0, right = 6, found = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (temps[mid] == target) {
            found = mid;
            break;
        }
        else if (temps[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (found != -1)
        cout << target << "C found at index " << found << ".\n";
    else
        cout << target << "C not found.\n";

    return 0;
}