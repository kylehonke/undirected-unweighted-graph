/*
 * Author: Kyle Honke
 * Final Project: Graphs
 * Purpose: Create a working undirected unweighted graph class with all the standard methods for 
 *  a data structure of that type.
 * File: data.h
 */

#ifndef GRAPH_DATA_H
#define GRAPH_DATA_H

#include <string>
using std::string;

struct Data {
    int id;
    string information;
};

struct Node {
    Data data;
};

#endif /* GRAPH_DATA_H */