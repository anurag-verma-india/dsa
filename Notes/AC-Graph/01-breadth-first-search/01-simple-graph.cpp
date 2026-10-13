#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph {
    int V;
    list<int>* l;  // int *arr; i.e. pointer to a list of ints (dynamic array)
    // access (int)arr[0], (int)arr[1], ...

   public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
        // arr = new int[V]
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // void printAdjList() {
    //     for(int i = 0;i<V;i++) {
    //         cout << i << " : " ;
    //         for(int neigh: l[i]) {
    //             cout << neigh << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    void bfs(int starting_node) {
        /*
        Approach:
            Visit all immediate neighbours of each node first

            Keep a queue of all the immediate neighbours, mark all the visited ones in a separate array
            Initialize the queue with a single node

            Until the queue becomes empty
                Mark this top as visited
                Add add the unvisited neighbours of current top to the queue

            Time complexity: O(V+E)
         */
        queue<int> q;
        vector<bool> visited(V, false);

        q.push(starting_node);
        visited[starting_node] = true;

        while (q.size() > 0) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int v: l[u]) {
                // v -> immediate neighbour
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
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
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    // g.printAdjList();
    g.bfs(0);

    return 0;
}
