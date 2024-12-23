/*
 * Author: Kyle Honke
 * Project: The Graph Data Structure
 * Purpose: 'Data' is a struct which stores information in a vertex (node) 
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