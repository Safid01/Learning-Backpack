#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// Edge representation
struct Edge {
    int u, v;          // from u to v
    long long weight;  // w(u,v)
};

using Graph = vector<Edge>;  // List of all edges (easier for Bellman-Ford)

// Bellman-Ford algorithm exactly as in the image
bool BellmanFord(const Graph& G_edges, int n, int s) {
    vector<long long> dist(n, INF);  // line 02
    vector<int> pred(n, -1);         // line 03 (NIL = -1)
    
    dist[s] = 0;                     // line 04
    
    // lines 05-07: Repeat |V|-1 times
    for (int i = 1; i <= n - 1; ++i) {
        for (const Edge& e : G_edges) {
            int u = e.u;
            int v = e.v;
            long long w = e.weight;
            
            // Relax(u, v, G)
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pred[v] = u;
            }
        }
    }
    
    // lines 08-10: Check for negative cycle
    for (const Edge& e : G_edges) {
        int u = e.u;
        int v = e.v;
        long long w = e.weight;
        
        if (dist[u] != INF && dist[v] > dist[u] + w) {
            return false;  // negative cycle exists (reachable from s)
        }
    }
    
    // line 11
    return true;
}

// Helper function to print results
void printResult(const vector<long long>& dist, const vector<int>& pred, int n) {
    cout << "Vertex   Distance from Source   Predecessor\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < n; ++i) {
        cout << "   " << i << "     ";
        if (dist[i] == INF)
            cout << "     INF";
        else
            cout << setw(10) << dist[i];
        cout << "          ";
        if (pred[i] == -1)
            cout << "NIL";
        else
            cout << pred[i];
        cout << "\n";
    }
}

int main() {
    int n = 5;           // number of vertices
    int s = 0;           // source vertex
    
    Graph edges;         // all edges
    
    auto add_edge = [&](int u, int v, long long w) {
        edges.push_back({u, v, w});
    };
    
    // Example graph (positive weights - no negative cycle)
    add_edge(0, 1, 5);   // s -> 5
    add_edge(0, 2, 10);  // s -> 8
    add_edge(1, 2, 2);   // 5 -> 8
    add_edge(1, 3, 7);   // 5 -> 9
    add_edge(1, 4, 2);   // 5 -> 7
    add_edge(2, 3, 1);   // 8 -> 9
    add_edge(3, 4, 6);   // 9 -> 7
    
    cout << "Bellman-Ford Algorithm (Source = " << s << ")\n\n";
    
    vector<long long> dist(n);
    vector<int> pred(n);
    
    // Run the algorithm
    if (BellmanFord(edges, n, s)) {
        // Retrieve dist and pred after successful run
        // (We run a modified version to capture them)
        dist.assign(n, INF);
        pred.assign(n, -1);
        dist[s] = 0;
        
        for (int i = 1; i <= n-1; ++i) {
            for (const Edge& e : edges) {
                if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.weight) {
                    dist[e.v] = dist[e.u] + e.weight;
                    pred[e.v] = e.u;
                }
            }
        }
        
        printResult(dist, pred, n);
    } else {
        cout << "Negative cycle detected! No single-source shortest paths exist.\n";
    }
    
    return 0;
}