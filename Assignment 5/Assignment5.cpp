////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Assignment #5
// Name: Taman Truong
// ASU Email Address: tvtruon1@asu.edu
// Description: This program takes user input of a hash table size, number of publications to be inserted, the publications
//              inserted as (ISBN)/(Publication Title)/(Publisher Name) with a delimeter "/", the number of commands to execute,
//              and the commands to do with the hash table (hash_search, hash_delete, hash_insert, hash_longest_title, and
//              hash_display) in order to parse and sort publisher information into a hash table (data structure).
// Hash Analysis: I came up with my hash function by considering powers through iterative multiplication of the ASCII values 
//                of each character in the ISBN of the publication. The number of collisions was what I expected with the 
//                multiplication function, as the products of values are cyclic in the modulus domain. My hash function worked 
//                well overall, but if I had to change it, I would mix up the operations of addition, multiplication, and 
//                exponentiation to minimize the number of collisions.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> // to use cout
#include <string> // to use strings
#include "HashTable.h" // to use the HashTable.h header file

using namespace std;

int main(){ 
    // initialize all variables for user input and output
    int newHashTableSize;
    int numberOfPublications;
    int numberOfCommands;
    string fullPublication;
    string codeISBN;
    string publicationTitle;
    string publisherName;
    string command;
    string commandCodeISBN;
    string commandPublicationTitle;
    string commandPublisherName;

    // Enter a hash table size
    cout << "Please enter a hash table size:" << endl;
    cin >> newHashTableSize;
    std::cin.ignore();
    // Initialize a hash table with user input size
    HashTable* newHashTable = new HashTable(newHashTableSize);
    // Enter the number of publications to be inserted
    cout << "How many publications will be inserted?" << endl;
    cin >> numberOfPublications;
    std::cin.ignore();
    // For all publications to be inputted
    for(int i = 0; i < numberOfPublications; i++) {
        // Take in each publication (ISBN)/(Title)/(Publisher)
        std::getline(std::cin, fullPublication);
        // Parse the input with the delimiter "/"
        codeISBN = fullPublication.substr(0, fullPublication.find("/"));
        fullPublication.erase(0, fullPublication.find("/") + 1);
        publicationTitle = fullPublication.substr(0, fullPublication.find("/"));
        fullPublication.erase(0, fullPublication.find("/") + 1);
        publisherName = fullPublication;
        // Insert the publication with the parsed publication data
        newHashTable->insertPublication(codeISBN, publicationTitle, publisherName);
    }
    // Enter a number of commands
    cout << "Please enter a number of commands:" << endl;
    cin >> numberOfCommands;
    std::cin.ignore();
    // For all number of commands to be inputted
    for(int i = 0; i < numberOfCommands; i++) {
        // Take in the command and the corresponding input(s)
        std::getline(std::cin, command);
        cout << "\n" << endl;
        // If "hash_search" is entered
        if(command.find("hash_search") != std::string::npos) {
            cout << "Command: hash_search" << endl;
            // Parse the input with the delimiter ","
            command.erase(0, command.find(",") + 1);
            commandCodeISBN = command;
            // Search for the publication with the key (ISBN)
            newHashTable->searchPublication(commandCodeISBN);
            cout << "\n" << endl;
        }
        // If "hash_delete" is entered
        else if(command.find("hash_delete") != std::string::npos) {
            cout << "Command: hash_delete" << endl;
            // Parse the input with the delimiter ","
            command.erase(0, command.find(",") + 1);
            commandCodeISBN = command;
            // Delete the publication with the key (ISBN)
            newHashTable->removePublication(commandCodeISBN);
            cout << "\n" << endl;
        }
        // If "hash_insert" is entered
        else if(command.find("hash_insert") != std::string::npos) {
            cout << "Command: hash_insert" << endl; 
            // Parse the input with the delimiter ","
            command.erase(0, command.find(",") + 1);
            commandCodeISBN = command.substr(0, command.find(","));
            command.erase(0, command.find(",") + 1);
            commandPublicationTitle = command.substr(0, command.find(","));
            command.erase(0, command.find(",") + 1);
            commandPublisherName = command;
            // Insert the publication with the parsed publication data
            newHashTable->insertPublication(commandCodeISBN, commandPublicationTitle, commandPublisherName);
            cout << "\n" << endl;
        }
        // If "hash_longest_title" is entered
        else if(command.find("hash_longest_title") != std::string::npos) {
            cout << "Command: hash_longest_title" << endl;
            // Find the publication with the longest title
            newHashTable->searchLongestTitle();
            cout << "\n" << endl;
        }
        // If "hash_display" is entered
        else if(command.find("hash_display") != std::string::npos) {
            cout << "Command: hash_display" << endl;
            cout << "Hash Table Contents:" << endl;
            cout << "------------------------------------------" << endl;
            // Print the entire hash table
            newHashTable->printTable();
            cout << "------------------------------------------" << endl;
            cout << "\n" << endl;
        }
    }
    return 0;
}