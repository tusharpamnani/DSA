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
void addEdge(struct Graph* graph, int u, int v, int direction) {
    // Create a new node for the adjacency list of node u
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = v;
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;

    // If the graph is undirected, add an edge from v to u as well
    if (direction == 0) {
        struct Node* anotherNewNode = (struct Node*)malloc(sizeof(struct Node));
        anotherNewNode->value = u;
        anotherNewNode->next = graph->adj[v];
        graph->adj[v] = anotherNewNode;
    }
}

// Function to print the adjacency list of the graph
void printAdjacencyList(struct Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        printf("%d->", i);

        struct Node* currentNode = graph->adj[i];
        // Print all adjacent nodes for the current node
        while (currentNode != NULL) {
            printf("%d, ", currentNode->value);
            currentNode = currentNode->next;
        }

        printf("\n");
    }
}

int main() {
    // Get the number of nodes and edges from the user
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int m;
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    // Create a graph object
    struct Graph* g = createGraph(n);

    // Input edges and add them to the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Enter edge %d (format: u v): ", i + 1);
        scanf("%d %d", &u, &v);

        // Create an undirected graph
        addEdge(g, u, v, 0);
    }

    // Print the adjacency list of the graph
    printf("Adjacency List:\n");
    printAdjacencyList(g);

    return 0;
}
