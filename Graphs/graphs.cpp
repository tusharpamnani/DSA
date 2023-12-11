#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> adj;

    // Function to add an edge between nodes u and v
    // The 'direction' parameter determines if the graph is directed or undirected
    void addEdge(T u, T v, bool direction)
    {
        // Create an edge from u to v
        adj[u].push_back(v);

        // If the graph is undirected, connect both nodes
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    // Function to print the adjacency list
    void printAdjacencyList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";

            // Print all adjacent nodes for the current node
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // Get the number of nodes and edges from the user
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    // Create a graph object
    graph<int> g;

    // Input edges and add them to the graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter edge " << i + 1 << " (format: u v): ";
        cin >> u >> v;

        // Create an undirected graph
        g.addEdge(u, v, 0);
    }

    // Print the adjacency list of the graph
    cout << "Adjacency List:" << endl;
    g.printAdjacencyList();

    return 0;
}
