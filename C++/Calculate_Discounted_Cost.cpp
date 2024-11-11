#include <iostream>
using namespace std;

int main() {
    int quantity;
    cout << "Enter quantity: ";
    cin >> quantity;

    int cost = quantity * 100;
    if (cost > 1000) {
        cost *= 0.9; // Apply 10% discount
    }

    cout << "Total cost: " << cost << endl;
    return 0;
}