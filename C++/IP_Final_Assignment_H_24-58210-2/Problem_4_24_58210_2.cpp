#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    char arr[100];
    cout << "Enter the characters: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Reversed order: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
    return 0;
}