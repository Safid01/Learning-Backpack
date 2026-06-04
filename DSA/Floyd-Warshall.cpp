#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void FloydWarshall(vector<vector<long long>>& dist, int n) {
    // Predecessor matrix (optional, for path reconstruction)
    vector<vector<int>> pred(n, vector<int>(n, -1));  // -1 means NIL/no direct edge initially
    
    // Initialization (as in the image)
    // Already done outside: dist[i][j] set to 0, w_ij, or INF
    
    // Set predecessors for direct edges
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && dist[i][j] < INF) {
                pred[i][j] = i;  // direct edge i -> j
            }
        }
    }
    
    // Main algorithm: k from 1 to n (but using 0-based indexing)
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    long long new_dist = dist[i][k] + dist[k][j];
                    if (new_dist < dist[i][j]) {
                        dist[i][j] = new_dist;
                        pred[i][j] = pred[k][j];  // update path
                    }
                }
            }
        }
    }
    
    // Optional: Check for negative cycles
    // If dist[i][i] < 0 for any i, there is a negative cycle
    bool negative_cycle = false;
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) {
            negative_cycle = true;
            break;
        }
    }
    
    if (negative_cycle) {
        cout << "Negative cycle detected!\n";
    }
}

// Helper to print the distance matrix nicely
void printMatrix(const vector<vector<long long>>& dist, int n, const vector<string>& names) {
    cout << "All-Pairs Shortest Paths (Floyd-Warshall):\n\n";
    cout << "     ";
    for (int j = 0; j < n; ++j) {
        cout << setw(10) << names[j];
    }
    cout << "\n";
    
    for (int i = 0; i < n; ++i) {
        cout << names[i] << " ";
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                cout << setw(10) << "INF";
            else
                cout << setw(10) << dist[i][j];
        }
        cout << "\n";
    }
}

int main() {
    int n = 5;
    vector<string> names = {"s(0)", "5(1)", "8(2)", "9(3)", "7(4)"};
    
    // Initialize distance matrix
    vector<vector<long long>> dist(n, vector<long long>(n, INF));
    
    // Set diagonal to 0
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    
    // Add edges (same graph as before)
    auto add_edge = [&](int i, int j, long long w) {
        dist[i][j] = w;  // directed graph
        // For undirected: also dist[j][i] = w;
    };
    
    add_edge(0, 1, 5);   // s -> 5
    add_edge(0, 2, 10);  // s -> 8
    add_edge(1, 2, 2);   // 5 -> 8
    add_edge(1, 3, 7);   // 5 -> 9
    add_edge(1, 4, 2);   // 5 -> 7
    add_edge(2, 3, 1);   // 8 -> 9
    add_edge(3, 4, 6);   // 9 -> 7
    
    cout << "Running Floyd-Warshall on the graph...\n\n";
    
    FloydWarshall(dist, n);
    
    printMatrix(dist, n, names);
    
    return 0;
}