/*
 * Author: Kyle Honke
 * Final Project: Graphs
 * Purpose: Create a working undirected unweighted graph class with all the standard methods for 
 *  a data structure of that type.
 * File: graph.cpp
 */

#include "graph.h"

/************************************
 * Constructor & Destructor
 ************************************/

Graph::Graph() {
    // No custom initialization needed as all data members will be initialized automatically.
}

Graph::~Graph() {
    clearGraph();
}

/************************************
 * Public methods & attributes
 ************************************/

bool Graph::isEmpty() const {
    return nodes.empty();
}

int Graph::getVertexCount() const {
    return nodes.size();
}

int Graph::getEdgeCount() const {
    int count = 0;
    for (int i = 0; i < nodes.size(); ++i) {
        for (int j = i + 1; j < nodes.size(); ++j) {
            if (adjacencyMatrix[i][j]) {
                count++;
            }
        }
    }
    return count;
}

// Display graph stats
void Graph::displayGraph() {
    cout << "\nDISPLAY GRAPH:\n";
    cout << "=================\n";
    printGraph();
    cout << "Graph is " << (isEmpty() ? "EMPTY" : "NOT empty") << endl;
    cout << "Vertex count: " << getVertexCount() << endl;
    cout << "Edge count: " << getEdgeCount() << endl;
}

// Add a new node to the graph
bool Graph::addNode(int id, string *information) {
    bool added = true; // Assume node can be added by default
    // Check if a node data is valid
    for (const Node& node : nodes) {
        if (node.data.id == id) {
            added = false; // Node with the same id already exists
        }
        if (id<0) {
            added = false; // Invalid data
        }
    }
    if (added) {
        Data data = {id, *information};
        nodes.push_back({data});
        // Add a new row and column to the adjacency matrix
        for (int i = 0; i < nodes.size() - 1; ++i) {
            adjacencyMatrix[i].push_back(false);
        }
        adjacencyMatrix.push_back(std::vector<bool>(nodes.size(), false));
    }
    return added;
}

// Add an edge between two nodes
bool Graph::addEdge(int id1, int id2) {
    int index1 = -1;
    int index2 = -1;
    bool added = false; // Assume edge cannot be added by default
    for (int i = 0; i < nodes.size() && (index1 == -1 || index2 == -1); ++i) {
        if (nodes[i].data.id == id1) {
            index1 = i;
        }
        if (nodes[i].data.id == id2) {
            index2 = i;
        }
    }
    if (index1 != -1 && index2 != -1) {
        // Check if the edge already exists
        if (!adjacencyMatrix[index1][index2]) {
            adjacencyMatrix[index1][index2] = true;
            adjacencyMatrix[index2][index1] = true;
            added = true; // Edge added successfully
        }
    }
    if (index1 == index2) { // Do not add edge between a value and itself
        added = false;
    }
    return added;
}

// Check if an edge between nodes exists
bool Graph::hasEdge(int id1, int id2) const {
    int index1 = -1;
    int index2 = -1;
    bool hasEdge = false; // Assume edge does not exist by default
    for (int i = 0; i < nodes.size() && (index1 == -1 || index2 == -1); ++i) {
        if (nodes[i].data.id == id1) {
            index1 = i;
        }
        if (nodes[i].data.id == id2) {
            index2 = i;
        }
    }
    if (index1 != -1 && index2 != -1) {
        hasEdge = adjacencyMatrix[index1][index2];
    }
    return hasEdge;
}

// Remove a node from the graph along with any edges associated with that node
bool Graph::removeNode(int id) {
    int index = -1;
    bool removed = false; // Assume node is not removed by default
    // Find the index of the node with the given id
    for (int i = 0; i < nodes.size(); ++i) {
        if (nodes[i].data.id == id) {
            index = i;
            nodes.erase(nodes.begin() + index);
            for (int j = 0; j < adjacencyMatrix.size(); ++j) {
                adjacencyMatrix[j].erase(adjacencyMatrix[j].begin() + index);
            }
            adjacencyMatrix.erase(adjacencyMatrix.begin() + index);
            removed = true; // Node removed successfully
        }
    }
    return removed;
}

