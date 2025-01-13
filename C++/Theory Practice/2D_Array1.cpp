#include <iostream>
using namespace std;

int main() {
    string countries[5];
    cout << "Enter names of 5 countries:\n";
    for (int i = 0; i < 5; i++) {
        cin >> countries[i];
    }
    cout << "The countries are:\n";
    for (int i = 0; i < 5; i++) {
        cout << countries[i] << endl;
    }
    return 0;
}