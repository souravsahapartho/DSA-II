#include<iostream>
#include<vector>
using namespace std;

class Graph{
    int n;
    vector< vector<int> > w;//to represent adjacency matrix
    vector<int> key, p, q;
    bool directed;//directed->true, undirected-->false
public:
    Graph(int n, bool dir): n(n), directed(dir){
        w = vector< vector<int> >(n, vector<int> (n, 0));
    }
    void addEdge(int u, int v, int weight){
        w[u][v] = weight;
        if(!directed) w[v][u] = weight;
    }
    bool isEdge(int u, int v){
        if(w[u][v] != 0) return true;
        return false;
    }

    int ExtractMin(){
        int m = INT_MAX, idx = -1;
        for(int i = 0; i<n; i++){
            if(q[i] == 1 && key[i]<m){
                m = key[i];
                idx = i;
            }
        }
        return idx;
    }

    void MST_Prim(int r){
        key = vector<int>(n, INT_MAX);
        p = vector<int>(n, -1);
        q = vector<int>(n, 1);
        key[r] = 0;

        for(int i = 1; i<=n; i++){
            int u = ExtractMin();
            q[u] = 0;
            for(int v = 0; v<n; v++){
                if( isEdge(u, v) ){
                    //v is adjacent to u
                    if(q[v] == 1 && w[u][v] < key[v]){
                        key[v] = w[u][v];
                        p[v] = u;
                    }
                }
            }
        }
        cout<<"Chosen edges for MST:"<<endl;
        int cost = 0;
        for(int i = 0; i<n; i++){
            if(i != r)
                cout<<"("<<i<<", "<<p[i]<<", "<<key[i]<<")"<<endl;
            cost += key[i];
        }
        cout<<"Cost of MST:"<<cost<<endl;
    }
};
int main(){
    Graph g(5, false );
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 4, 8);
    g.addEdge(3, 4, 9);
    g.MST_Prim(0);
}
