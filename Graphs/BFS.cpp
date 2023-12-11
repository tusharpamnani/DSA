#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <list>

using namespace std;

template <typename T>
class Graph {
public:
    unordered_map<T, list<T>> adj;

    // Function to add an edge between nodes u and v
    void addEdge(T u, T v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming an undirected graph
    }

    // Function to perform Breadth-First Search
    void BFS(T startNode) {
        unordered_set<T> visited; // To keep track of visited nodes
        queue<T> q;

        // Enqueue the starting node
        q.push(startNode);
        visited.insert(startNode);

        while (!q.empty()) {
            T currentNode = q.front();
            cout << currentNode << " ";
            q.pop();

            // Explore adjacent nodes
            for (T neighbor : adj[currentNode]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph<int> g;

    // Get the number of nodes from the user
    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    // Get the number of edges from the user
    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    // Input edges from the user
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    // Get the starting node for BFS from the user
    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    cout << "BFS starting from node " << startNode << ": ";
    g.BFS(startNode);

    return 0;
}
