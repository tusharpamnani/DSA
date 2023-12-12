#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <climits>

using namespace std;

// Function to perform Dijkstra's algorithm
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    // Populate the adjacency list from the given graph
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Initialize distances vector with maximum integer values
    vector<int> dist(vertices, INT_MAX);

    // Create a set to store vertices and their distances
    set<pair<int, int>> st;

    // Set distance for the source vertex to 0
    dist[source] = 0;

    // Insert the source vertex into the set
    st.insert(make_pair(0, source));

    // Dijkstra's algorithm loop
    while (!st.empty()) {
        // Fetch the top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // Remove the top record
        st.erase(st.begin());

        // Traverse neighbors
        for (auto &neighbor : adj[topNode]) {
            // Check if the new distance is smaller than the current distance
            if (nodeDistance + neighbor.second < dist[neighbor.first]) {
                // Update the distance
                dist[neighbor.first] = nodeDistance + neighbor.second;

                // Insert the updated record into the set
                st.insert(make_pair(dist[neighbor.first], neighbor.first));
            }
        }
    }

    return dist;
}

int main() {
    // User input for the graph
    int vertices, edges;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<vector<int>> graph(edges, vector<int>(3));

    cout << "Enter edges in the format (u v w) representing an edge from vertex u to vertex v with weight w:\n";
    for (int i = 0; i < edges; i++) {
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    }

    // User input for the source vertex
    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    // Perform Dijkstra's algorithm
    vector<int> distances = dijkstra(graph, vertices, edges, source);

    // Print distances from the source vertex
    for (int i = 0; i < vertices; i++) {
        cout << "Distance from source to vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
