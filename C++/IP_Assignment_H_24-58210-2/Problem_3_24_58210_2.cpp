#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;

    // Input 4 numbers
    cout << "Enter four integers: ";
    cin >> a >> b >> c >> d;

    int smallest, secondSmallest;

    // Find the smallest number
    if (a <= b && a <= c && a <= d) {
        smallest = a;
        if (b <= c && b <= d) {
            secondSmallest = b;
        } else if (c <= b && c <= d) {
            secondSmallest = c;
        } else {
            secondSmallest = d;
        }
    } else if (b <= a && b <= c && b <= d) {
        smallest = b;
        if (a <= c && a <= d) {
            secondSmallest = a;
        } else if (c <= a && c <= d) {
            secondSmallest = c;
        } else {
            secondSmallest = d;
        }
    } else if (c <= a && c <= b && c <= d) {
        smallest = c;
        if (a <= b && a <= d) {
            secondSmallest = a;
        } else if (b <= a && b <= d) {
            secondSmallest = b;
        } else {
            secondSmallest = d;
        }
    } else {
        smallest = d;
        if (a <= b && a <= c) {
            secondSmallest = a;
        } else if (b <= a && b <= c) {
            secondSmallest = b;
        } else {
            secondSmallest = c;
        }
    }

    // Output the second smallest number
    cout << "The second smallest number is: " << secondSmallest << endl;

    return 0;
}