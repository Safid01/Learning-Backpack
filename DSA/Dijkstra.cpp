#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// Edge structure
struct Edge {
    int to;
    long long weight;
};

using Graph = vector<vector<Edge>>;

// Dijkstra matching the exact pseudocode in the image
void Dijkstra(const Graph& G, int s) {
    int n = G.size();
    
    vector<long long> dist(n, INF);   // line 02
    vector<int> pred(n, -1);          // line 03 (NIL = -1)
    
    dist[s] = 0;                       // line 04
    
    // Priority queue: {distance, vertex}
    // We use set to simulate a decrease-key capable queue
    // Multiple entries possible, but we ignore outdated ones
    using T = pair<long long, int>;
    set<T> Q;                          // line 06 init(Q, G.V)
    
    for (int u = 0; u < n; ++u) {
        Q.insert({dist[u], u});
    }
    
    while (!Q.empty()) {               // line 07
        // extractMin(Q) - line 08
        auto it = Q.begin();
        long long cost = it->first;
        int u = it->second;
        Q.erase(it);
        
        // If this entry is outdated (better path already found), skip
        if (cost > dist[u]) continue;
        
        // line 10: for each neighbor v of u
        for (const Edge& e : G[u]) {
            int v = e.to;
            long long w = e.weight;
            
            // Relax(u, v, G) - line 11
            if (dist[v] > dist[u] + w) {
                // Before updating, remove old entry if it exists
                if (dist[v] != INF) {
                    Q.erase({dist[v], v});  // remove old (dist[v], v)
                }
                
                dist[v] = dist[u] + w;      // relax
                pred[v] = u;                // predecessor
                
                // modifyKey(Q, v) - insert new better distance
                Q.insert({dist[v], v});
            }
        }
    }
    
    // Output results
    cout << "Vertex   Distance from s   Predecessor\n";
    for (int i = 0; i < n; ++i) {
        cout << "   " << i << "            ";
        if (dist[i] == INF) cout << "INF";
        else cout << dist[i];
        cout << "             ";
        if (pred[i] == -1) cout << "NIL";
        else cout << pred[i];
        cout << "\n";
    }
}

int main() {
    // Graph from the image
    // Vertices: s=0, 5(x)=1, 8(u)=2, 9(v)=3, 7(y)=4
    int n = 5;
    Graph G(n);
    
    auto add_edge = [&](int u, int v, long long w) {
        G[u].push_back({v, w});
    };
    
    add_edge(0, 2, 10);  // s  -> 8
    add_edge(0, 1, 5);   // s  -> 5
    add_edge(1, 2, 2);   // 5  -> 8
    add_edge(1, 3, 7);   // 5  -> 9  (weight 7 in image)
    add_edge(1, 4, 2);   // 5  -> 7
    add_edge(2, 3, 1);   // 8  -> 9
    add_edge(3, 4, 6);   // 9  -> 7
    
    cout << "Dijkstra's algorithm starting from s (vertex 0)\n\n";
    Dijkstra(G, 0);
    
    return 0;
}