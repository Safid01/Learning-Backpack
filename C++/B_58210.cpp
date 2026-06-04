#include <iostream>
using namespace std;

int main() {
    int n, amount;

    cout << "Enter number of denominations: ";
    cin >> n;

    int coins[100];
    cout << "Enter the denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter target amount: ";
    cin >> amount;

    int k = 0;
    for (int i = 0; i < n; i++)
        if (coins[i] > k) k = coins[i];
    
    int C[] = {0};   
    int B[] = {0};   

    for (int j = 0; j < n; j++)
        C[coins[j]] = C[coins[j]] + 1;
    
    for (int i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    
    for (int j = 0; j < n; j++) {
        C[coins[j]] = C[coins[j]] - 1;
        B[C[coins[j]]] = coins[j];
    }

    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
        cout << endl;
    }

}