// Remove only an edge from the graph
bool Graph::removeEdge(int id1, int id2) {
    int index1 = -1;
    int index2 = -1;
    bool removed = false; // Assume edge is not removed by default
    // Find the indices of the nodes with the given ids
    for (int i = 0; i < nodes.size(); ++i) {
        if (nodes[i].data.id == id1) {
            index1 = i;
        }
        if (nodes[i].data.id == id2) {
            index2 = i;
        }
    }
    // Check if both nodes exist in the graph
    if (index1 != -1 && index2 != -1) {
        // Check if the edge exists between the nodes
        if (adjacencyMatrix[index1][index2]) {
            adjacencyMatrix[index1][index2] = false;
            adjacencyMatrix[index2][index1] = false;
            removed = true; // Edge removed successfully
        }
    }
    return removed;
}

// Prints general graph info
void Graph::printGraph() const {
    cout << "Data:" << endl;
    // Print each vertex along with its associated data
    for (const Node& node : nodes) {
        cout << "Vertex " << node.data.id << ": " << node.data.information << endl;
        // Print edges of the vertex
        cout << "   Edges: ";
        bool foundVertex = false;
        int i = 0;
        while (!foundVertex && i < nodes.size()) {
            if (nodes[i].data.id == node.data.id) {
                foundVertex = true;
                for (int j = 0; j < nodes.size(); ++j) {
                    if (adjacencyMatrix[i][j]) {
                        cout << nodes[j].data.id << " ";
                    }
                }
            }
            i++;
        }
        if (!foundVertex) {
            cout << "Vertex not found in the graph.";
        }
        cout << endl;
    }
}

// Set the default value to (-1, "") & update it if we find the node with the matching ID
Data Graph::getNode(int id) const {
    Data foundData = { -1, "" };
    for (const Node& node : nodes) {
        if (node.data.id == id) {
            foundData = node.data;
        }
    }
    return foundData;
}

// Remove all nodes and edges from the graph
void Graph::clearGraph() {
    nodes.clear();
    adjacencyMatrix.clear();
}

/*
 * The following public methods call private overloads:
 */

// Start the depth-first traversal from a given starting vertex
void Graph::depthFirstTraversal(int startId) {
    if (startId < 1 || startId > getVertexCount()) {
        cout << "Invalid starting vertex ID: " << startId << endl;
        return;
    }
    std::vector<bool> visited(getVertexCount(), false);
    depthFirstTraversal(startId, visited);
}

// Start the breadth-first traversal from a given starting vertex
void Graph::breadthFirstTraversal(int startId) {
    if (startId < 1 || startId > getVertexCount()) {
        cout << "Invalid starting vertex ID: " << startId << endl;
        return;
    }
    std::vector<bool> visited(getVertexCount(), false);
    breadthFirstTraversal(startId, visited);
}

/************************************
 * Private methods & attributes
 ************************************/

// Overload for recursive depth-first traversal
void Graph::depthFirstTraversal(int id, std::vector<bool>& visited) {
    visited[id - 1] = true; // Mark the current vertex as visited
    // Print the current vertex
    cout << "Visited vertex " << id << endl;
    // Traverse all adjacent vertices (based on the adjacency matrix)
    for (int i = 0; i < getVertexCount(); ++i) {
        if (adjacencyMatrix[id - 1][i] && !visited[i]) {
            depthFirstTraversal(i + 1, visited);
        }
    }
}

// Overload for breadth-first traversal using a queue
void Graph::breadthFirstTraversal(int id, std::vector<bool>& visited) {
    std::queue<int> bfsQueue;
    bfsQueue.push(id);
    visited[id - 1] = true;
    while (!bfsQueue.empty()) {
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();
        // Process the current vertex
        cout << "Visited vertex " << currentVertex << endl;
        for (int i = 0; i < getVertexCount(); ++i) {
            if (adjacencyMatrix[currentVertex - 1][i] && !visited[i]) {
                bfsQueue.push(i + 1);
                visited[i] = true;
            }
        }
    }
}