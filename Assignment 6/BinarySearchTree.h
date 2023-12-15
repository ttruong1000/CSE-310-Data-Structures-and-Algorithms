// Assignment #6
// Name: Taman Truong
// ASU Email Address: tvtruon1@asu.edu
// Description: The BinarySearchTree.h header file is meant to assist the Assignment6.cpp file in forming a binary search tree of course and their corresponding credits.
//              The courses are put on the binary search tree in descending order of credits. Starting from the root, the left nodes will have courses with a greater amount
//              of credits than the root, and the right nodes will have courses with a lesser amount of credits than the root. If any of the courses in the binary search tree
//              have the same number of credits, they are placed in alphabetical order, from bottom to top.

#include <iostream> //to use cout
#include <string> //to use strings
#include <cstdlib> //to use atoi

using namespace std;

//Course represents some course information
class Course {
  private: 
    string courseName;
    int numberOfCredits;
    Course * left, * right, * parent;

  public:
    //The following two functions are constructors
    Course(){ 
      courseName = "?";
      numberOfCredits = 0;
      parent = NULL;
      left = NULL;
      right = NULL;
    }

    Course(string courseName1, int numberOfCredits1) {
      courseName = courseName1;
      numberOfCredits = numberOfCredits1;
      parent = NULL;
      left = NULL;
      right = NULL;
    }

    //The following functions are accessor functions
    Course* getLeft() {
      return left;
    }

    Course* getRight() {
      return right;
    }

    Course* getParent() {
      return parent;
    }
     
    string getCourseName() {
      return courseName;
    }
    
    int getNumberOfCredits() {
      return numberOfCredits;
    }

    //The following functions are mutator functions
    void setLeft(Course* other) {
       left = other;
    }

    void setRight(Course* other) {
       right = other;
    }

    void setParent(Course* other) {
       parent = other;
    }

    //The print method prints the courseName and numberOfCredits
    void print() {
      cout << "Course Name: " << courseName;
      cout << ", Credits: " << numberOfCredits << endl << endl;
    }
 };

//class BinarySearchTree will contains courses
class BinarySearchTree {
  private:
     Course* root;
     int size;

  public:
     BinarySearchTree();
     ~BinarySearchTree();
     int postOrderTreeDelete(Course * course);
     bool isEmpty();
     void inOrderTreePrint();
     void preOrderTreePrint();
     void postOrderTreePrint();
     void inOrderTreeWalk(Course * course);
     void preOrderTreeWalk(Course * course);
     void postOrderTreeWalk(Course * course);
     Course* treeSearchNode(Course * course, string courseName, int courseCredits);
     Course* treeSearch(string courseName, int courseCredits);
     Course* treeMinimum();
     Course* treeMaximum();
     Course* treeMinimumNode(Course * course);
     Course* treeMaximumNode(Course * course);
     Course* treeSuccessor(string courseName, int courseCredits);
     Course* treePredecessor(string courseName, int courseCredits);
     bool treeInsert(string newCourseName, int newCourseCredits);
     bool rightRotate(string courseName, int courseCredits);
     bool leftRotate(string courseName, int courseCredits);
};

//The constructor initialize the root to be NULL, size of the binary size tree to be 0
BinarySearchTree::BinarySearchTree() {
  root = NULL;
  size = 0;
}

//The destructor should delete all nodes in the tree 
//and perform garbage collections starting from leaves (bottom-up order). 
//The destructor should also print “The number of nodes deleted: X” 
//where X is the number of nodes deleted
BinarySearchTree::~BinarySearchTree() {
  cout << "The number of nodes deleted: " << postOrderTreeDelete(root) << endl;
}

// Deletes the binary search tree using post-order
int BinarySearchTree::postOrderTreeDelete(Course * course) {
  if(course == NULL) {
    return 0;
  }
  postOrderTreeDelete(course->getLeft());
  postOrderTreeDelete(course->getRight());
  delete course;
  size++;
  return size;
}

//Checks if the tree is empty
bool BinarySearchTree::isEmpty() {
   if (root == NULL)
    return true;
   else
    return false; 
}

// Prints all nodes using in-order
void BinarySearchTree::inOrderTreePrint() {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else {
    cout << "\n";
    inOrderTreeWalk(root);
    cout << "\n";
  }
}

