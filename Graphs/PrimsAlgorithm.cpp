#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
using namespace std;

// Function to calculate the Minimum Spanning Tree (MST) using Prim's algorithm.
// Returns a vector of edges forming the MST along with their weights.
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Create adjacency list
  unordered_map<int, list<pair<int, int>>> adj;
  
  // Build the adjacency list from the given graph edges.
  for (int i = 0; i < g.size(); i++)
  {
      // Extracting information from the input graph edge.
      int u = g[i].first.first;    // Starting vertex of the edge
      int v = g[i].first.second;   // Ending vertex of the edge
      int w = g[i].second;          // Weight of the edge
  
      // Adding the edge to the adjacency list for both vertices (undirected graph).
      // An undirected edge (u, v) is added as (u, w) to the adjacency list of v,
      // and (v, w) is added to the adjacency list of u.
      adj[u].push_back(make_pair(v, w));
      adj[v].push_back(make_pair(u, w));
  }


    // Initialize key, parent, and mst arrays.
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    // Initialize key values to infinity, parent to -1, and mst status to false.
    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // Start with the first node as the source.
    key[1] = 0;
    parent[1] = -1;

    // Iterate over all vertices to build the MST.
    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        // Finding the minimum key value node.
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // Mark the selected node as part of the MST.
        mst[u] = true;

        // Update key values and parent for adjacent nodes.
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // Construct the result vector containing MST edges and their weights.
    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }

    // Return the MST edges and their weights.
    return result;
}

// Example usage in main function or elsewhere:
// int main() {
//     // Input values for the number of vertices, edges, and the graph.
//     int n, m;
//     cin >> n >> m;
//     vector<pair<pair<int, int>, int>> g(m);
//     // Input graph edges...
//
//     // Calculate MST using Prim's algorithm.
//     vector<pair<pair<int, int>, int>> result = calculatePrimsMST(n, m, g);
//
//     // Output MST edges and their weights.
//     for (auto edge : result) {
//         cout << "Edge: (" << edge.first.first << ", " << edge.first.second << ") Weight: " << edge.second << endl;
//     }
//
//     return 0;
// }
