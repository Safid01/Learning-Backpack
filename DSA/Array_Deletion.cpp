#include <iostream>
using namespace std;

int main() {
    int k, i, n=8, mimo[10]={1, 2, 3, 4, 5, 6, 7, 8};
    n--; // Decrease n to remove the last element
    n--; // Decrease n to remove the second last element
    for (i=0; i<n; i++) {
        mimo[i] = mimo[i+1]; // Shift elements to the left
    }
    k = 2; // Index to remove
    n--; // Decrease n to account for the removal
    for (i=k; i<n; i++) {
        mimo[i] = mimo[i+1]; // Shift elements to the right
    }
    for (i=0; i<n; i++) {
        cout << mimo[i] << " ";
    }
}