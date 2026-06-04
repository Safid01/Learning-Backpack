#include <iostream>
using namespace std;

int main() {
    int notes[10];
    int n = 10;

    cout << "Insert 10 banknote values:";
    for (int i = 0; i < n; i++) {
        cin >> notes[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (notes[max] < notes[j]) {
                max = j;
            }
        }
        int temp = notes[i];
        notes[i] = notes[max];
        notes[max] = temp;
    }

    cout << "After Sort: ";
    for (int i = 0; i < n; i++) {
        cout << notes[i] << ", ";
    }
    cout << endl;

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += notes[i];
    }

    cout << "Total Amount: " << total << " taka" << endl;

    int amount;
    cout << "Provide an amount less than total: ";
    cin >> amount;

    if (amount >= total || amount < 0) {
        cout << "Invalid amount! It should be less than " << total << " and non-negative." << endl;
        return 0;
    }

    int used_notes[10], count = 0;
    for (int i = 0; i < n; i++) {
        if (notes[i] <= amount) {
            amount -= notes[i];
            used_notes[count++] = notes[i];
        }
    }

    if (amount != 0) {
        cout << "Cannot make the exact amount with given notes!" << endl;
    } else {
        cout << "Total notes needed: " << count << ", Which are: ";
        for (int i = 0; i < count; i++) {
            cout << used_notes[i] << ", ";
        }
        cout << endl;
    }
    return 0;
}