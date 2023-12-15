////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Assignment #5
// Name: Taman Truong
// ASU Email Address: tvtruon1@asu.edu
// Description: The HashTable.h header file is meant to assist the Assignment5.cpp file in forming a hash table of publications, 
//              with the ISBN, publication title, and publisher name. The header file contains pertinent class declarations, 
//              constructors, destructors, and helper methods (hashFunction, createHashTable, insertPublication, searchPublication, 
//              removePublication, searchLongestTitle, and printTable) to construct and destruct the hash table of publications.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> // to use cout
#include <iomanip> // to format output
#include <string> // to use strings
#include "LinkedList.h" // to use the LinkedList.h header file

using namespace std;

// class HashTable will contains an linked list array of linked lists
class HashTable {
    public:
    LinkedList** hashTable;
    int hashTableSize;
    HashTable(int newHashTableSize);
    ~HashTable();
    int hashFunction(string codeISBN);
    void createHashTable(int newHashTableSize);
    void insertPublication(string newCodeISBN, string newPublicationTitle, string newPublisherName);
    void searchPublication(string codeISBN);
    void removePublication(string codeISBN);
    void searchLongestTitle();
    void printTable();
};

// Constructor to initialize the hash table
HashTable::HashTable(int newHashTableSize) {
    hashTable = new LinkedList*[newHashTableSize];
    hashTableSize = newHashTableSize;
    for (int i = 0; i < hashTableSize; i++) {
        hashTable[i] = new LinkedList();
    }
}

// Destructor
// Description: The destructor takes out every publication node out of the hash table.
HashTable::~HashTable() {
    for(int i = 0; i < hashTableSize; i++) {
        hashTable[i]->~LinkedList();
    }
}

// Hash Function Method
// Hash Function: h(k) = ((a mod p)^2 + (b mod p)^2 + (c mod p)^2 + ...) mod p, where a, b, c, ... are the ASCII character values 
//                of the characters in the publication ISBN and p is the hash table size.
// Description: The hash function determines the index of the linked list array in which the publication will be manipulated.
int HashTable::hashFunction(string codeISBN) {
    int keyValueAtIndex = 0;
    int product = 0;
    int temporaryValue = 0;
    int finalHashFunctionValue = 0;
    // For every character in the publication ISBN
    for(int i = 0; i < codeISBN.length(); i++){
        // Take the ASCII character values of each character in the ISBN
        keyValueAtIndex = (int) codeISBN[i];
        // Do arithmetic and modulus operations, satisfying the conditions for h(k)
        product = ((keyValueAtIndex % hashTableSize) * (keyValueAtIndex % hashTableSize)) % hashTableSize;
        temporaryValue = (temporaryValue + product) % hashTableSize;
    }
    // Take the modulus of the entire iterated sum of products (squared numbers)
    finalHashFunctionValue = temporaryValue % hashTableSize;
    return finalHashFunctionValue;
}

// Insert Publication Method
// Description: The insert publication method inserts a publication into a particular index of the hash table, based off of the hash function.
void HashTable::insertPublication(string newCodeISBN, string newPublicationTitle, string newPublisherName) {
    int key = hashFunction(newCodeISBN); // Hash Function
    // Insert the publication to the front of the linked list at a particular index of the hash table
    hashTable[key]->addPublicationtoFront(newCodeISBN, newPublicationTitle, newPublisherName);
}

// Search Publication Method
// Description: The search publication method searches for a publication based off of the ISBN, which is based off of the hash function.
void HashTable::searchPublication(string codeISBN) {
    int key = hashFunction(codeISBN); // Hash Function
    // Record the corresponding string if the publication is found
    string publicationIsFound = hashTable[key]->searchPublication(codeISBN);
    // If the publication is not found,
    if (publicationIsFound.compare("not found") == 0) {
      // Output that the publication is not found
      cout << "The Publication with ISBN " << codeISBN << " is not found.";
    }
    // If the publication is found,
    else {
      // Output that the publication is found
      cout << "The Publication: " << publicationIsFound << " with ISBN " << codeISBN << " is found.";
    }
}

// Remove Publication Method
// Description: The remove publication method searches for a publication based off of the ISBN, which is based off of the hash function.
void HashTable::removePublication(string codeISBN) {
    int key = hashFunction(codeISBN); // Hash Function
    // Record the corresponding string if the publication is found
    string publicationIsFound = hashTable[key]->searchPublication(codeISBN);
    // If the publication is not found,
    if (publicationIsFound.compare("not found") == 0) {
      // Output that the publication is not removed
      cout << "The Publication with ISBN " << codeISBN << "is not removed.";
    }
    // If the publication is found,
    else {
      // Output that the publication is going to be removed
      cout << "The Publication: " << publicationIsFound << " with ISBN " << codeISBN << " is removed.";
      // Remove the publication from the linked list at the particular index of the hash table
      hashTable[key]->removePublication(codeISBN);
    }
}

// Search Longest Title Method
// Description: The search publication method searchs for the longest publication title.
void HashTable::searchLongestTitle() {
  string longestTitle = "";
  int longestTitleLength = 0;
  // For all elements in the hash table
  for (int i = 0; i < this->hashTableSize; i++) {
    Publication* currentPublication = hashTable[i]->head;
    // While the current publication node is not null,
    while(currentPublication != NULL) {
      // If the current publication title is longer than the longest title length
      if((currentPublication->publicationTitle).length() > longestTitleLength) {
        // Set the string to be the new longest title
        longestTitle = currentPublication->publicationTitle;
        // Set the longest title length to be the new longest title length
        longestTitleLength = currentPublication->publicationTitle.length();
      }
      // If the current publication title is not longer than the longest title length, move to the next publication node in the hash table index
      currentPublication = currentPublication->next;
    }
  }
  // If the longest title length is 0,
  if(longestTitleLength == 0) {
    // There is no elements in the hash table
    cout << "The hash table is empty!" << endl;
  }
  // If the longest title length is not 0,
  else {
    // Return the longest publication title size
    cout << "The Publication: " << longestTitle << " has the longest title size of " << longestTitleLength << "." << endl;
  }
}

// Print Table Method
// Description: The print table method prints the entire hash table.
void HashTable::printTable() {
  // For all elements in the hash table,
  for(int i = 0; i < this->hashTableSize; i++) {
    // Output the index and the linked list size of each index of the hash table
    cout << "Index: " << i << ", Linked List Size: " << hashTable[i]->linkedListSize << endl;
    // Print the hash table at this index
    hashTable[i]->printList();
  }
}