#include <iostream>
using namespace std;

void findLargestAndSmallest(int arr[], int n, int &largest, int &smallest) {
    largest = arr[0];
    smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
}
int main() {
    int n, largest, smallest;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    findLargestAndSmallest(arr, n, largest, smallest);
    cout << "Largest: " << largest << ", Smallest: " << smallest << endl;
    return 0;
}