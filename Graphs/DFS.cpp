#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <list>

using namespace std;

// Template class for an undirected graph
template <typename T>
class Graph {
public:
    unordered_map<T, list<T>> adj; // Adjacency list representation

    // Function to add an edge between nodes u and v
    void addEdge(T u, T v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming an undirected graph
    }

    // Function to perform Depth-First Search starting from a specified node
    void DFS(T startNode) {
        unordered_set<T> visited; // To keep track of visited nodes
        DFSUtil(startNode, visited);
    }

private:
    // Recursive utility function for DFS
    void DFSUtil(T currentNode, unordered_set<T>& visited) {
        cout << currentNode << " "; // Process the current node
        visited.insert(currentNode); // Mark the current node as visited

        // Explore adjacent nodes
        for (T neighbor : adj[currentNode]) {
            if (visited.find(neighbor) == visited.end()) {
                DFSUtil(neighbor, visited); // Recursively visit unvisited neighbors
            }
        }
    }
};

int main() {
    Graph<int> g; // Create a graph object

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
        g.addEdge(u, v); // Add edges to the graph
    }

    // Get the starting node for DFS from the user
    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    cout << "DFS starting from node " << startNode << ": ";
    g.DFS(startNode); // Perform DFS starting from the specified node

    return 0;
}
