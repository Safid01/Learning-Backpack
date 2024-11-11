#include <iostream>
using namespace std;

int main() {
    int age1, age2, age3;
    cout << "Enter ages of three people: ";
    cin >> age1 >> age2 >> age3;

    if (age1 >= age2 && age1 >= age3) {
        cout << "Oldest age: " << age1 << endl;
    } else if (age2 >= age1 && age2 >= age3) {
        cout << "Oldest age: " << age2 << endl;
    } else {
        cout << "Oldest age: " << age3 << endl;
    }

    if (age1 <= age2 && age1 <= age3) {
        cout << "Youngest age: " << age1 << endl;
    } else if (age2 <= age1 && age2 <= age3) {
        cout << "Youngest age: " << age2 << endl;
    } else {
        cout << "Youngest age: " << age3 << endl;
    }

    return 0;
}
