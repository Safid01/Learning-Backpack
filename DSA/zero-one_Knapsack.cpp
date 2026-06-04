#include <iostream>
#include <algorithm>  // for std::max

int knapsack(int W, int weights[], int values[], int n) {
    // DP table: dp[i][w] = max value using first i items with capacity w
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new int[W + 1];
        for (int w = 0; w <= W; ++w) {
            dp[i][w] = 0;  // initialize
        }
    }

    for (int i = 1; i <= n; ++i) {
        int wi = weights[i - 1];
        int vi = values[i - 1];

        for (int w = 0; w <= W; ++w) {
            if (wi <= w) {
                dp[i][w] = std::max(vi + dp[i - 1][w - wi], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int result = dp[n][W];

    // Clean up memory
    for (int i = 0; i <= n; ++i) {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(values) / sizeof(values[0]);

    std::cout << "Maximum value: " << knapsack(W, weights, values, n) << "\n";
    return 0;
}