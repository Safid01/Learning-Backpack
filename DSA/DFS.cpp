#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Vertex colors
enum Color { WHITE, GREY, BLACK };

class Graph {
private:
    int V;                          // Number of vertices
    vector<list<int>> adj;          // Adjacency list
    vector<Color> color;            // Color of each vertex
    vector<int> d;                  // Discovery time
    vector<int> f;                  // Finishing time
    vector<int> p;                  // Parent in DFS tree
    int time;

    void DFS_Visit(int u) {
        color[u] = GREY;            // Mark as visiting (GREY)
        time = time + 1;
        d[u] = time;                // Discovery time

        // Explore all adjacent vertices
        for (int v : adj[u]) {
            if (color[v] == WHITE) {
                p[v] = u;           // Set parent
                DFS_Visit(v);       // Recursively visit
            }
        }

        color[u] = BLACK;           // Done visiting
        time = time + 1;
        f[u] = time;                // Finishing time
    }

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
        color.assign(V, WHITE);
        d.assign(V, 0);
        f.assign(V, 0);
        p.assign(V, -1);            // -1 means no parent (root)
        time = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        // For undirected graph, uncomment the next line:
        // adj[v].push_back(u);
    }

    void DFS() {
        // Initialize all vertices
        fill(color.begin(), color.end(), WHITE);
        fill(d.begin(), d.end(), 0);
        fill(f.begin(), f.end(), 0);
        fill(p.begin(), p.end(), -1);
        time = 0;

        // Visit each unvisited (WHITE) vertex
        for (int u = 0; u < V; ++u) {
            if (color[u] == WHITE) {
                DFS_Visit(u);
            }
        }
    }

    // Utility to print results
    void printResults() {
        cout << "Vertex\tDiscovery\tFinish\tParent\n";
        for (int u = 0; u < V; ++u) {
            cout << u << "\t" << d[u] << "\t\t" << f[u] << "\t" << (p[u] == -1 ? "None" : to_string(p[u])) << "\n";
        }
    }
};

int main() {
    // Example graph with 6 vertices (0 to 5)
    Graph g(6);

    // Undirected graph edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 5);

    cout << "DFS Traversal Results:\n";
    g.DFS();
    g.printResults();

    return 0;
}