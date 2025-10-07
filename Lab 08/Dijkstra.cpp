#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

class Graph {
    int n;
    vector<vector<int>> w; // Adjacency matrix
    vector<int> d, p, q;
    bool directed;

public:
    Graph(int n, bool dir) : n(n), directed(dir) {
        w = vector<vector<int>>(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v, int weight) {
        w[u][v] = weight;
        if (!directed)
            w[v][u] = weight;
    }

    bool isEdge(int u, int v) {
        return w[u][v] != 0;
    }

    int ExtractMin() {
        int m = INT_MAX;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (q[i] == 1 && d[i] < m) {
                m = d[i];
                idx = i;
            }
        }
        return idx;
    }

    void Dijkstra(int src) {
        d = vector<int>(n, INT_MAX);
        p = vector<int>(n, -1);
        q = vector<int>(n, 1);
        d[src] = 0;

        for (int i = 0; i < n; i++) {
            int u = ExtractMin();
            if (u == -1) break; // All reachable vertices processed
            q[u] = 0;

            for (int v = 0; v < n; v++) {
                if (isEdge(u, v) && q[v] == 1) {
                    if (d[u] + w[u][v] < d[v]) {
                        d[v] = d[u] + w[u][v];
                        p[v] = u;
                    }
                }
            }
        }

        // Print shortest distances from source
        cout << "Vertex\tDistance from Source\tPath\n";
        for (int i = 0; i < n; i++) {
            cout << i << "\t" << d[i] << "\t\t";
            printPath(i);
            cout << endl;
        }
    }

    void printPath(int v) {
        if (p[v] == -1) {
            cout << v;
            return;
        }
        printPath(p[v]);
        cout << " -> " << v;
    }
};

int main() {
    Graph g(5, false);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 4, 8); // Last valid edge; remove or fix the duplicate

    g.Dijkstra(0);

    return 0;
}
