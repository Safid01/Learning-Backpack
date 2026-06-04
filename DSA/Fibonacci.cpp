#include <iostream>
#include <vector>
using namespace std;

// Fibonacci function exactly as per the pseudocode
long long Fibonacci(int n) {
    if (n == 0) return 0;          
    if (n == 1) return 1;         
    
    // We need to compute up to F[n]
    vector<long long> F(n + 1);

    F[0] = 0;
    F[1] = 1;
    

    for (int i = 2; i <= n; ++i) {
        F[i] = F[i - 1] + F[i - 2];
    }
    
    return F[n];
}

int main() {
    int n;
    cout << "Enter n to compute Fibonacci(n): ";
    cin >> n;
    
    if (n < 0) {
        cout << "Please enter a non-negative integer.\n";
        return 1;
    }
    
    cout << "Fibonacci(" << n << ") = " << Fibonacci(n) << endl;
    
    return 0;
}