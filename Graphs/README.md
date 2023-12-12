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

### Depth-First Search (DFS):

#### Pseudocode:
```plaintext
DFS(graph, start_vertex, visited):
    if start_vertex not in visited:
        visit(start_vertex)
        visited.add(start_vertex)

        for neighbor in graph.get_neighbors(start_vertex):
            DFS(graph, neighbor, visited)
```

#### Real-life Use Cases:
- Topological sorting.
- Solving puzzles and mazes.

#### Advantages and Disadvantages:
- **Advantages:** Memory efficient, suitable for sparse graphs.
- **Disadvantages:** Does not necessarily find the shortest path.

### Dijkstra's Algorithm:

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

#### Real-life Use Cases:
- Shortest path finding in road networks.
- Network routing protocols.

#### Advantages and Disadvantages:
- **Advantages:** Guarantees the shortest path for weighted graphs.
- **Disadvantages:** Inefficient for large graphs.

### Prim's Algorithm:

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

#### Real-life Use Cases:
- Network design (e.g., connecting cities with minimal cost).
- Cluster analysis.

#### Advantages and Disadvantages:
- **Advantages:** Guarantees a minimum spanning tree.
- **Disadvantages:** Inefficient for dense graphs.

### Kruskal's Algorithm:

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

#### Real-life Use Cases:
- Network design.
- Circuit design.

#### Advantages and Disadvantages:
- **Advantages:** Guarantees a minimum spanning tree.
- **Disadvantages:** Inefficient for dense graphs.

## Conclusion:
Graphs and their algorithms are versatile tools that find applications in various domains. The choice of algorithm depends on the specific problem requirements and characteristics of the graph. Each algorithm has its strengths and weaknesses, making it essential to understand their properties to select the most suitable approach for a given task.
