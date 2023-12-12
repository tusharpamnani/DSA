# Graphs

## Introduction:
Graphs are a fundamental data structure in computer science and mathematics. They consist of nodes (vertices) and edges that connect these nodes. Graphs can be directed or undirected, and edges may have weights.

## Pseudocode:
```plaintext
Graph Representation: G(V, E)

// Add a vertex to the graph
addVertex(vertex)

// Add an edge between two vertices
addEdge(vertex1, vertex2)

// Remove a vertex from the graph
removeVertex(vertex)

// Remove an edge between two vertices
removeEdge(vertex1, vertex2)
```

## Algorithms:

### Breadth-First Search (BFS):

#### Definition:

Breadth-First Search (BFS) is a graph traversal algorithm that explores all the vertices of a graph level by level, visiting all the neighbors of a vertex before moving on to the next level. It uses a queue data structure to keep track of the vertices to be explored.

#### Pseudocode:
```plaintext
BFS(graph, start_vertex):
    queue = Queue()
    visited = set()

    queue.enqueue(start_vertex)
    visited.add(start_vertex)

    while queue is not empty:
        current_vertex = queue.dequeue()

        for neighbor in graph.get_neighbors(current_vertex):
            if neighbor not in visited:
                queue.enqueue(neighbor)
                visited.add(neighbor)
```

#### Real-life Use Cases:
- Shortest path finding in unweighted graphs.
- Web crawling to discover and index web pages layer by layer.

#### Advantages and Disadvantages:
- **Advantages:** Guarantees the shortest path for unweighted graphs.
- **Disadvantages:** Inefficient for dense graphs.

#### Key Characteristics:

- Guarantees the shortest path for unweighted graphs.
- Uses a First-In-First-Out (FIFO) queue for traversal.
- Efficiently finds the shortest path in unweighted graphs.
- Requires additional memory to store visited nodes.


### Depth-First Search (DFS):

#### Definition:
Depth-First Search (DFS) is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It uses a stack data structure (or recursion) to keep track of the vertices to be explored.

#### Pseudocode:
```plaintext
DFS(graph, start_vertex, visited):
    if start_vertex not in visited:
        visit(start_vertex)
        visited.add(start_vertex)

        for neighbor in graph.get_neighbors(start_vertex):
            DFS(graph, neighbor, visited)
```

#### Key Characteristics:

- Does not guarantee the shortest path.
- Uses a Last-In-First-Out (LIFO) stack or recursion for traversal.
- Memory-efficient, suitable for sparse graphs.
- Can be used for topological sorting.

#### Real-life Use Cases:
- Topological sorting.
- Solving puzzles and mazes.

#### Advantages and Disadvantages:
- **Advantages:** Memory efficient, suitable for sparse graphs.
- **Disadvantages:** Does not necessarily find the shortest path.

### Dijkstra's Algorithm:

#### Definition:
Dijkstra's Algorithm is a popular algorithm for finding the shortest path between nodes in a graph, especially in graphs with non-negative edge weights. It uses a priority queue to always select the vertex with the smallest tentative distance and continually updates the distances to neighboring vertices.

#### Pseudocode:
```plaintext
Dijkstra(graph, start_vertex):
    priority_queue = PriorityQueue()
    distances = {vertex: infinity for vertex in graph}
    distances[start_vertex] = 0

    priority_queue.enqueue((0, start_vertex))

    while priority_queue is not empty:
        current_distance, current_vertex = priority_queue.dequeue()

        if current_distance > distances[current_vertex]:
            continue

        for neighbor, weight in graph.get_neighbors(current_vertex):
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                priority_queue.enqueue((distance, neighbor))
```

#### Key Characteristics:

- Guarantees the shortest path for weighted graphs.
- Uses a priority queue to always select the vertex with the smallest tentative distance.
- Efficient for finding the shortest path in graphs with non-negative edge weights.

#### Real-life Use Cases:
- Shortest path finding in road networks.
- Network routing protocols.

#### Advantages and Disadvantages:
- **Advantages:** Guarantees the shortest path for weighted graphs.
- **Disadvantages:** Inefficient for large graphs.

### Prim's Algorithm:

