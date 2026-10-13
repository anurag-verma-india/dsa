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
        l = new list<int>[V];
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

    bool dfs(int u, int parent, vector<bool>& visited) {
        visited[u] = true;
        list<int> neighbors = l[u];
        for (int v : neighbors) {
            if (!visited[v]) {
                if (dfs(v, u, visited)) return true;
            } else if (v != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCycle() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            // Handle disconnected graph
            if (!visited[i]) {
                if (dfs(i, -1, visited)) return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);

    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    g.printAdjList();

    cout << "Graph contains cycle: " << (g.isCycle() ? "yes" : "no") << endl;
    return 0;
}