// Prints all nodes using pre-order
void BinarySearchTree::preOrderTreePrint() {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else {
    cout << "\n";
    preOrderTreeWalk(root);
    cout << "\n";
  }
}

// Prints all nodes using post-order
void BinarySearchTree::postOrderTreePrint() {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else {
    cout << "\n";
    postOrderTreeWalk(root);
    cout << "\n";
  }
}

// Walking through the binary search tree using in-order
void BinarySearchTree::inOrderTreeWalk(Course* course) {
  if (course != NULL) {
    inOrderTreeWalk(course->getLeft());
    cout << "Course Name: " << course->getCourseName() << ", Credits: " << course->getNumberOfCredits() << endl;
    inOrderTreeWalk(course->getRight());
  }
}

// Walking through the binary search tree using pre-order
void BinarySearchTree::preOrderTreeWalk(Course* course) {
  if (course != NULL) {
    cout << "Course Name: " << course->getCourseName() << ", Credits: " << course->getNumberOfCredits() << endl;
    preOrderTreeWalk(course->getLeft());
    preOrderTreeWalk(course->getRight());
  }
}

// Walking through the binary search tree using post-order
void BinarySearchTree::postOrderTreeWalk(Course* course) {
  if (course != NULL) {
    postOrderTreeWalk(course->getLeft());
    postOrderTreeWalk(course->getRight());
    cout << "Course Name: " << course->getCourseName() << ", Credits: " << course->getNumberOfCredits() << endl;
  }
}

// Search through the binary search tree given a course name and course credits, starting from the root
Course* BinarySearchTree::treeSearch(string courseName, int courseCredits) {
  return treeSearchNode(root, courseName, courseCredits);
}

// Search through the binary search tree given a course name and course credits, starting from an arbitrary node
Course* BinarySearchTree::treeSearchNode(Course* course, string courseName, int courseCredits) {
  // if the course node is either NULL or matches the course name and course credits exactly
  if((course == NULL) || (((course->getCourseName()).compare(courseName) == 0) && (course->getNumberOfCredits() == courseCredits))) {
    return course; // return this course
  }
  else { // else, compare the number of credits with the current node's number of credits
    if(courseCredits < course->getNumberOfCredits()) {
      return treeSearchNode(course->getRight(), courseName, courseCredits);
    }
    else if(course->getNumberOfCredits() == courseCredits) {
      if(courseName.compare(course->getCourseName()) < 0) {
        return treeSearchNode(course->getLeft(), courseName, courseCredits);
      }
      else { // courseName.compare(course->getCourseName()) > 0
        return treeSearchNode(course->getRight(), courseName, courseCredits);
      }
    }
    else { // courseCredits > course->getNumberOfCredits()
      return treeSearchNode(course->getLeft(), courseName, courseCredits);
    }
  }
  // if node cannot be found
  return NULL;
}

// Find the minimum node on the binary search tree (course with the lowest number of credits) starting from the root
Course* BinarySearchTree::treeMinimum() {
  if (root == NULL){
    return NULL;
  }
  else {
    return treeMinimumNode(root);
  }
}

// Find the minimum node on the binary search tree (course with the lowest number of credits) starting from an arbitrary node
Course* BinarySearchTree::treeMinimumNode(Course* course) {
  while(course->getLeft() != NULL) {
    course = course->getLeft();
  }
  return course;
}

// Find the maximum node on the binary search tree (course with the highest number of credits) starting from the root
Course* BinarySearchTree::treeMaximum() {
  if (root == NULL){
    return NULL;
  }
  else {
    return treeMaximumNode(root);
  }
}

// Find the maximum node on the binary search tree (course with the highest number of credits) starting from an arbitrary node
Course* BinarySearchTree::treeMaximumNode(Course* course) {
  while(course->getRight() != NULL) {
    course = course->getRight();
  }
  return course;
}

// Find the successor of a node on the binary search tree
Course* BinarySearchTree::treeSuccessor(string courseName, int courseCredits) {
  Course* successor1 = treeSearch(courseName, courseCredits);
  if(successor1 == NULL) {
    return NULL;
  }
  if(successor1->getRight() != NULL) {
    return treeMinimumNode(successor1->getRight());
  }
  else {
    Course* successor2 = successor1->getParent();
    while((successor2->getParent() != NULL) && (successor1 == successor2->getRight())) {
      successor1 = successor2;
      successor2 = successor2->getParent();
    }
    return successor2;
  }
}

