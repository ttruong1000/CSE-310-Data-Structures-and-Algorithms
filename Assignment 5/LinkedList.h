////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Assignment #5
// Name: Taman Truong
// ASU Email Address: tvtruon1@asu.edu
// Description: The LinkedList.h header file is meant to assist the HashTable.h and Assignment5.cpp file in forming a linked 
//              list of publications, with the ISBN, publication title, and publisher name. The header file contains pertinent 
//              structs, class declarations, constructors, destructors, and helper methods (addPublicationtoFront, 
//              removePublication, searchPublication, and printList) to construct and destruct the linked list of publications.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> // to use cout
#include <iomanip> // to format output
#include <string> // to use strings

using namespace std;

// struct Publication represents some publication information
struct Publication {
    string codeISBN;
    string publicationTitle;
    string publisherName;
    struct Publication* next;
};

// class LinkedList will contains a linked list of publications
class LinkedList {
    public:
    struct Publication* head;
    int linkedListSize;
    LinkedList();
    ~LinkedList();
    void addPublicationtoFront(string codeISBN, string bookTitle, string publisherName);
    bool removePublication(string bookName);
    string searchPublication(string bookName);
    void printList();
};

// Constructor to initialize the linked list
LinkedList::LinkedList() {
    head = NULL;
    this->linkedListSize = 0;
}

// Destructor
// Description: The destructor takes out every publication node from the linked list out of the linked list.
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

// Add Publication to Front Method
// Description: The add publication to front method adds a publication into the linked list to the front of the linked list.
void LinkedList::addPublicationtoFront(string newCodeISBN, string newPublicationTitle, string newPublisherName) {
    // Setting up the new publication node
    struct Publication* newPublicationNode = new Publication;
    struct Publication* tempNode = head;
    // Add pertinent information about the publication to the node
    newPublicationNode->codeISBN = newCodeISBN;
    newPublicationNode->publicationTitle = newPublicationTitle;
    newPublicationNode->publisherName = newPublisherName;
    // Add every new publication node to the front of the linked list
    head = newPublicationNode;
    newPublicationNode->next = tempNode;
    // Update the linked list size
    this->linkedListSize = this->linkedListSize + 1;
}

// Remove Publication Method
// Description: The remove publication method removes a publication in the list based off of the ISBN. If the publication being removed is not on the list,
//              return false.
bool LinkedList::removePublication(string codeISBN) {
    struct Publication* prevNode = NULL;
    struct Publication* tempNode = this->head;
    // While traversing through the linked list,
    while (tempNode != NULL) {
        // If the publication being removed matches the publication found in the linked list based off of the ISBN,
        if (codeISBN.compare(tempNode->codeISBN) == 0) {
            // If the publication being removed is the first publication in the linked list based off of the ISBN,
            if (prevNode == NULL) {
                // Set the head node to the next node after the first publication node
                head = tempNode->next;
                // Update the linked list size
                this->linkedListSize = this->linkedListSize - 1;
                return true;
            }
            // If the publication being removed is not the first publication in the linked list based off of the ISBN,
            else {
                // Delete this node by adjusting the nodes so that the list skips the node being deleted.
                prevNode->next = tempNode->next;
                // Update the linked list size
                this->linkedListSize = this->linkedListSize - 1;
                return true;
            }
        }
        // If the publication being removed does not matches the publication found in the linked list based off of the ISBN, move on
        // the next element in the linked list until the end of the linked list is reached.
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    // If the publication being deleted cannot be found in the linked list, return false.
    return false;
}
 
// Search Publication Method
// Description: The search publication method searches for a publication in the list based off of the ISBN. If the publication being 
//              searched for is not on the list, return "not found". If the publication being searched for is in the list, 
//              return this publication title.
string LinkedList::searchPublication(string codeISBN) {
    struct Publication* tempNode = this->head;
    // While traversing through the linked list,
    while (tempNode != NULL) {
        // If the publication being searched for matches the publication ISBN found in the linked list based off of the ISBN,
        if (codeISBN.compare(tempNode->codeISBN) == 0) {
            // Return the publication title for the corresponding publication ISBN
            return tempNode->publicationTitle;
        }
        // If the publication being searched for does not match the publication found in the linked list, move on
        // the next element in the linked list until the end of the linked list is reached.
        tempNode = tempNode->next;
    }
    // If the publication being searched for cannot be found in the linked list, return "not found".
    return "not found";
}

// Print List Method
// Description: The print list method prints the publication list to the console. If the list is empty, the console will print that the list is empty.
void LinkedList::printList() {
    struct Publication* tempNode = this->head;
    // If there is at least one element in the linked list,
    if (tempNode != NULL) {
        // While traversing through the linked list,
        while(tempNode != NULL) {
            // Print out the publication title, the ISBN, and the publisher name
            cout << "Publication: " << tempNode->publicationTitle << ", ISBN: " << tempNode->codeISBN << ", Publisher: " << tempNode->publisherName << endl;
            // Move onto the next node
            tempNode = tempNode->next;
        }
        cout << "\n" << endl;
    }
    // If there are no elements in the linked list,
    else {
        // Print that the list is empty.
        cout << "The list is empty!\n" << endl;
    }
}