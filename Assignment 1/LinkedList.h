////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Assignment #1
// Name: Taman Truong
// ASU Email Address: tvtruon1@asu.edu
// Description: The LinkedList.h header file is meant to assist the Assignment1.cpp file in forming a linked list
//              of courses arranged in descending order of number of course credits. If the courses have the same 
//              number of credits, they are arranged in alphabetical order. The header file contains pertinent structs,
//              class declarations, constructors, destructors, and helper methods (addCourse, removeCourse, searchCourse, 
//              and printList) to construct and destruct the linked list of courses.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> // to use cout
#include <iomanip> // to format output
#include <string> // to use strings

using namespace std;

// struct Course represents some course information
struct Course {
    string courseName;
    int numberOfCredits;
    struct Course* next;
};

// class LinkedList will contains a linked list of courses
class LinkedList {
    private:
    struct Course* head;
    
    public:
    LinkedList();
    ~LinkedList();
    bool addCourse(string courseName, int numberOfCredits);
    bool removeCourse(string courseName);
    int searchCourse(string courseName);
    void printList();
};

// Constructor to initialize the linked list
LinkedList::LinkedList() {
    head = NULL;
}

// Destructor
// Description: The destructor takes out every course node from the linked list out of the linked list.
LinkedList::~LinkedList() {
    int courseCount = 0;
    struct Course* tempNode = this->head;
    struct Course* deleteNode = this->head;
    // While traversing through the linked list,
    while(tempNode != NULL) {
        deleteNode = tempNode; // assign the deleteNode to the temporary node, pointing to the first element
        tempNode = tempNode->next; // move onto the next node
        free(deleteNode); // delete the node at deleteNode
        courseCount++; // increment the amount of courses deleted
    }
    free(tempNode); // After traversing through the linked list, delete the temporary node
    cout << "The number of deleted courses is: " << courseCount << endl;
}

// Add Course Method
// Description: The add course method adds a course onto the linked list. The add course method is split based off of many subcases.
//              The list is arranged in descending order of number of credits. If any of the courses have the same number of credits, 
//              they are arranged in alphabetical order.
bool LinkedList::addCourse(string newCourseName, int newNumberOfCredits) {
    // If the course being added has the same name as an already existing course in the linked list, do not add that course.
    if (this->searchCourse(newCourseName) != -1) {
        return false;
    }
    struct Course* tempNode = this->head;
    // Setting up the new course node
    struct Course* newCourseNode = new Course;
    newCourseNode->courseName = newCourseName;
    newCourseNode->numberOfCredits = newNumberOfCredits;
    newCourseNode->next = NULL;
    // If the course being added to the linked list is the first one, add it to the linked list.
    if (head == NULL) {
        head = newCourseNode;
        return true;
    }
    // While traversing through the linked list,
    while (tempNode != NULL) {
        // If there is only 1 course in the linked list,
        if (tempNode->next == NULL) {
            // If the number of credits for the new course that is added is greater than the number of credits in the first course node,
            if (newNumberOfCredits > tempNode->numberOfCredits) {
                // Place the new course node in front of the first course node
                newCourseNode->next = head;
                head = newCourseNode;
                return true;
            }
            // If the number of credits for the new course that is added is less than the number of credits in the first course node,
            else if (newNumberOfCredits < tempNode->numberOfCredits) {
                // Place the new course node after the first course node
                tempNode->next = newCourseNode;
                return true;
            }
            // If the number of credits for the new course that is added is equal to the number of credits in the first course node,
            else if (newNumberOfCredits == tempNode->numberOfCredits) {
                // If the new course name comes after the name of the first course on the linked list,
                if (newCourseName.compare(tempNode->courseName) > 0) {
                    // Place the new course node after the first course node 
                    tempNode->next = newCourseNode;
                    return true;
                }
                // If the new course name comes before the name of the first course on the linked list,
                else if (newCourseName.compare(tempNode->courseName) < 0) {
                    // Place the new course node in front of the first course node
                    newCourseNode->next = tempNode;
                    head = newCourseNode;
                    return true;
                }
            }
        }
        // If there is more than 1 course in the linked list,
        // If the number of credits in the curent temporary node course is greater than the number of credits for the new course,
        else if (tempNode->numberOfCredits > newNumberOfCredits) {
            // If the new course node comes before the temporary node course with the same number of credits,
            if((newCourseName.compare((tempNode->next)->courseName) < 0) && ((tempNode->next)->numberOfCredits == newNumberOfCredits)) {
                // Place this new course after of the temporary node course (with the greater number of credits)
                newCourseNode->next = tempNode->next;
                tempNode->next = newCourseNode;
                return true;
          }
        }
        // If the number of credits in the current temporary node course is greater than the number of credits in the next temporary node course
        // and the number of credits in the new course is equal to the number of credits in the next temporary node course,
        else if ((tempNode->numberOfCredits > (tempNode->next)->numberOfCredits) && (newNumberOfCredits == (tempNode->next)->numberOfCredits)) {
            // If the name of the course in the current temporary node course comes before the new course name alphabetically,
            if (tempNode->courseName.compare(newCourseName) < 0) { 
                // Place the new course after the current temporary node course (with the greater number of credits)
                newCourseNode->next = tempNode->next;
                tempNode->next = newCourseNode;
                return true;
            }
        }
        // If the number of credits in the new course is the same as the number of credits in the temporary node course and next temporary node course,
        else if ((newNumberOfCredits == tempNode->numberOfCredits) && (newNumberOfCredits == (tempNode->next)->numberOfCredits)) {
            // If the temporary node course name comes before the new course name alphabetically and the new course name comes before the next temporary node course name,
            if (((tempNode->courseName).compare(newCourseName) < 0) && (newCourseName.compare((tempNode->next)->courseName) < 0)) {
                // Place the new course in between these two nodes in alphabetical order
                newCourseNode->next = tempNode->next;
                tempNode->next = newCourseNode;
                return true;
            }
        }
        // If the number of credits in the current temporary node course is greater than the number of credits in the next temporary node course and the number of credits in the new course
        // is greater than the number of credits in the current temporary node course,
        else if ((tempNode->numberOfCredits > (tempNode->next)->numberOfCredits) && (newNumberOfCredits > (tempNode->next)->numberOfCredits)) {
            // If the current temporary node course name comes before the new course name alphabetically,
            if (tempNode->courseName.compare(newCourseName) < 0) {
                // Place the new course after the current temporary node course
                newCourseNode->next = tempNode->next;
                tempNode->next = newCourseNode;
                return true;
            }
        }
        // If the number of credits in the new course is strictly between the number of credits in the next temporary node course and the current temporary node course (arranged in decreasing order of credits)
        else if ((tempNode->numberOfCredits > newNumberOfCredits) && (newNumberOfCredits > (tempNode->next)->numberOfCredits)) {
            // Place the new course in between these two nodes in order of descending credit numbers
            newCourseNode->next = tempNode->next;
            tempNode->next = newCourseNode;
            return true;
        }
        // If the number of credits in the new course is greater than the number of credits in the first course (the course with the greatest number of credits),
        else if (newNumberOfCredits > tempNode->numberOfCredits) {
            // Place the new course node in front of the linked list
            newCourseNode->next = head;
            head = newCourseNode;
            return true;
        }
        // If none of these sub-cases pass, move the temporary node to the next element in the linked list.
        tempNode = tempNode->next;
    }
}

