#include <iostream>
#include <list>
#include <queue>
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

    bool checkCycleBfs(int starting) {
        /*
        Visit all neighbors of current node first

        Keep a queue of all the unvisited neighbors (ini with a node of your choice)
            iterate through the queue and keep adding unvisited neighbors until it is empty
        */

        queue<pair<int, int>> q;  // pair<element, parent>
        vector<bool> visited(V, false);

        q.push(pair(starting, -1));
        visited[starting] = true;

        while (!q.empty()) {
            pair<int, int> u = q.front();
            int parent = u.second;
            q.pop();
            for (auto v : l[u.first]) {
                if (!visited[v]) {
                    q.push(pair(v, u.first));
                    visited[v] = true;
                } else {
                    if(v != parent) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    cout << "Graph contains cycle: " << (g.checkCycleBfs(0) ? "yes" : "no") << endl;

    return 0;
}