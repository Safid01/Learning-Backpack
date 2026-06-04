#include <iostream>
using namespace std;

int main() {

    // Original (unsorted) coin array
    int A[] = {1, 2, 5, 10, 20, 50, 100};
    int n = sizeof(A) / sizeof(A[0]);

    // -----------------------------------
    // COUNTING SORT IN DESCENDING ORDER
    // -----------------------------------


    int k = 0;
    for (int i = 0; i < n; i++)
        if (A[i] > k) k = A[i];

    int C[k+1] = {0};
    int B[n];

    for (int j = 0; j < n; j++)
        C[A[j]]++;

    for (int i = k - 1; i >= 0; i--)
        C[i] = C[i] + C[i + 1];

    for (int j = 0; j < n; j++) {
        C[A[j]]--;
        B[C[A[j]]] = A[j];
    }

    cout << "Coins After Counting Sort (Descending): ";
    for (int i = 0; i < n; i++)
        cout << B[i] << " ";
    cout << "\n";

    // -----------------------------------
    // 0/1 BOUNDED COIN SHIFTING
    // -----------------------------------
    int target = 93;
    int selected1[10];
    int count1 = 0;
    int remaining = target;

    for (int i = 0; i < n; i++) {
        if (B[i] <= remaining) {
            selected1[count1] = B[i];
            count1++;
            remaining -= B[i];
        }
    }

    cout << "\nBounded Coin Shifting (0/1): ";
    int total1 = 0;
    for (int i = 0; i < count1; i++) {
        cout << selected1[i] << " ";
        total1 += selected1[i];
    }
    cout << "\nTotal Coins Used: " << count1;
    cout << "\nTotal Value: " << total1 << "\n";

    // -----------------------------------
    // UNBOUNDED COIN SHIFTING
    // -----------------------------------
    int selected2[100];
    int count2 = 0;
    remaining = target;

    for (int i = 0; i < n; i++) {
        while (B[i] <= remaining) {
            selected2[count2] = B[i];
            count2++;
            remaining -= B[i];
        }
    }

    cout << "\nUnbounded Coin Shifting: ";
    int total2 = 0;
    for (int i = 0; i < count2; i++) {
        cout << selected2[i] << " ";
        total2 += selected2[i];
    }
    cout << "\nTotal Coins Used: " << count2;
    cout << "\nTotal Value: " << total2 << "\n";

    return 0;
}