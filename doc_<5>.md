### <p align="center"> INTRODUCTION </p>

This program demonstrates how to represent an Undirected Graph using an Adjacency Matrix. It further implements two fundamental traversal algorithms: Breadth-First Search (BFS) and Depth-First Search (DFS) to visit all nodes in the graph systematically.

---

### <p align="center"> DATA STRUCTURE USED </p>

The implementation uses three primary structures:

Adjacency Matrix: A 2D array where matrix[i][j] = 1 indicates a connection between node i and j.

Stack: Used for DFS to manage the "depth-first" pathing.

Queue: Used for BFS to explore neighbors "level-by-level."

---

### <p align="center"> FUNCTIONS USED </p>

push() and pop()
These functions manage the NodeStack structure. push adds a vertex to the stack for exploration, while pop retrieves the most recent vertex to continue the depth-wise search.

enqueue() and dequeue()
These functions manage the NodeQueue structure. enqueue adds discovered neighbors to the end of the queue, and dequeue removes the front element to explore its immediate adjacent nodes.

performBFS(int adj[][], int n, int start)
Starts from a source node, marks it as visited, and uses a queue to visit all neighbors at the current distance before moving to the next level.

performDFS(int adj[][], int n, int start)
Uses a stack to dive as deep as possible into a branch before backtracking. It ensures each node is visited exactly once using a visited array.

---

### <p align="center"> WORKING ALGORITHM </p>

BFS (Breadth-First):

Initialize a queue and a visited array.

Enqueue the start node and mark it visited.

While the queue isn't empty: dequeue node U, print it, and enqueue all unvisited neighbors of U.

DFS (Depth-First):

Initialize a stack and a visited array.

Push the start node.

While the stack isn't empty: pop node U, if not visited: mark it, print it, and push all its unvisited neighbors.

---

### <p align="center"> SAMPLE OUTPUT </p>

For a Square Graph (0-1, 0-2, 1-3, 2-3):

BFS Traversal: 0 1 2 3

DFS Traversal: 0 1 3 2