// Remove Course Method
// Description: The remove course method removes a course in the list. If the name for the course being removed is not on the list,
//              return false.
bool LinkedList::removeCourse(string courseName) {
    struct Course* prevNode = NULL;
    struct Course* tempNode = this->head;
    // While traversing through the linked list,
    while (tempNode != NULL) {
        // If the course name being removed matches the course found in the linked list,
        if (courseName.compare(tempNode->courseName) == 0) {
            // If the course name being removed is the first course in the linked list,
            if (prevNode == NULL) {
                // Set the head node to the next node after the first course node
                head = tempNode->next;
                return true;
            }
            // If the course name being removed is not the first course in the linked list,
            else {
                // Delete this node by adjusting the nodes so that the list skips the node being deleted.
                prevNode->next = tempNode->next;
                return true;
            }
        }
        // If the course name being removed does not matches the course found in the linked list, move on
        // the next element in the linked list until the end of the linked list is reached.
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    // If the course being deleted cannot be found in the linked list, return false.
    return false;
}
 
// Search Course Method
// Description: The search course method searches for a course in the list. If the name for the course being searched for is not on the list,
//              return -1.
int LinkedList::searchCourse(string courseName) {
    struct Course* tempNode = this->head;
    // While traversing through the linked list,
    while (tempNode != NULL) {
        // If the course name being searched for matches the course found in the linked list,
        if (courseName.compare(tempNode->courseName) == 0) {
            // Return the number of credits for that searched course
            return tempNode->numberOfCredits;
        }
        // If the course name being searched for does not matches the course found in the linked list, move on
        // the next element in the linked list until the end of the linked list is reached.
        tempNode = tempNode->next;
    }
    // If the course being searched for cannot be found in the linked list, return false.
    return -1;
}

// Print List Method
// Description: The print course method prints the course list to the console. If the list is empty, the console will print that the list is empty.
void LinkedList::printList() {
    struct Course* tempNode = this->head;
    // If there is at least one element in the linked list,
    if (tempNode != NULL) {
        // While traversing through the linked list,
        while(tempNode != NULL) {
            // Print out the course name and its corresponding number of credits
            cout << "Course Name: " << tempNode->courseName << ", Credits: " << tempNode->numberOfCredits << endl;
            // Move onto the next node
            tempNode = tempNode->next;
        }
    }
    // If there is at least one element in the linked list,
    else {
        // Print that the list is empty.
        cout << "The list is empty!\n" << endl;
    }
}