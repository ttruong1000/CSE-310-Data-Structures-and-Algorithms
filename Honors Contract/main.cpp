// Alexander Wood, Taman Truong
// CSE 310 Honors Contract - Nakamura
// main.cpp
/**
 This is the main class. Nothing much is happening here. We introduce ourselves upon the start of the main.
 We then ask for user input to define the demensions of the mxn board, for which they
 wish to solve, then calls a helper function in the KnightsTour.h file to
 recursivley solve the problem.
 */

#include <iostream>
#include <iostream>
#include <string>

#include "KnightsTour.h"

int main(int argc, const char * argv[]) 
{
    // defining integers m,n for the size of the board
    int m, n; // O(1)
    
    std::cout << "Welcome to the Knights Tour solution by Alexander Wood and Taman Truong\n" << 
    "This program will produce an open Knights Tour Solution for a mxn size board" << std::endl; // O(1)
    
    // grab dimensions
    std::cout << "Please enter size for m: " << std::endl; // O(1)
    std::cin >> m; // O(1)
    std::cin.ignore(); // O(1)
    
    std::cout << "Please enter size for n: " << std::endl; // O(1)
    std::cin >> n; // O(1)
    std::cin.ignore(); // O(1)
    
    // define board size
    KnightsTour * board1 = new KnightsTour(m, n); // O(1)
    
    // solve tour
    board1->solveTour(); // O(8^(mn))
}