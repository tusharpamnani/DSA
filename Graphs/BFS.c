#include <stdio.h>
#include <stdlib.h>

// Node structure represents a node in the adjacency list
struct Node {
    int value;           // Value of the node
    struct Node* next;    // Pointer to the next node in the list
};

// Graph structure represents an undirected graph using an adjacency list
struct Graph {
    int numNodes;         // Number of nodes in the graph
    struct Node** adj;    // Array of pointers to nodes representing the adjacency list
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

// Function to perform Breadth-First Search starting from a specified node
void BFS(struct Graph* graph, int startNode) {
    int* visited = (int*)malloc(graph->numNodes * sizeof(int));

    // Initialize all nodes as not visited
    for (int i = 0; i < graph->numNodes; i++) {
        visited[i] = 0;
    }

    struct Node** queue = (struct Node**)malloc(graph->numNodes * sizeof(struct Node*));
    int front = 0, rear = 0;

    // Enqueue the starting node
    queue[rear++] = graph->adj[startNode];
    visited[startNode] = 1;

    while (front < rear) {
        struct Node* currentNode = queue[front++];

        // Process the current node
        printf("%d ", currentNode->value);

        // Explore adjacent nodes
        while (currentNode != NULL) {
            int neighbor = currentNode->value;

            // If the neighbor is not visited, enqueue it and mark it as visited
            if (!visited[neighbor]) {
                queue[rear++] = graph->adj[neighbor];
                visited[neighbor] = 1;
            }

            currentNode = currentNode->next;
        }
    }

    // Free allocated memory
    free(visited);
    free(queue);
}

int main() {
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Create a graph object
    struct Graph* g = createGraph(numNodes);

    int numEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (format: u v):\n");
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add edges to the graph
        addEdge(g, u, v);
    }

    int startNode;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);

    // Perform BFS starting from the specified node
    printf("BFS starting from node %d: ", startNode);
    BFS(g, startNode);

    // Free allocated memory for the graph
    free(g->adj);
    free(g);

    return 0;
}
