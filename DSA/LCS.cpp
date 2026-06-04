#include <iostream>
#include <string>
#include <algorithm>  // for std::max

using namespace std;

// Returns the length of LCS and the LCS string itself
pair<int, string> longestCommonSubsequence(const string& A, const string& B) {
    int m = A.length();
    int n = B.length();

    // L[i][j] will store length of LCS of A[0..i-1] and B[0..j-1]
    int** L = new int*[m + 1];
    for (int i = 0; i <= m; ++i) {
        L[i] = new int[n + 1];
    }

    // b[i][j] will store direction: "↖" (diagonal), "↑" (up), "←" (left)
    char** b = new char*[m + 1];
    for (int i = 0; i <= m; ++i) {
        b[i] = new char[n + 1];
    }

    // Step iii & iv: Initialize first row and first column
    for (int i = 0; i <= m; ++i) L[i][0] = 0;
    for (int j = 0; j <= n; ++j) L[0][j] = 0;

    // Step vii to xvi: Fill the table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1]) {          // Step ix
                L[i][j] = L[i - 1][j - 1] + 1;
                b[i][j] = '\\';                  // diagonal (we use '\' for ↖)
            }
            else if (L[i - 1][j] >= L[i][j - 1]) { // Step xii
                L[i][j] = L[i - 1][j];
                b[i][j] = '|';                   // up (we use '|' for ↑)
            }
            else {                                // Step xv
                L[i][j] = L[i][j - 1];
                b[i][j] = '-';                   // left (we use '-' for ←)
            }
        }
    }

    // Reconstruct the LCS string by backtracking using b table
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (b[i][j] == '\\') {       // came from diagonal → character match
            lcs = string(1, A[i - 1]) + lcs;     // prepend the character
            --i;
            --j;
        }
        else if (b[i][j] == '|') {   // came from up
            --i;
        }
        else {                       // came from left
            --j;
        }
    }

    // Clean up memory
    int lcsLength = L[m][n];
    for (int k = 0; k <= m; ++k) {
        delete[] L[k];
        delete[] b[k];
    }
    delete[] L;
    delete[] b;

    return {lcsLength, lcs};
}

int main() {
    string A = "ABCBDAB";
    string B = "BDCAB";

    pair<int, string> res = longestCommonSubsequence(A, B);
    int length = res.first;
    string lcs = res.second;

    cout << "String A: " << A << "\n";
    cout << "String B: " << B << "\n";
    cout << "Length of LCS: " << length << "\n";
    cout << "One LCS: " << lcs << "\n";

    // Another example
    cout << "\nExample 2:\n";
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    pair<int, string> res2 = longestCommonSubsequence(X, Y);
    int len2 = res2.first;
    string lcs2 = res2.second;
    cout << "X: " << X << "\n";
    cout << "Y: " << Y << "\n";
    cout << "LCS: " << lcs2 << " (length " << len2 << ")\n";

    return 0;
}