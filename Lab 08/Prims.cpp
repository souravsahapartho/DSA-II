#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

class Graph {
    int n;
    vector<vector<int>> w; // Adjacency matrix
    vector<int> key, p, q;
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
            if (q[i] == 1 && key[i] < m) {
                m = key[i];
                idx = i;
            }
        }
        return idx;
    }

    void MST_Prim(int r) {
        key = vector<int>(n, INT_MAX);
        p = vector<int>(n, -1);
        q = vector<int>(n, 1);
        key[r] = 0;

        for (int i = 1; i <= n; i++) {
            int u = ExtractMin();
            if (u == -1) break; // In case graph is disconnected
            q[u] = 0;

            for (int v = 0; v < n; v++) {
                if (isEdge(u, v)) {
                    // v is adjacent to u
                    if (q[v] == 1 && w[u][v] < key[v]) {
                        key[v] = w[u][v];
                        p[v] = u;
                    }
                }
            }
        }

        cout << "Chosen edges for MST:\n";
        int cost = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] != -1) {
                cout << "(" << p[i] << " - " << i << ")  ";
                cost += w[i][p[i]];
            }
        }
        cout << "\nCost of MST: " << cost << endl;
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
    g.addEdge(2, 4, 8);
    g.addEdge(2, 4, 9); // This will overwrite the previous edge

    g.MST_Prim(0);

    return 0;
}
