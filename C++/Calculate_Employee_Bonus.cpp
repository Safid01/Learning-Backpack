#include <iostream>
using namespace std;

int main() {
    int salary, years;
    cout << "Enter salary and years of service: ";
    cin >> salary >> years;

    if (years > 5) {
        float bonus = salary * 0.05;
        cout << "Bonus: " << bonus << endl;
    } else {
        cout << "No bonus" << endl;
    }

    return 0;
}
