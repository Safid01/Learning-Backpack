#include <iostream>
using namespace std;

class Average {
public:
    static void calculate(int a, int b, int c) {
        float avg = (a + b + c) / 3.0;
        cout << "Average: " << avg << endl;
    }
};
int main() {
    int a, b, c;
    cout << "Enter number 1: ";
    cin >> a;
    cout << "Enter number 2: ";
    cin >> b;
    cout << "Enter number 3: ";
    cin >> c;
    Average::calculate(a, b, c);
    return 0;
}