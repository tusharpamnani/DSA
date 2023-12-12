#include<algorithm>

// Comparator function to sort edges based on their weights.
bool cmp(vector<int> &a, vector<int> &b) { 
    return a[2] < b[2];  // Compare based on the third element (weight) of each vector.
}

// Function to initialize a disjoint-set data structure.
void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for (int i=0; i<n; i++){
        // Each node is initially its own parent.
        parent[i] = i;
        // Initially, the rank of each node is 0.
        rank[i] = 0;
    }
}

// Function to find the parent of a node in the disjoint-set.
int findParent(vector<int> &parent, int node){
    if(parent[node] == node){
        // If the node is its own parent, return the node.
        return node;
    }
    // Path compression: Set the parent of the current node to its root.
    return parent[node] = findParent(parent, parent[node]);
}

// Function to perform union operation in the disjoint-set.
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    // Find the root of the set containing the node 'u'.
    u = findParent(parent, u);
    // Find the root of the set containing the node 'v'.
    v = findParent(parent, v);

    // Union by rank: Attach the smaller rank tree under the root of the higher rank tree.
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else if(rank[u] == rank[v]){
        // If ranks are equal, choose one as the root and increment its rank.
        parent[v] = u;
        rank[u]++;
    }
}

// Function to find the minimum spanning tree weight using Kruskal's algorithm.
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    // Sort edges based on weights in non-decreasing order.
    sort(edges.begin(), edges.end(), cmp);

    // Initialize disjoint-set data structure.
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;

    // Iterate over the sorted edges to build the minimum spanning tree.
for(int i = 0; i < edges.size(); i++){
    // Extract the components of the current edge.
    // 'u' and 'v' are the nodes, and 'w' is the weight of the edge.
    int u = findParent(parent, edges[i][0]);  // Find the representative (root) of the set containing node 'u'.
    int v = findParent(parent, edges[i][1]);  // Find the representative (root) of the set containing node 'v'.
    int w = edges[i][2];  // Extract the weight of the current edge.

    // Check if adding this edge creates a cycle in the current spanning tree.
    if(u != v){
        // If adding this edge does not create a cycle, include it in the minimum spanning tree.
        // Update the total weight of the minimum spanning tree.
        minWeight += w;

        // Union the sets containing nodes 'u' and 'v'.
        // This operation merges the sets, making them part of the same connected component.
        unionSet(u, v, parent, rank);
    }
}    
    // Return the total weight of the minimum spanning tree.
    return minWeight;
}
