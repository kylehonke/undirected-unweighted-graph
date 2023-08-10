/*
 * Author: Kyle Honke
 * Final Project: Graphs
 * Purpose: Create a working undirected unweighted graph class with all the standard methods for 
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
    Graph();
    ~Graph();
    bool isEmpty() const;
    int getVertexCount() const;
    int getEdgeCount() const;
    bool addNode(int, string*);
    bool addEdge(int, int);
    bool hasEdge(int, int) const; // "exists"
    bool removeNode(int);
    bool removeEdge(int, int);
    Data getNode(int) const;
    void printGraph() const;
    void displayGraph();
    void clearGraph();
    // Public method to start the depth-first traversal from a given starting vertex
    void depthFirstTraversal(int);
    // Public method to start the breadth-first traversal from a given starting vertex
    void breadthFirstTraversal(int);

    private:
    // Attributes:
    std::vector<Node> nodes;
    std::vector<std::vector<bool>> adjacencyMatrix;
    // Methods:
    // Private overload for recursive depth-first traversal
    void depthFirstTraversal(int, std::vector<bool>&);
    // Private overload for breadth-first traversal using a queue
    void breadthFirstTraversal(int, std::vector<bool>&);
};

#endif /* GRAPH_GRAPH_H */