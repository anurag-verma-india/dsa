#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int V;
    list<int>* l;

   public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];  // like, arr = new int[size]
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int neigh : l[i]) {
                cout << neigh << " ";
            }
            cout << endl;
        }
    }

    void dfsHelper(int u, vector<int>& visited) {
        cout << u << " ";
        visited[u] = true;

        for (int v : l[u]) {
            if (!visited[v]){
                dfsHelper(v, visited);
            }
        }
    }

    void dfs(int starting) {
        vector<int> visited(V, false);
        // dfsHelper(starting, visited);

        // Handling for disconnected graphs
        for(int i = 0; i<V; i++){
            if(!visited[i]) {
                dfsHelper(i, visited);
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    // g.printAdjList();
    cout << "dfs: ";
    g.dfs(0);


    return 0;
}