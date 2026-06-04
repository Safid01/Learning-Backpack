#include <iostream>
#include <queue>
#include <list>

using namespace std;

// Vertex colors
enum Color { WHITE, GREY, BLACK };

class Graph {
private:
    int V;                          // Number of vertices
    vector<list<int>> adj;          // Adjacency list
    vector<Color> color;            // Color of each vertex
    vector<int> d;                  // Distance from source
    vector<int> p;                  // Parent in BFS tree

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
        color.resize(V);
        d.resize(V);
        p.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        // For undirected graph, uncomment the next line:
        // adj[v].push_back(u);
    }

    void BFS(int s) {
        // Initialize vertices (BFS(s): initialize vertices)
        queue<int> Q;
        for (int u = 0; u < V; ++u) {
            color[u] = WHITE;
            d[u] = -1;                  // Undefined (instead of infinity)
            p[u] = -1;                  // No parent
        }

        // Start from source s
        color[s] = GREY;
        d[s] = 0;
        p[s] = -1;                      // Source has no parent
        Q.push(s);                      // Q = {s}

        // Main BFS loop
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();                    // u = Dequeue(Q)

            // Process adjacent vertices
            for (int v : adj[u]) {
                if (color[v] == WHITE) {    // If v is WHITE
                    color[v] = GREY;        // color[v] = GREY
                    d[v] = d[u] + 1;        // d[v] = d[u] + 1
                    p[v] = u;               // p[v] = u (build BFS tree)
                    Q.push(v);              // Enqueue(Q, v)
                }
            }

            color[u] = BLACK;           // color[u] = BLACK
        }
    }

    // Utility to print results
    void printResults() {
        cout << "Vertex\tColor\tDistance\tParent\n";
        for (int u = 0; u < V; ++u) {
            string col_str = (color[u] == WHITE ? "WHITE" : 
                              color[u] == GREY ? "GREY" : "BLACK");
            cout << u << "\t" << col_str << "\t" << d[u] << "\t\t" 
                 << (p[u] == -1 ? "None" : to_string(p[u])) << "\n";
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

    int source = 0;
    cout << "BFS Traversal from source " << source << ":\n";
    g.BFS(source);
    g.printResults();

    return 0;
}