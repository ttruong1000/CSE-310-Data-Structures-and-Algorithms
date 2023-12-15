// Assignment #7
// Name: Taman Truong
// ASU Email Address: tvtruon1@asu.edu
// Description: The LinkedList.h header file is meant to assist the Assignment7.cpp file and the Graph.h and Queue.h
//              header files to add and print locations in a graph and queue of locations.

#include <iostream> // to use cout
#include <iomanip> // to format output
#include <string> // to use strings

using namespace std;

// struct Location represents some location information
struct Location {
    string location;
    int index;
    struct Location* next;
};

// class LinkedList will contains a linked list of locations
class LinkedList {
    public:
    struct Location* head;
    int linkedListSize;
    LinkedList();
    ~LinkedList();
    void addLocationtoBack(string newLocation, int newIndex);
    void printList();
};

// Constructor to initialize the linked list
LinkedList::LinkedList() {
    head = NULL;
    this->linkedListSize = 0;
}

// Destructor
// Description: The destructor takes out every location node from the linked list out of the linked list.
LinkedList::~LinkedList() {
    struct Location* tempNode = this->head;
    struct Location* deleteNode = this->head;
    // While traversing through the linked list,
    while(tempNode != NULL) {
        deleteNode = tempNode; // assign the deleteNode to the temporary node, pointing to the first element
        tempNode = tempNode->next; // move onto the next node
        free(deleteNode); // delete the node at deleteNode
    }
    free(tempNode); // After traversing through the linked list, delete the temporary node
}

// Add Location to Back Method
// Description: The add location to back method adds a location into the linked list to the back of the linked list.
void LinkedList::addLocationtoBack(string newLocation, int newIndex) {
    // Setting up the new location node
    struct Location* newLocationNode = new Location;
    newLocationNode->location = newLocation;
    newLocationNode->index = newIndex;
    struct Location* lastNode = head;
    // If the head does not exist
    if(head == NULL) {
        // set the head to the new location node
        head = newLocationNode;
        this->linkedListSize = this->linkedListSize + 1;
    }
    // If the head exists
    else {
        // Loop through the linked list to the end of the linked list
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        // Set the last node to the new location node
        lastNode->next = newLocationNode;
        this->linkedListSize = this->linkedListSize + 1;
    }
}

// Print List Method
// Description: The print list method prints the locations to the console. If the list is empty, the console will print that the list is empty.
void LinkedList::printList() {
    struct Location* tempNode = head;
    // If there is at least one element in the linked list,
    if (tempNode != NULL) {
        // While traversing through the linked list,
        while(tempNode != NULL) {
            // If the node traversed is the first node,
            if(tempNode == head) {
                // Print out initial location 'from'
                cout << "From: " << tempNode->location << endl;
            }
            // If the node traversed is not the first node,
            else {
                // Print out possible destinations 'to'
                cout << "To: " << tempNode->location << endl;
            }
            // Move onto the next node
            tempNode = tempNode->next;
        }
        cout << endl;
    }
    // If there are no elements in the linked list,
    else {
        // Print that the list is empty.
        cout << "The list is empty!\n" << endl;
    }
}