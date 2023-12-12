// Function to find the shortest distance of all the vertices
// from the source vertex S using Dijkstra's algorithm.
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Priority queue to store pairs of distance and node.
    // Min-heap is used to always select the node with the smallest distance.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Vector to store the distances from the source vertex to all other vertices.
    vector<int> dist(V);

    // Initializing distances to a very large value.
    for (int i = 0; i < V; i++)
    {
        dist[i] = 1e9;
    }

    // Distance from source to itself is 0.
    dist[S] = 0;

    // Pushing the source node and its distance into the priority queue.
    pq.push({0, S});

    // Dijkstra's algorithm
    while (!pq.empty())
    {
        // Extracting the minimum distance node from the priority queue.
        int dis = pq.top().first;
        int node = pq.top().second;
        
        pq.pop();

        // Iterating over the adjacent nodes of the current node.
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWeight = it[1];

            // If a shorter path is found to the adjacent node, update the distance.
            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight;

                // Push the updated distance and node into the priority queue.
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    // Return the vector containing the shortest distances from the source vertex.
    return dist;
}
