// Assignment #8
// Name: Taman Truong
// ASU Email Address: tvtruon1@asu.edu
// Description: The Graph.h header file is meant to assist the Assignment8.cpp file in setting up the starting
//              and ending destinations through setting up the nodes (locations) and connecting the nodes (edges).

#include <iostream> //to use cout
#include <string> //to use strings
#include <cstdlib> //to use atoi
#include "LinkedList.h"

using namespace std;

// class Graph will contains an linked list array of linked lists
class Graph {
    public:
    LinkedList** adjacencyList;
    int adjacencyListSize;
    Graph(int newGraphSize);
    ~Graph();
    bool checkValidEdge(string publicationID1, string publicationID2);
    int numEdgesAtIndex(int index);
    void insertNode(string publicationID, string year, int index);
    void insertEdge(string nextPublicationID, string nextYear, int index1, int index2);
    int getIndex(string nextPublicationID);
    void outDegree(int numVertices, int numEdges);
    void FloydWarshall();
    void DepthFirstSearch();
    void DepthFirstSearchVisit();
    void stronglyConnectedComponents();
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
    for (int i = 0; i < adjacencyListSize; i++) {
        adjacencyList[i]->~LinkedList();
    }
    delete[] adjacencyList;
}

int Graph::numEdgesAtIndex(int index) {
    adjacencyList[index]->numOfNodes();
}

bool Graph::checkValidEdge(string publicationID1, string publicationID2) {
    int count = 0;
    std:string checkPublicationID;

    for (int i = 0; i < adjacencyListSize; i++) {
        checkPublicationID = (adjacencyList[i]->head)->publicationID;
        if((checkPublicationID.compare(publicationID1) == 0) || (checkPublicationID.compare(publicationID2) == 0)) {
            count++;
        }
    }

    if (count == 2) {
        return true;
    }
    else {
        return false;
    }
}

// Insert Node
// Description: The insert node function insert a publication into the adjacency list.
void Graph::insertNode(string publicationID, string year, int index) {
    adjacencyList[index]->insertNode(publicationID, year, index);
}

// Insert Edge
// Description: 
void Graph::insertEdge(string nextPublicationID, string nextYear, int index1, int index2) {
    adjacencyList[index1]->insertNode(nextPublicationID, nextYear, index2);
}

int Graph::getIndex(string nextPublicationID) {
    for (int i = 0; i < adjacencyListSize; i++) {
        if(((adjacencyList[i]->head)->publicationID).compare(nextPublicationID) == 0) {
            return i;
        }
    }
    return -1;
}

void Graph::outDegree(int numVertices, int numEdges) {
    cout << std::fixed << std::setprecision(3) << "The graph G has average out-degree " << numVertices << "/" << numEdges << " = " << (float) numVertices/numEdges << ".\n";
    cout << "The out-degree distribution is:\n" << endl;
    cout << "Out-degree: Number of vertices\n" << endl;
}

void Graph::FloydWarshall() {
    for(int k = 0; k < adjacencyListSize; k++) {
        for(int i = 0; i < adjacencyListSize; i++) {
            for(int j = 0; j < adjacencyListSize; j++) {
                
            }
        }
    }
}

void Graph::DepthFirstSearch() {

}

void Graph::DepthFirstSearchVisit() {

}

void Graph::stronglyConnectedComponents() {

}