#include <iostream>
using namespace std;

int main() {
    int years[5];
    cout << "Enter 5 years: ";
    for (int i = 0; i < 5; i++) {
        cin >> years[i];
    }
    cout << "Leap years: ";
    for (int i=0; i<5; i++) {
        int year = years[i];
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << ", ";
        }
    }
    return 0;
}
