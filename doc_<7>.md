### <p align="center"> INTRODUCTION </p>

This program implements Dijkstra's Algorithm, a greedy approach used to find the shortest path from a single source node to all other nodes in a weighted graph. It works by repeatedly selecting the unvisited node with the smallest known distance and "relaxing" its neighbors.

---

### <p align="center"> DATA STRUCTURE USED </p>

The algorithm utilizes an Adjacency Matrix for graph representation and auxiliary arrays for path tracking:

graph[V][V]: A 2D array where graph[i][j] stores the weight of the edge between node i and j.

dist[V]: An array that stores the minimum distance from the source to each vertex.

visited[V]: A boolean array to keep track of nodes already included in the shortest-path tree.

---

### <p align="center"> FUNCTIONS USED </p>

findNextNode(int dist[], bool visited[])
This function identifies the vertex with the minimum distance value among those not yet processed. It satisfies the greedy property of the algorithm by always picking the "closest" available node.

calculateShortestPath(int graph[V][V], int src)
This is the primary function containing the Dijkstra logic. It initializes distances to infinity, sets the source distance to zero, and iterates through all vertices to update the shortest path records through a process called relaxation.

---

### <p align="center"> WORKING ALGORITHM </p>

- Initialization: Set all dist values to Infinity and visited to false. Set dist[source] = 0.

- Selection: While there are unvisited nodes, pick node u with the smallest dist.

- Visitation: Mark u as visited.

- Relaxation: For every neighbor v of u, if dist[u] + weight(u,v) < dist[v], then update dist[v] with the new lower value.

- Completion: Once all nodes are visited, the dist array contains the final shortest distances.

---

### <p align="center"> SAMPLE OUTPUT </p>
Source Node: 0

Output Table:
Vertex   Distance from Source 0
0                0
1                4
2                12
3                19
4                28
5                16
