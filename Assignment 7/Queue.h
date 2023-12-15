// Assignment #7
// Name: Taman Truong
// ASU Email Address: tvtruon1@asu.edu
// Description: The Queue.h header file is meant to assist the Assignment7.cpp file and the Graph.h header file
//              in doing the breadth first search algorithm through the linked list array of linked lists (graph) 
//              of locations, printing the distance array and pi array contents for the graph.

#include <iostream> //to use cout
#include <string> //to use strings
#include <cstdlib> //to use atoi
#include "LinkedList.h"

using namespace std;

// struct locationQueue represents some location information in the queue
struct locationQueue {
    string location;
    int index;
    struct locationQueue* next;
};

// class Queue will contains a linked list of locations in the queue (FIFO - First In First Out)
class Queue {
    public:
    struct locationQueue* head;
    Queue();
    ~Queue();
    void queue(string newLocation, int newIndex);
    void dequeue();
    void printQueue();
};

// Constructor to initialize the queue
Queue::Queue() {
    head = NULL;
}

// Destructor
Queue::~Queue() {
    
}

// Queue
// Description: The queue function queues in a new location at a particular index
void Queue::queue(string newLocation, int newIndex) {
    // Setting up the new location node
    struct locationQueue* newLocationNode = new locationQueue();
    newLocationNode->location = newLocation;
    newLocationNode->index = newIndex;
    newLocationNode->next = NULL;
    struct locationQueue* tempNode = head;

    // If the head does not exist
    if(head == NULL) {
        // Set the head to the new location node
        head = newLocationNode;
    }
    // If the head exists
    else {
        // Loop to the end of the linked list (queue)
        while(tempNode->next != NULL) {
            tempNode = tempNode->next;
        }
        // Set the last node to the new location node
        tempNode->next = newLocationNode;
    }
}

// Dequeue
// Description: The dequeue function removes the first location from the linked list. (FIFO - First In First Out)
void Queue::dequeue() {
    // If the head does not exist
    if(head == NULL) {
        return; // break
    }
    // If the head does not exist
    else {
        // Replace the head with the element next to the head; this will remove the first element from the linked list
        head = head->next;
    }
}

// Print Queue
// Description: The print queue function prints out the queue of locations.
void Queue::printQueue() {
    struct locationQueue* tempNode = head;
    // If the head does not exist
    if(head == NULL) {
        // The queue list is empty
        cout << "This queue is empty!" << endl;
    }
    // If ths head exists
    else {
        // Output the queue in FIFO order
        cout << endl;
        cout << "{";
        while(tempNode != NULL) {
            if(tempNode->next != NULL) {
                cout << tempNode->location << ", ";
            }
            else {
                cout << tempNode->location;
            }
            tempNode = tempNode->next;
        }
        cout << "}";
    }
}