#### Definition:
Prim's Algorithm is a greedy algorithm that finds a minimum spanning tree for a connected, undirected graph. It starts with an arbitrary node and repeatedly adds the minimum-weight edge that connects a vertex in the growing minimum spanning tree to a vertex outside the tree until all vertices are included.

#### Pseudocode:
```plaintext
Prim(graph):
    min_spanning_tree = set()
    start_vertex = arbitrary_vertex_from(graph)
    priority_queue = PriorityQueue()

    for vertex in graph:
        priority_queue.enqueue((infinity, vertex))

    priority_queue.decrease_key(start_vertex, 0)

    while priority_queue is not empty:
        current_distance, current_vertex = priority_queue.dequeue()

        if current_vertex in min_spanning_tree:
            continue

        min_spanning_tree.add(current_vertex)

        for neighbor, weight in graph.get_neighbors(current_vertex):
            priority_queue.decrease_key(neighbor, weight)
```

#### Key Characteristics:

- Guarantees a minimum spanning tree.
- Uses a priority queue to always select the minimum-weight edge.
- Efficient for sparse graphs.

#### Real-life Use Cases:
- Network design (e.g., connecting cities with minimal cost).
- Cluster analysis.

#### Advantages and Disadvantages:
- **Advantages:** Guarantees a minimum spanning tree.
- **Disadvantages:** Inefficient for dense graphs.

### Kruskal's Algorithm:

#### Definition:
Kruskal's Algorithm is another greedy algorithm for finding a minimum spanning tree in a connected, undirected graph. It starts with an empty set of edges and repeatedly adds the smallest edge that connects two disjoint sets of vertices until all vertices are included.

#### Pseudocode:
```plaintext
Kruskal(graph):
    min_spanning_tree = set()
    edges = sort(graph.get_edges())  // Sort edges by weight in ascending order

    disjoint_set = DisjointSet()

    for vertex in graph:
        disjoint_set.make_set(vertex)

    for edge in edges:
        u, v, weight = edge

        if disjoint_set.find_set(u) != disjoint_set.find_set(v):
            min_spanning_tree.add(edge)
            disjoint_set.union(u, v)
```

#### Key Characteristics:

- Guarantees a minimum spanning tree.
- Uses a disjoint-set data structure to efficiently check for cycles.
- Efficient for sparse graphs.

#### Real-life Use Cases:
- Network design.
- Circuit design.

#### Advantages and Disadvantages:
- **Advantages:** Guarantees a minimum spanning tree.
- **Disadvantages:** Inefficient for dense graphs.

## Complexities

1. **Breadth-First Search (BFS):**
   - Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
   - Space Complexity: O(V) for the queue and O(V) for the visited set, making it O(V) in total.

2. **Depth-First Search (DFS):**
   - Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
   - Space Complexity: O(V) for the recursive call stack and O(V) for the visited set, making it O(V) in total.

3. **Dijkstra's Algorithm:**
   - Time Complexity: O((V + E) * log(V)) with a binary heap or Fibonacci heap for the priority queue implementation. Without a priority queue, the time complexity can go up to O(V^2), which is less efficient.
   - Space Complexity: O(V) for the priority queue and O(V) for the distance array, making it O(V) in total.

4. **Prim's Algorithm:**
   - Time Complexity: O((V + E) * log(V)) with a binary heap or Fibonacci heap for the priority queue implementation. Without a priority queue, the time complexity can go up to O(V^2), which is less efficient.
   - Space Complexity: O(V) for the priority queue and O(V) for the visited set, making it O(V) in total.

5. **Kruskal's Algorithm:**
   - Time Complexity: O(E * log(E)) for sorting the edges plus O(E * alpha(V)) for union-find operations, where alpha(V) is the inverse Ackermann function. In practice, alpha(V) is very slow-growing, and it can be considered as a constant.
   - Space Complexity: O(V) for the disjoint-set data structure and O(E) for the sorted edges, making it O(E + V) in total.

## Conclusion:
Graphs and their algorithms are versatile tools that find applications in various domains. The choice of algorithm depends on the specific problem requirements and characteristics of the graph. Each algorithm has its strengths and weaknesses, making it essential to understand their properties to select the most suitable approach for a given task.
