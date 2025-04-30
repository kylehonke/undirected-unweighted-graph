Graph Data Structure (C++)
----------------------------

A graph is a non-linear data structure consisting of nodes and edges. Nodes (also called vertices) are the fundamental units of a graph that represent objects or entities. Edges represent the connections or relationships between vertices. Put simply, graphs are used to model relationships between different entities.

Undirected: Edges have no direction, meaning the connection between vertices A and B is bidirectional (if A is connected to B, then B is connected to A).
Unweighted: Edges have no weight or value associated with them, meaning they do not have a specific numerical value that represents their importance or significance.

### This program will:
- Create an undirected, unweighted graph class with all the standard methods for a data structure of that type.
- Implement the graph using the adjacency matrix approach. The 2D vector 'adjacencyMatrix' stores the edges between nodes, allowing the graph to grow or shrink to any size.
- Work with a struct data type called Data. This contains an int "id" and a string "information".
- Implement graph traversal algorithms using both Depth-First Search (DFS) and Breadth-First Search (BFS).

### Graph Traversal
- Depth-First: This program demonstrates DFS through the use of recursion. This recursive approach involves calling a function repeatedly until all nodes are visited.
- Breadth-First: The program demonstrates BFS using a queue data structure. This involves adding nodes to a queue and removing them in a first-in-first-out (FIFO) manner.

### Usage
Prerequisites: C++11 or later, g++ compiler
Compile: g++ -I ./ *.cpp
Run: Run the executable file.