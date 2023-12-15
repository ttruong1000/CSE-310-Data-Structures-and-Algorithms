// Assignment #7
// Name: Taman Truong
// ASU Email Address: tvtruon1@asu.edu
// Description: The Assignment7.cpp file is the driver file that inputs the number of nodes in the graph, 
//              the locations to be put on the graph as nodes, the number of edges in the graph, and the 
//              pairs of locations (bi-directional edges) that make up the shape and structure of the location
//              graph.

#include <iostream> //to use cin and cout
#include <string> //to use strings
#include <cstdlib> //to use string functions
#include "Graph.h"

using namespace std;

int main() {
    // initialize all variables for user input and output
    int numberOfNodes;
    int pairsOfLocations;
    string initialLocation;
    string pairOfLocations;
    string leftPairOfLocations;
    string rightPairOfLocations;

    // Input the number of nodes in the graph
    cin >> numberOfNodes;
    std::cin.ignore();
    // Initialize the graph (adjacency list) with the corresponding number of nodes
    Graph* newAdjacencyList = new Graph(numberOfNodes);
    // For the number of nodes (locations) to be inputted
    for(int i = 0; i < numberOfNodes; i++) {
        // Get the location
        std::getline(std::cin, initialLocation);
        // Store each location into each linked list array
        newAdjacencyList->insertNode(i, initialLocation);
    }
    // Input the number of bi-directional edges in the graph
    cin >> pairsOfLocations;
    std::cin.ignore();
    // For the number of bi-directional edges (pairs of locations) in the graph
    for(int i = 0; i < pairsOfLocations; i++) {
        // Get the pair of locations (location1,location2)
        std::getline(std::cin, pairOfLocations);
        // Parse the input via the delimiter ','
        leftPairOfLocations = pairOfLocations.substr(0, pairOfLocations.find(","));
        pairOfLocations.erase(0, pairOfLocations.find(",") + 1);
        rightPairOfLocations = pairOfLocations;
        // Store each edge into the corresponding linked list of locations (adjacency list)
        newAdjacencyList->insertEdge(leftPairOfLocations, rightPairOfLocations);
    }
    // Print out the graph content
    cout << "The Graph Content:" << endl;
    cout << "-------------------" << endl;
    newAdjacencyList->printGraph();
    // Print out the breadth first search processing, pi array, distance array
    newAdjacencyList->breadthFirstSearch();
    return 0;
}