/*
 * Author: Kyle Honke
 * Project: The 'Graph' Data Structure
 * Purpose: Create an undirected, unweighted graph class with all the standard methods for 
 *  a data structure of that type
 * File: graph.h
 */

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "data.h"

using std::cout;
using std::endl;
using std::string;

class Graph {

    public:
    Graph(); // Constructor
    ~Graph(); // Destructor
    bool isEmpty() const; // Checks if the graph is empty
    int getVertexCount() const;
    int getEdgeCount() const;
    bool addNode(int, string*); // Add a new node to the graph
    bool addEdge(int, int); // Add an edge between two nodes
    bool hasEdge(int, int) const; // Check if an edge between nodes exists
    bool removeNode(int); // Remove a node from the graph along with any edges associated with that node
    bool removeEdge(int, int); // Remove only an edge from the graph
    Data getNode(int) const;
    void printGraph() const; // Prints general graph info
    void displayGraph(); // Display graph stats
    void clearGraph(); // Remove all nodes and edges from the graph
    void depthFirstTraversal(int); // Public method to start the depth-first traversal from a given starting vertex
    void breadthFirstTraversal(int); // Public method to start the breadth-first traversal from a given starting vertex

    private:
    // Attributes:
    std::vector<Node> nodes;
    std::vector<std::vector<bool>> adjacencyMatrix;
    // Methods:
    void depthFirstTraversal(int, std::vector<bool>&); // Private overload for recursive depth-first traversal
    void breadthFirstTraversal(int, std::vector<bool>&); // Private overload for breadth-first traversal using a queue
};

#endif /* GRAPH_GRAPH_H */