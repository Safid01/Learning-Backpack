#include <iostream>
using namespace std;

int main() {
    int A[] = {2, 5, 3, 1, 5, 2, 4, 3, 0, 0, 33};
    int n = sizeof(A) / sizeof(A[0]);   // auto size
    
    // Find max value
    int k = 0;
    for (int i = 0; i < n; i++)
        if (A[i] > k) k = A[i];
    
    int C[k+1] = {0};   // counting array
    int B[n] = {0};    // output array
    
    // Step 1: Count
    for (int j = 0; j < n; j++)
        C[A[j]] = C[A[j]] + 1;
    
    // Step 2: Cumulative sum
    for (int i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    
    // Step 3: Build output FROM 0 TO n-1 (forward) ← as you asked
    for (int j = 0; j < n; j++) {
        C[A[j]] = C[A[j]] - 1;
        B[C[A[j]]] = A[j];
    }
    
    // Print result
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << B[i] << " ";
    cout << endl;
    
    return 0;
}