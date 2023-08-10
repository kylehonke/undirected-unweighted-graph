/*
 * Author: Kyle Honke
 * Final Project: Graphs
 * Purpose: Create a working undirected unweighted graph class with all the standard methods for 
 *  a data structure of that type 
 * File: main.cpp
 */

#include "main.h"

int main(int argc, char** argv) {

    // seed the rand function
    srand(time(NULL));

    /***********************************
     * MANUALLY TESTING A GRAPH
     **********************************/

    // Create a graph object
    Graph graph;

    // Empty tests
    cout << "\nTesting methods on an empty graph...\n";
    graph.displayGraph();

    // Adding nodes to the graph
    std::string info1 = "Node 1";
    std::string info2 = "Node 2";
    std::string info3 = "Node 3";
    std::string info4 = "Node 4";
    cout << "\nManually testing addNode...\n";
    if (graph.addNode(1, &info1)) {
        cout << "addNode SUCCESS\n";
    } else {
        cout << "addNode FAILED\n";
    }
    if (graph.addNode(2, &info2)) {
        cout << "addNode SUCCESS\n";
    } else {
        cout << "addNode FAILED\n";
    }
    if (graph.addNode(3, &info3)) {
        cout << "addNode SUCCESS\n";
    } else {
        cout << "addNode FAILED\n";
    }
    if (graph.addNode(4, &info4)) {
        cout << "addNode SUCCESS\n";
    } else {
        cout << "addNode FAILED\n";
    }
    cout << "Attempting to add duplicate data...\n";
    if (graph.addNode(4, &info4)) {
        cout << "addNode SUCCESS\n";
    } else {
        cout << "addNode FAILED\n";
    }
    
    // Adding edges between nodes
    cout << "\nManually testing addEdge...\n";
    if (graph.addEdge(1, 2)) {
        cout << "addEdge SUCCESS\n";
    } else {
        cout << "addEdge FAILED\n";
    }
    if (graph.addEdge(1, 3)) {
        cout << "addEdge SUCCESS\n";
    } else {
        cout << "addEdge FAILED\n";
    }
    if (graph.addEdge(2, 4)) {
        cout << "addEdge SUCCESS\n";
    } else {
        cout << "addEdge FAILED\n";
    }
    cout << "Attempting to add duplicate data...\n";
    if (graph.addEdge(2, 4)) {
        cout << "addEdge SUCCESS\n";
    } else {
        cout << "addEdge FAILED\n";
    }

    // Display graph data
    graph.displayGraph();

    // Test getNode method
    cout << "\nManually testing getNode...\n";
    int searchId = 3;
    Data searchData = graph.getNode(searchId);
    if (searchData.id != -1) {
        cout << "Node with ID " << searchId << " found: " << searchData.information << endl;
    } else {
        cout << "Node with ID " << searchId << " not found in the graph." << endl;
    }
    searchId = -2;
    searchData = graph.getNode(searchId);
    if (searchData.id != -1) {
        cout << "Node with ID " << searchId << " found: " << searchData.information << endl;
    } else {
        cout << "Node with ID " << searchId << " not found in the graph." << endl;
    }

    // Test hasEdge method
    cout << "\nManually testing hasEdge...\n";
    cout << "Edge between Node 1 and Node 2 exists? " << (graph.hasEdge(1, 2) ? "Yes" : "No") << endl;
    cout << "Edge between Node 1 and Node 4 exists? " << (graph.hasEdge(1, 4) ? "Yes" : "No") << endl;

    // Display graph data
    graph.displayGraph();

    // Test depth-first traversal
    cout << "\nDepth-First Traversal from Vertex 3:\n";
    graph.depthFirstTraversal(3);
    cout << "\nAttempting Depth-First Traversal from invalid Vertex...\n";
    graph.depthFirstTraversal(-1);

    // Test Breadth-first traversal
    cout << "\nBreadth-First Traversal from Vertex 2:\n";
    graph.breadthFirstTraversal(2);
    cout << "\nAttempting Breadth-First Traversal from invalid Vertex...\n";
    graph.breadthFirstTraversal(-1);

    // Removing a node and testing the removal
    cout << "\nManually testing removeNode...\n";
    cout << "Removing Node 1..." << endl;
    bool removed = graph.removeNode(1);
    if (removed) {
        cout << "Node 1 was successfully removed." << endl;
    } else {
        cout << "Node 1 was not found in the graph." << endl;
    }
    cout << "Removing Node 1..." << endl;
    removed = graph.removeNode(1);
    if (removed) {
        cout << "Node 1 was successfully removed." << endl;
    } else {
        cout << "Node 1 was not found in the graph." << endl;
    }

    // Test hasEdge method
    cout << "\nManually testing hasEdge...\n";
    cout << "Edge between Node 1 and Node 2 exists? " << (graph.hasEdge(1, 2) ? "Yes" : "No") << endl;
    cout << "Edge between Node 1 and Node 4 exists? " << (graph.hasEdge(1, 4) ? "Yes" : "No") << endl;

    // Test depth-first traversal
    cout << "\nDepth-First Traversal from Vertex 3:\n";
    graph.depthFirstTraversal(3);
    cout << "\nAttempting Depth-First Traversal from invalid Vertex...\n";
    graph.depthFirstTraversal(-1);

    // Test Breadth-first traversal
    cout << "\nBreadth-First Traversal from Vertex 2:\n";
    graph.breadthFirstTraversal(2);
    cout << "\nAttempting Breadth-First Traversal from invalid Vertex...\n";
    graph.breadthFirstTraversal(-1);

    // Display graph data
    graph.displayGraph();

    // Removing an edge and testing the removal
    cout << "\nManually testing removeEdge...\n";
    cout << "Removing edge between Node 2 and Node 4..." << endl;
    bool edgeRemoved = graph.removeEdge(2, 4);
    if (edgeRemoved) {
        cout << "Edge between Node 2 and Node 4 was successfully removed." << endl;
    } else {
        cout << "Edge between Node 2 and Node 4 was not found in the graph." << endl;
    }
    cout << "Removing edge between Node 2 and Node 4..." << endl;
    edgeRemoved = graph.removeEdge(2, 4);
    if (edgeRemoved) {
        cout << "Edge between Node 2 and Node 4 was successfully removed." << endl;
    } else {
        cout << "Edge between Node 2 and Node 4 was not found in the graph." << endl;
    }

    // Test hasEdge method
    cout << "\nManually testing hasEdge...\n";
    cout << "Edge between Node 2 and Node 4 exists? " << (graph.hasEdge(2, 4) ? "Yes" : "No") << endl;

    // Display graph data using printGraph
    cout << "\nDisplaying the contents of the graph...\n";
    graph.printGraph();

    // Test getNode method
    cout << "\nManually testing getNode...\n";
    searchId = 3;
    searchData = graph.getNode(searchId);
    if (searchData.id != -1) {
        cout << "Node with ID " << searchId << " found: " << searchData.information << endl;
    } else {
        cout << "Node with ID " << searchId << " not found in the graph." << endl;
    }

    // Clear the graph
    cout << "\nClearing the graph...\n";
    graph.clearGraph();

    // Empty tests
    cout << "\nTesting methods on an empty graph...\n";
    graph.displayGraph();

    /***********************************
     * RANDOM METHOD TESTING
     **********************************/

    cout << "\n\nBEGINNING RANDOM TESTS...\n";
    cout << "================================\n";

    for (int i = 0; i < TESTSIZE; ++i) {
        int operation = (rand() % 10) + 1; // Generate a random number between 0 and 10
        switch (operation) {
            case 0: // Get node
                {
                    int nodeId = rand() % 10 + 1; // Generate a random node ID between 1 and 10
                    Data data = graph.getNode(nodeId);
                    if (data.id != -1) {
                        cout << "Operation " << (i + 1) << ": Found Node " << nodeId << ": " << data.information << endl;
                    } else {
                        cout << "Operation " << (i + 1) << ": Node with ID " << nodeId << " not found in the graph." << endl;
                    }
                }
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5: // Add node
                {
                    int nodeId = rand() % 10 + 1; // Generate a random node ID between 1 and 10
                    string nodeInfo = "Node " + std::to_string(nodeId);
                    if (graph.addNode(nodeId, &nodeInfo)) {
                        cout << "Operation " << (i + 1) << ": Added Node " << nodeId << endl;
                    } else {
                        cout << "Operation " << (i + 1) << ": Failed to add Node " << nodeId << " (duplicate data or invalid ID)" << endl;
                    }
                }
                break;
            case 6:
            case 7:
            case 8: // Add edge
                {
                    int nodeId1 = rand() % 10 + 1; // Generate a random node ID between 1 and 10
                    int nodeId2 = rand() % 10 + 1; // Generate another random node ID between 1 and 10
                    if (graph.addEdge(nodeId1, nodeId2)) {
                        cout << "Operation " << (i + 1) << ": Added Edge between Node " << nodeId1 << " and Node " << nodeId2 << endl;
                    } else {
                        cout << "Operation " << (i + 1) << ": Failed to add Edge between Node " << nodeId1 << " and Node " << nodeId2 << " (invalid node IDs or duplicate edge)" << endl;
                    }
                }
                break;
            case 9: // Remove node
                {
                    int nodeId = rand() % 10 + 1; // Generate a random node ID between 1 and 10
                    if (graph.removeNode(nodeId)) {
                        cout << "Operation " << (i + 1) << ": Removed Node " << nodeId << endl;
                    } else {
                        cout << "Operation " << (i + 1) << ": Node " << nodeId << " not found in the graph" << endl;
                    }
                }
                break;
            case 10: // Remove edge
                {
                    int nodeId1 = rand() % 10 + 1; // Generate a random node ID between 1 and 10
                    int nodeId2 = rand() % 10 + 1; // Generate another random node ID between 1 and 10
                    if (graph.removeEdge(nodeId1, nodeId2)) {
                        cout << "Operation " << (i + 1) << ": Removed Edge between Node " << nodeId1 << " and Node " << nodeId2 << endl;
                    } else {
                        cout << "Operation " << (i + 1) << ": Edge between Node " << nodeId1 << " and Node " << nodeId2 << " not found in the graph" << endl;
                    }
                }
                break;
            default:
                break;
        }
    }
    // Display graph data
    graph.displayGraph();

    // Traversals using a random number as an entry ID
    // (typically provides a great traversal, otherwise try running the program again to get a better int)
    cout << "\nRandom int Traversal:\n";
    int startId = rand() % 10 + 1; // Generate a random starting node ID between 1 and 10
    cout << "Traversal from Vertex " << startId << ":\n";
    cout << "Depth-First...\n";
    graph.depthFirstTraversal(startId);
    cout << "Breadth-First...\n";
    graph.breadthFirstTraversal(startId);
    startId = rand() % 10 + 1; // Generate a second random starting node ID between 1 and 10
    cout << "Traversal from Vertex " << startId << ":\n";
    cout << "Depth-First...\n";
    graph.depthFirstTraversal(startId);
    cout << "Breadth-First...\n";
    graph.breadthFirstTraversal(startId);

    return 0;
}