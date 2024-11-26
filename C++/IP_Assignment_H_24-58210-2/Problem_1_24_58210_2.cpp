#include <iostream>
using namespace std;

int main() {
    int items;
    cout << "Enter the number of items in the cart: ";
    cin >> items;

    double totalCost = 0;
    for (int i = 0; i < items; i++) {
        double price;
        int quantity;
        cout << "Enter price of the item " << i + 1 << ": ";
        cin >> price;
        cout << "Enter quantity of the item " << i + 1 << ": ";
        cin >> quantity;
        totalCost += price * quantity;
    }
    cout << "Total cost: " << totalCost << " BDT" << endl;
    return 0;
}