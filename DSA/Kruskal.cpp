#include <iostream>
#include <algorithm>  // for std::sort

using namespace std;

// Edge structure
struct Edge {
    int u, v, w;
};

// Comparison function for sorting edges by weight (non-decreasing)
bool compareEdges(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

// Disjoint Set Union (DSU) with path compression and union by rank
class DSU {
private:
    int* parent;
    int* rank;
    int n;

public:
    DSU(int size) {
        n = size;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;    // MAKE_SET(v)
            rank[i] = 0;
        }
    }

    ~DSU() {
        delete[] parent;
        delete[] rank;
    }

    int FIND_SET(int x) {
        if (parent[x] != x) {
            parent[x] = FIND_SET(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void UNION(int x, int y) {
        int px = FIND_SET(x);
        int py = FIND_SET(y);
        if (px == py) return;

        // Union by rank
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

// Kruskal's Algorithm - returns MST edges and total weight
void kruskalMST(int V, Edge edges[], int E, Edge mst[], int& mstSize, int& totalWeight) {
    mstSize = 0;
    totalWeight = 0;

    // Step 4: Sort all edges in non-decreasing order of weight
    sort(edges, edges + E, compareEdges);

    // Step 2-3: Initialize DSU
    DSU dsu(V);

    // Step 5-8: Process each edge
    for (int i = 0; i < E; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (dsu.FIND_SET(u) != dsu.FIND_SET(v)) {
            // Add to MST
            mst[mstSize++] = edges[i];
            totalWeight += edges[i].w;
            dsu.UNION(u, v);
        }
    }
}

int main() {
    int V = 6;  // Number of vertices (0 to 5)
    int E = 9;  // Number of edges

    // All edges: {u, v, weight}
    Edge edges[9] = {
        {0, 1, 4}, {0, 2, 4}, {1, 2, 2},
        {1, 0, 4}, {2, 3, 3}, {2, 5, 2},
        {2, 4, 4}, {3, 4, 3}, {4, 5, 3}
    };

    // Array to store MST edges (max V-1 edges)
    Edge mst[10];
    int mstSize;
    int totalWeight;

    kruskalMST(V, edges, E, mst, mstSize, totalWeight);

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 0; i < mstSize; ++i) {
        cout << mst[i].u << " -- " << mst[i].v << "  (weight: " << mst[i].w << ")\n";
    }
    cout << "Total weight of MST: " << totalWeight << "\n";

    return 0;
}