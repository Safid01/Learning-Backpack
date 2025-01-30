#include <iostream>
using namespace std;

int Factorial(int n) {
    if (n == 0) return 0; // As per problem example
    int fact = 1;
    for (int i = 1; i <= n; ++i) fact = fact * i;
    return fact;
}

int main() {
    int num;
    cin >> num;
    cout << Factorial(num);
    return 0;
}