#include <iostream>
using namespace std;

int main() {
    int n = 8;
    int arr[8] = {15, 5, 10, 3, 2, 1, 7, 9};
    
    cout << "Array elements in reverse order:" << endl;
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << "  ";
    }
    cout << endl;
    
    return 0;
}