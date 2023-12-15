// Assignment #8
// Name: Taman Truong
// ASU Email Address: tvtruon1@asu.edu
// Description: The LinkedList.h header file is meant to assist the Assignment8.cpp file and the Graph.h
//              header file to add and print locations in a graph of locations.

#include <iostream> // to use cout
#include <iomanip> // to format output
#include <string> // to use strings

using namespace std;

// struct Publication represents some publication information
struct Publication {
    string publicationID;
    string year;
    int index;
    int weight;
    struct Publication* next;
};

// class LinkedList will contains a linked list of publications
class LinkedList {
    public:
    struct Publication* head;
    int linkedListSize;
    LinkedList();
    ~LinkedList();
    void insertNode(string newPublicationID1, string newPublicationID2, int newIndex);
    int numOfNodes();
};

// Constructor to initialize the linked list
LinkedList::LinkedList() {
    head = NULL;
    this->linkedListSize = 0;
}

// Destructor
// Description: The destructor takes out every location node from the linked list out of the linked list.
LinkedList::~LinkedList() {
    struct Publication* tempNode = this->head;
    struct Publication* deleteNode = this->head;
    // While traversing through the linked list,
    while(tempNode != NULL) {
        deleteNode = tempNode; // assign the deleteNode to the temporary node, pointing to the first element
        tempNode = tempNode->next; // move onto the next node
        free(deleteNode); // delete the node at deleteNode
    }
    free(tempNode); // After traversing through the linked list, delete the temporary node
}

// Insert Node
// Description: 
void LinkedList::insertNode(string newPublicationID, string newYear, int newIndex) {
    // Setting up the new location node
    struct Publication* newPublicationEdge = new Publication;
    newPublicationEdge->publicationID = newPublicationID;
    newPublicationEdge->year = newYear;
    newPublicationEdge->index = newIndex;
    newPublicationEdge->weight = 1;
    struct Publication* lastEdge = head;
    // If the head does not exist
    if(head == NULL) {
        // set the head to the new location node
        head = newPublicationEdge;
        this->linkedListSize = this->linkedListSize + 1;
    }
    // If the head exists
    else {
        // Loop through the linked list to the end of the linked list
        while(lastEdge->next != NULL) {
            lastEdge = lastEdge->next;
        }
        // Set the last node to the new location node
        lastEdge->next = newPublicationEdge;
        this->linkedListSize = this->linkedListSize + 1;
    }
}

int LinkedList::numOfNodes() {
    struct Publication* tempNode = new Publication;
    int countNodes = 0;
    while(tempNode != NULL) {
        countNodes++;
        tempNode = tempNode->next;
    }
    return countNodes;
}