// Find the predecessor of a node on the binary search tree
Course* BinarySearchTree::treePredecessor(string courseName, int courseCredits) {
  Course* predecessor1 = treeSearch(courseName, courseCredits);
  if(predecessor1 == NULL) {
    return NULL;
  }
  if(predecessor1->getLeft() != NULL) {
    return treeMaximumNode(predecessor1->getLeft());
  }
  else {
    Course* predecessor2 = predecessor1->getParent();
    while((predecessor2->getParent() != NULL) && (predecessor1 == predecessor2->getLeft())) {
      predecessor1 = predecessor2;
      predecessor2 = predecessor2->getParent();
    }
    return predecessor2;
  }
}

// Insert a node in the binary search tree
bool BinarySearchTree::treeInsert(string newCourseName, int newCourseCredits) {
  Course* course1 = root;
  Course* course2 = NULL;
  Course* insertCourse = new Course(newCourseName, newCourseCredits); // inserted node
  while(course1 != NULL) {
    course2 = course1;
    // compare the number of credits with the current node's number of credits
    if(insertCourse->getNumberOfCredits() < course2->getNumberOfCredits()) {
      course1 = course1->getRight();
    }
    else if(insertCourse->getNumberOfCredits() == course2->getNumberOfCredits()){
      if(insertCourse->getCourseName().compare(course2->getCourseName()) < 0) {
        course1 = course1->getLeft();
      }
      else { // course->getCourseName().compare(courseName) > 0
        course1 = course1->getRight();
      }
    }
    else { // insertCourse->getNumberOfCredits() > course2->getNumberOfCredits()
      course1 = course1->getLeft();
    }
  }
  insertCourse->setParent(course2);
  if(course2 == NULL){
    root = insertCourse;
  }
  else {
    // compare the number of credits with the current node's number of credits
    if(insertCourse->getNumberOfCredits() < course2->getNumberOfCredits()) {
      course2->setRight(insertCourse);
    }
    else if(insertCourse->getNumberOfCredits() == course2->getNumberOfCredits()){
      if(insertCourse->getCourseName().compare(course2->getCourseName()) < 0) {
        course2->setLeft(insertCourse);
      }
      else { // course->getCourseName().compare(courseName) > 0
        course2->setRight(insertCourse);
      }
    }
    else { // insertCourse->getNumberOfCredits() > course2->getNumberOfCredits()
      course2->setLeft(insertCourse);
    }
  }
  return true;
}

// Left rotate the binary search tree
bool BinarySearchTree::leftRotate(string courseName, int courseCredits) {
  Course* course1 = treeSearch(courseName, courseCredits);
  if(course1 == NULL){
    return false;
  } 
  Course* course2 = course1->getRight();
  if(course2 == NULL){
    return false;
  }
  course1->setRight(course2->getLeft()); // (1)
  if(course2->getLeft() != NULL) { // (2)
    (course2->getLeft())->setParent(course1);
  }
  course2->setParent(course1->getParent()); // (3)
  if(course1->getParent() == NULL) { // (4)
    root = course2;
  }
  else {
    if(course1 == (course1->getParent())->getLeft()) {
      (course1->getParent())->setLeft(course2);
    }
    else {
      (course1->getParent())->setRight(course2);
    }
  }
  course2->setLeft(course1); // (5)
  course1->setParent(course2); // (6)
  return true;
}

// Right rotate the binary search tree
bool BinarySearchTree::rightRotate(string courseName, int courseCredits) {
  Course* course1 = treeSearch(courseName, courseCredits);
  if(course1 == NULL){
    return false;
  } 
  Course* course2 = course1->getLeft();
  if(course2 == NULL){
    return false;
  }
  course1->setLeft(course2->getRight()); // (1)
  if(course2->getRight() != NULL) { // (2)
    (course2->getRight())->setParent(course1);
  }
  course2->setParent(course1->getParent()); // (3)
  if(course1->getParent() == NULL) { // (4)
    root = course2;
  }
  else {
    if(course1 == (course1->getParent())->getRight()) {
      (course1->getParent())->setRight(course2);
    }
    else {
      (course1->getParent())->setLeft(course2);
    }
  }
  course2->setRight(course1); // (5)
  course1->setParent(course2); // (6)
  return true;
}