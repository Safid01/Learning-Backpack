#include <iostream>
using namespace std;

int main() {

    int n = 7;
    double W = 15;

    double value[7]  = {10, 5, 15, 7, 6, 18, 3};
    double weight[7] = { 2, 3, 5, 7, 1, 4, 1};

    double ratio[7];
    int ratioInt[7];

    // ----------------------------------------------------------
    // Step 1: ratio[i] = value[i] / weight[i]
    // ----------------------------------------------------------
    for (int i = 0; i < n; i++) {
        ratio[i] = value[i] / weight[i];
        ratioInt[i] = ratio[i] * 100;   // use integer ratio*100 for counting sort
    }

    // ----------------------------------------------------------
    // Step 2: Counting Sort (DESCENDING)
    // ----------------------------------------------------------

    int k = ratioInt[0];
    for (int i = 1; i < n; i++)
        if (ratioInt[i] > k) k = ratioInt[i];

    int C[k+1];
    for (int i = 0; i <= k; i++) C[i] = 0;

    int order[7];

    for (int i = 0; i < n; i++)
        C[ratioInt[i]]++;

    for (int i = k - 1; i >= 0; i--)
        C[i] = C[i] + C[i + 1];

    for (int i = 0; i < n; i++) {
        C[ratioInt[i]]--;
        order[C[ratioInt[i]]] = i;
    }

    // ----------------------------------------------------------
    // Fractional Knapsack + extra outputs
    // ----------------------------------------------------------

    double totalValue = 0;
    double currentWeight = 0;

    int takenObjectIndex[7];  // store which objects were taken
    double takenFraction[7];  // fraction taken (1 for full)
    int takenCount = 0;

    for (int i = 0; i < n; i++) {

        int idx = order[i];
        double v = value[idx];
        double w = weight[idx];

        if (currentWeight + w <= W) {
            totalValue += v;
            currentWeight += w;

            takenObjectIndex[takenCount] = idx + 1;   // object number (1-based)
            takenFraction[takenCount] = 1.0;          // full item
            takenCount++;
        }
        else {
            double remain = W - currentWeight;
            double frac = remain / w;

            totalValue += v * frac;

            currentWeight += remain;

            takenObjectIndex[takenCount] = idx + 1;
            takenFraction[takenCount] = frac;
            takenCount++;

            break; // knapsack is full
        }
    }

    // ----------------------------------------------------------
    // OUTPUT
    // ----------------------------------------------------------
    cout << "Maximum value in knapsack = " << totalValue << endl;

    cout << "Total weight used = " << currentWeight << endl;

    cout << "Objects taken: ";
    for (int i = 0; i < takenCount; i++)
        cout << takenObjectIndex[i] << " ";
    cout << endl;

    cout << "Fractions taken: ";
    for (int i = 0; i < takenCount; i++)
        cout << takenFraction[i] << " ";
    cout << endl;

    cout << "Object count = " << takenCount << endl;

    return 0;
}