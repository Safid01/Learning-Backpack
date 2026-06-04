#include <iostream>
#include <climits>  // for INT_MAX

using namespace std;

const int MAX_V = 100;  // Maximum number of vertices (adjust if needed)

// Structure to represent graph as adjacency matrix
int graph[MAX_V][MAX_V];
int V;  // Number of vertices (set in main)

// Prim's Algorithm - returns total weight of MST and stores parent array
int primMST(int r) {  // r = starting vertex
    int parent[MAX_V];   // parent[u] = parent of u in MST
    int key[MAX_V];      // key[u] = minimum weight edge connecting u to MST
    bool inQ[MAX_V];     // inQ[u] = true if u is still in priority queue

    // Step 1-4: Initialize all vertices
    for (int u = 0; u < V; ++u) {
        key[u] = INT_MAX;
        parent[u] = -1;   // NIL
        inQ[u] = true;
    }

    // Step 4: Set root key to 0
    key[r] = 0;

    int totalWeight = 0;
    int remaining = V;  // Number of vertices still in Q

    // Step 6: While Q is not empty
    while (remaining > 0) {
        // Step 7: EXTRACT_MIN(Q) - find vertex u with minimum key in Q
        int minKey = INT_MAX;
        int u = -1;
        for (int i = 0; i < V; ++i) {
            if (inQ[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        if (u == -1) break;  // Graph is disconnected

        inQ[u] = false;      // Remove u from Q
        remaining--;
        totalWeight += key[u];

        // Step 8-11: Update neighbors
        for (int v = 0; v < V; ++v) {
            int w = graph[u][v];
            if (w != 0 && inQ[v] && w < key[v]) {  // v in Q and edge exists
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // Print the MST edges
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 0; i < V; ++i) {
        if (parent[i] != -1) {
            cout << parent[i] << " -- " << i << "  (weight: " << graph[parent[i]][i] << ")\n";
        }
    }

    return totalWeight;
}

int main() {
    // Example graph with 6 vertices (0 to 5)
    V = 6;

    // Initialize graph to 0 (no edge)
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            graph[i][j] = 0;

    // Undirected edges: graph[u][v] = graph[v][u] = weight
    graph[0][1] = graph[1][0] = 4;
    graph[0][2] = graph[2][0] = 4;
    graph[1][2] = graph[2][1] = 2;
    graph[1][3] = graph[3][1] = 6;
    graph[2][3] = graph[3][2] = 3;
    graph[2][4] = graph[4][2] = 4;
    graph[2][5] = graph[5][2] = 2;
    graph[3][4] = graph[4][3] = 3;
    graph[4][5] = graph[5][4] = 3;

    int startVertex = 0;
    cout << "Prim's Algorithm starting from vertex " << startVertex << ":\n";
    int total = primMST(startVertex);
    cout << "Total weight of MST: " << total << "\n";

    return 0;
}