////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Assignment #1
// Name: Taman Truong
// ASU Email Address: tvtruon1@asu.edu
// Description: This program displays a menu of choices to a user
//              and performs the chosen task. It will keep asking a user to
//              enter the next choice until the choice of 'Q' (Quit) is entered.
// Please answer the following three questions (3 points).
// 1. Which place (specify university/college/school name) did you take the prerequisite (CSE220/240 or equivalent) course? 
//    -> Arizona State University - Tempe Campus, Ira A. Fulton Schools of Engineering
// 2. Who was your instructor for the prerequisite (CSE220/240 or equivalent) course? 
//    -> Justin Selgrad (CSE 220/240 Merged/Hybrid Course)
// 3. What was the mode of the prerequisite (CSE220/240 or equivalent) course? Onground, Online, Hybrid, or Other (explain)
//    -> Hybrid (In-Person/Zoom)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

void printMenu();

int main()
   {
       // local variables, can be accessed anywhere from the main method
       char input1 = 'Z';
       string courseName;
       int numberOfCredits;
       bool success = false;

       // instantiate a Linked List object
       LinkedList * list1 = new LinkedList();

       printMenu();


       do  // will ask for user input
        {
           cout << "\nWhat action would you like to perform?\n";
           cin.get(input1);
           input1 = toupper(input1);
           cin.ignore(20, '\n'); //flush the buffer
           // matches one of the case statement
           switch (input1)
            {
             case 'A':   //Add Course
                cout << "Please enter some course information:\n";
                cout << "Enter a course name:\n";
                getline(cin, courseName);

                cout << "Enter a number of its credits:\n";
                cin >> numberOfCredits;
                cin.ignore(20, '\n'); //flush the buffer

                success = list1->addCourse(courseName, numberOfCredits);
     
                if (success == true)
                 cout << "The course " << courseName << " added\n";
                else
                 cout << "The course " << courseName << " not added\n";
                break;
             case 'D':   //Display Courses
                list1->printList();
                break;
             case 'M':  //Search Course
                cout << "Please enter a course name to search:\n";
                getline(cin, courseName);
                    
                numberOfCredits = list1->searchCourse(courseName);
                if (numberOfCredits > -1)
                        cout << "The course " << courseName << " has " << numberOfCredits << " credit(s)\n";
                else
                        cout << "The course " << courseName << " does not exist\n";
                break;
             case 'Q':   //Quit
                delete list1;
                break;
             case 'R':  //Remove Course
                cout << "Please enter a course name to remove:\n";
                getline(cin, courseName);

                success = list1->removeCourse(courseName);
                if (success == true)
                 cout << "The course " << courseName << " removed\n";
                else
                 cout << "The course " << courseName << " does not exist\n";
                break;
             case '?':   //Display Menu
                printMenu();
                break;
             default:
                cout << "Unknown action\n";
                break;
            }

        } while (input1 != 'Q');

      return 0;
   }


  /** The method printMenu displays the menu to a user**/
  void printMenu()
   {
     cout << "Choice\t\tAction\n";
     cout << "------\t\t------\n";
     cout << "A\t\tAdd Course\n";
     cout << "D\t\tDisplay Courses\n";
     cout << "M\t\tSearch Course\n";
     cout << "Q\t\tQuit\n";
     cout << "R\t\tRemove Course\n";
     cout << "?\t\tDisplay Help\n\n";
  }