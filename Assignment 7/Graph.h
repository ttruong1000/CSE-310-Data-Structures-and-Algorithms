// Assignment #7
// Name: Taman Truong
// ASU Email Address: tvtruon1@asu.edu
// Description: The Graph.h header file is meant to assist the Assignment7.cpp file in setting up the starting
//              and ending destinations through setting up the nodes (locations) and connecting the nodes (edges).

#include <iostream> //to use cout
#include <string> //to use strings
#include <cstdlib> //to use atoi
#include "Queue.h"

using namespace std;

// class Graph will contains an linked list array of linked lists
class Graph {
    public:
    LinkedList** adjacencyList;
    Queue* newQueue;
    int adjacencyListSize;
    Graph(int newGraphSize);
    ~Graph();
    void insertNode(int index, string location);
    void insertEdge(string startingLocation, string endingLocation);
    void printGraph();
    void breadthFirstSearch();
};

// Constructor to initialize the graph
Graph::Graph(int newGraphSize) {
    adjacencyList = new LinkedList*[newGraphSize];
    adjacencyListSize = newGraphSize;
    for (int i = 0; i < adjacencyListSize; i++) {
        adjacencyList[i] = new LinkedList();
    }
}

// Destructor
Graph::~Graph() {
    
}

// Insert Node
// Description: The insert node function insert a location into the adjacency list.
void Graph::insertNode(int index, string location) {
    adjacencyList[index]->addLocationtoBack(location, index);
}

// Insert Edge
// Description: The insert edge function inserts the starting and ending locations at their respective indices in the adjacency list (bi-directional edges).
void Graph::insertEdge(string startingLocation, string endingLocation) {
    int startingIndex = 0;
    int endingIndex = 0;
    // For each linked list in the adjacency list
    for(int i = 0; i < adjacencyListSize; i++) {
        // If the starting location is the same as what it is in the adjacency list
        if(((adjacencyList[i]->head)->location).compare(startingLocation) == 0) {
            // Set the starting index to what it is in the adjacency list
            startingIndex = (adjacencyList[i]->head)->index;
        }
        // If the ending location is the same as what it is in the adjacency list
        if(((adjacencyList[i]->head)->location).compare(endingLocation) == 0) {
            // Set the ending index to what it is in the adjacency list
            endingIndex = (adjacencyList[i]->head)->index;
        }
    }
    // Set the adjacency list at the starting index to its corresponding ending location at its ending index
    adjacencyList[startingIndex]->addLocationtoBack(endingLocation, endingIndex);
    // Set the adjacency list at the ending index to its corresponding starting location at its starting index
    adjacencyList[endingIndex]->addLocationtoBack(startingLocation, startingIndex);
}

// Print Graph
// Description: The print graph function prints out the graph, from the starting location ('from') to all possible ending locations ('to').
void Graph::printGraph() {
    // For each linked list in the adjacency list
    for(int i = 0; i < adjacencyListSize; i++) {
        // If there is nothing in the linked list array at that particlar index
        if(adjacencyList[i]->head == NULL) {
            // The linked list at that index is empty
            cout << "The list is empty!\n" << endl;
        }
        // If there is something in the linked list array at that particular index
        else {
            // Print the locations adjacent to the head associated with the linked list array at that particular index
            adjacencyList[i]->printList();
        }
    }
}

// Breadth First Search
// Description: The breadth first search function does the breadth first search (BFS) algorithm on the location graph.
void Graph::breadthFirstSearch() {
    // Set up the color array inputs
    string colorWhite = "white";
    string colorGray = "gray";
    string colorBlack = "black";
    // Set up the color array
    string colorArray[adjacencyListSize];
    // Set up the pi array
    string piArray[adjacencyListSize];
    // Set up the distance array
    int distanceArray[adjacencyListSize];

    cout << "BFS being performed..." << endl;
    cout << "The Queue Content:" << endl;

    // For each node U in the adjacency list
    for(int nodeU = 0; nodeU < adjacencyListSize; nodeU++) {
        // Set all nodes in the color, pi, and distance array to their default values
        colorArray[nodeU] = colorWhite;
        piArray[nodeU] = "none";
        distanceArray[nodeU] = 0;
    }

    // Create a queue to do BFS (breadth first search algorithm)
    newQueue = new Queue;

    // For each node S in the adjacency list
    for(int nodeS = 0; nodeS < adjacencyListSize; nodeS++) {
        // If the node is white (not visited)
        if(colorArray[nodeS].compare(colorWhite) == 0) {
            // Node is now gray (visited once)
            colorArray[nodeS] = colorGray;
            distanceArray[nodeS] = 0;
            // Add this node to the queue
            newQueue->queue((adjacencyList[nodeS]->head)->location, (adjacencyList[nodeS]->head)->index);
            // While the queue is not empty
            while(newQueue->head != NULL) {
                // Print the current queue contents
                newQueue->printQueue();
                // Find the location of the first node in the queue
                int nodeU = (newQueue->head)->index;
                Location* tempNode = adjacencyList[nodeU]->head; 
                // While the linked list is not empty
                while(tempNode != NULL) {
                    // Find the current index of the node in the queue in the adjacency list
                    int currentIndex = tempNode->index;
                    // If the node is white (not visited)
                    if(colorWhite.compare(colorArray[currentIndex]) == 0) {
                        // Node is now gray (visited once)
                        colorArray[currentIndex] = colorGray;
                        // pi-array is the array that outputs the node that the current node is discovered from
                        piArray[currentIndex] = (adjacencyList[nodeU]->head)->location;
                        // distance array is the shortest distance to get from the starting node to the current node
                        distanceArray[currentIndex] = distanceArray[nodeU] + 1;
                        // add this current node to the queue
                        newQueue->queue(tempNode->location, tempNode->index);
                    }
                    // Move to the next node
                    tempNode = tempNode->next;
                }
                // Dequeue the first node
                newQueue->dequeue();
                // Node is now black (every possible location from this node is visited/discovered)
                colorArray[nodeU] = colorBlack;
            }
        }
    }
    cout << endl;
    cout << endl;
    // Print out the pi array contents
    cout << "The array pi content:" << endl;
    for(int i = 0; i < adjacencyListSize; i++) {
        cout << "pi[" << (adjacencyList[i]->head)->location << "]=" << piArray[i] << endl;
    }
    cout << endl;
    // Print out the distance array contents
    cout << "The array distance content:" << endl;
    for(int i = 0; i < adjacencyListSize; i++) {
        cout << "distance[" << (adjacencyList[i]->head)->location << "]=" << distanceArray[i] << endl;
    }
}