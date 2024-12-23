C++ Project: The 'Graph' Data Structure

In C++, a graph is a non-linear data structure consisting of nodes and edges. Nodes (also called vertices) are the fundamental units of a graph that represent objects or entities. Edges represent the connections or relationships between vertices. Put simply, graphs are used to model relationships between different entities.

This program will:
- Create an undirected, unweighted graph class with all the standard methods for a data structure of that type.
- Work with a struct data type called Data. This contains an int "id" and a string "information"

The graph is implemented using the adjacency matrix approach. The 2D vector 'adjacencyMatrix' stores the edges between nodes, allowing the graph to grow/ shrink to any size.

Graph Traversal:
Depth-First - The recursive approach to Depth-First Search (DFS) involves calling a function repeatedly until all nodes are visited.
Breadth-First - The program demonstrates BFS (Breadth-First Search) using a queue data structure.