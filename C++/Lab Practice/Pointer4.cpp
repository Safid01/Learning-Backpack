#include <iostream>
using namespace std;

int main() {
    int x = 32;
    int *p = &x;
    char ch = 'A';
    cout << x << ", " << ch << "=" << (int) ch << endl;

    *p += ch;
    cout << x << "=" << (char)x << ", CH=" << ch <<endl;
    return 0;
}