#include <iostream>
#include <climits>

void matrixChainOrder(int d[], int n, int** M, int** s) {
    // n = number of matrices, d has n+1 dimensions

    // Initialize diagonal
    for (int i = 1; i <= n; ++i)
        M[i][i] = 0;

    for (int Len = 2; Len <= n; ++Len) {
        for (int i = 1; i <= n - Len + 1; ++i) {
            int j = i + Len - 1;
            M[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; ++k) {
                int q = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (q < M[i][j]) {
                    M[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParens(int** s, int i, int j) {
    if (i == j) {
        std::cout << "A" << i;
        return;
    }
    std::cout << "(";
    printOptimalParens(s, i, s[i][j]);
    printOptimalParens(s, s[i][j] + 1, j);
    std::cout << ")";
}

int main() {
    int d[] = {10, 30, 5, 60};
    int n = sizeof(d) / sizeof(d[0]) - 1;  // number of matrices = 3

    // Allocate M and s tables
    int** M = new int*[n + 1];
    int** s = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        M[i] = new int[n + 1];
        s[i] = new int[n + 1];
    }

    matrixChainOrder(d, n, M, s);

    std::cout << "Minimum cost: " << M[1][n] << "\n";
    std::cout << "Optimal parenthesization: ";
    printOptimalParens(s, 1, n);
    std::cout << "\n";

    // Deallocate
    for (int i = 0; i <= n; ++i) {
        delete[] M[i];
        delete[] s[i];
    }
    delete[] M;
    delete[] s;

    return 0;
}