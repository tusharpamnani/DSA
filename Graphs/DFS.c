#include <stdio.h>
#include <stdlib.h>

// Node structure represents a node in the adjacency list
struct Node {
    int value;
    struct Node* next;
};

// Graph structure represents an undirected graph using an adjacency list
struct Graph {
    int numNodes;
    struct Node** adj;
};

// Function to create a new graph with a specified number of nodes
struct Graph* createGraph(int numNodes) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = numNodes;
    graph->adj = (struct Node**)malloc(numNodes * sizeof(struct Node*));

    // Initialize each adjacency list to NULL
    for (int i = 0; i < numNodes; i++) {
        graph->adj[i] = NULL;
    }

    return graph;
}

// Function to add an edge between nodes u and v to the graph
void addEdge(struct Graph* graph, int u, int v) {
    // Create a new node for the adjacency list of node u
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = v;
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;

    // Create a new node for the adjacency list of node v
    struct Node* anotherNewNode = (struct Node*)malloc(sizeof(struct Node));
    anotherNewNode->value = u;
    anotherNewNode->next = graph->adj[v];
    graph->adj[v] = anotherNewNode;
}

// Recursive utility function for DFS
void DFSUtil(struct Graph* graph, int currentNode, int* visited) {
    printf("%d ", currentNode); // Process the current node
    visited[currentNode] = 1;    // Mark the current node as visited

    // Explore adjacent nodes
    struct Node* neighborNode = graph->adj[currentNode];
    while (neighborNode != NULL) {
        int neighbor = neighborNode->value;
        if (!visited[neighbor]) {
            DFSUtil(graph, neighbor, visited); // Recursively visit unvisited neighbors
        }
        neighborNode = neighborNode->next;
    }
}

// Function to perform Depth-First Search starting from a specified node
void DFS(struct Graph* graph, int startNode) {
    int* visited = (int*)malloc(graph->numNodes * sizeof(int));

    // Initialize all nodes as not visited
    for (int i = 0; i < graph->numNodes; i++) {
        visited[i] = 0;
    }

    // Call the recursive utility function starting from the specified node
    DFSUtil(graph, startNode, visited);

    free(visited); // Free allocated memory
}

int main() {
    // Get the number of nodes from the user
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Create a graph object
    struct Graph* g = createGraph(numNodes);

    // Get the number of edges from the user
    int numEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Input edges from the user
    printf("Enter the edges (format: u v):\n");
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add edges to the graph
        addEdge(g, u, v);
    }

    // Get the starting node for DFS from the user
    int startNode;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);

    printf("DFS starting from node %d: ", startNode);
    DFS(g, startNode); // Perform DFS starting from the specified node

    // Free allocated memory for the graph
    free(g->adj);
    free(g);

    return 0;
}
