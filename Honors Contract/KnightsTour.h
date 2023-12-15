// Alexander Wood, Taman Truong
// CSE 310 Honors Contract - Nakamura
// KnightsTour.h
/**
 In this header file, we have defined our KnightsTour class which has the private variables m, n, totalMoves,
 and board. This variables hold the length of the board, width of the board, the total number of
 possible moves that can be made, and the 2D matrix that represents our board.
 We also define two size 8 matrixes that represent all the ways a knight can move. We use these two
 arrays several times in the code to check the validity of moves.
 
 We then have the public functions: constructor, isSafe, printBoard, solveTourRecursive, solveTour.
 I wll describe the logic behind each function.
 
 Constructor: KnightsTour(int, int)
 First, this method takes in two integers and defines an mxn board from them.
 It then uses these two numbers to define the total number of moves that can be made.
 We then declare the size of the rows (m). We then enter a for-loop that creates
 a new array for every index of the array, thus making the size of the columns (n).
 We then enter a nested for-loop (mn) to set the value of each posiiton to the smallest
 integer value as possible. This is supposed to represent negative infinity. 
 */

#include <iostream>
#include <iostream>
#include <string>

class KnightsTour
{
private:
    int m, n, totalMoves;
    int ** board;
public:
    KnightsTour(int, int);
    bool isSafe(int, int);
    void printBoard();
    bool solveTourRecursive(int, int, int);
    void solveTour();
    
};

// define possible x and y moves
int xMoves[] = {1, 2, -2, -1, -1, 1, -2, 2}; // O(1)
int yMoves[] = {-2, -1, -1, 2, -2, 2, 1, 1}; // O(1)

// constructor
KnightsTour::KnightsTour(int l, int w) // total O(mn)
{
    // defines m, n, and the total number of moves
    this->m = l; // O(1)
    this->n = w; // O(1)
    this->totalMoves = l * w; // O(1)
    
    // create mxn board
    board = new int*[this->m]; // O(1)
    for(int i = 0; i < this->m; i++) // O(m)
    {
        board[i] = new int[this->n]; // O(1)
    }
    
    // set every spot to negative infinity // total O(mn)
    for(int i = 0; i < this->m; i++) // O(m)
    {
        for(int j = 0; j < this->n; j++) // O(n)
        {
            board[i][j] = INT_MIN; // O(1)
        }
    }
    
}

// checks whether a given piece is good or not
bool KnightsTour::isSafe(int x, int y) // O(1)
{
    // checks if the move is in bounds or not
    if(((x >=0) && (x < this->m)) && ((y >=0) && (y < this->m))) // O(1)
    {
        // in bounds
        return true; // O(1)
    }
    // not in bounds
    return false; // O(1)
}

// print board
void KnightsTour::printBoard() // total O(mn)
{
    for(int i = 0; i < this->m; i++) // O(m)
    {
        for(int j = 0; j < this->n; j++) // O(n)
        {
            std::cout << board[i][j] << " "; // O(1)
        }
        std::cout << std::endl; // O(1)
    }
}

// the recursive call made to solve the tour
bool KnightsTour::solveTourRecursive(int moveCount, int x, int y) // O(8^mn)
{
    // will hold the moves being tested
    int nextX, nextY; // O(1)
    
    // base case
    if(moveCount == this->totalMoves) // O(1)
    {
        // solution found
        return true; // O(1)
    }
    
    // else, solve recursively by iterating through moves
    for(int i = 0; i < 8; i++) // O(8^mn)
    {
        // set next moves
        nextX = x + xMoves[i]; // O(1)
        nextY = y + yMoves[i]; // O(1)
        
        // check if move is in bounds AND is negative infinity
        if((isSafe(nextX, nextY) == true) && (board[nextX][nextY] == INT_MIN)) // O(1)
        {
            // move is valid, so make that edge
            board[nextX][nextY] = moveCount; // O(1)
            moveCount++; // O(1)
            
            // recursive step - solve next step
            if(solveTourRecursive(moveCount, nextX, nextY)) // O(mn)
            {
                return true; // O(1)
            }
            
            // else, if move is not valid for the future, back track
            board[nextX][nextY] = INT_MIN; // O(1)
            moveCount--; // O(1)
        }
    }
    
    // no solution
    return 0; // O(1)
}

// solve tour - called from main
void KnightsTour::solveTour() // total O(mn)
{
    // start at (0, 0)
    board[0][0] = 0; // O(1)
    
    // call recursive solution
    if(solveTourRecursive(1, 0, 0) == true) // O(mn)
    {
        // if solution found, prints the board with move numbers
        printBoard(); // O(mn)
    }
    else
    {
        std::cout << "Something went wrong here..." << std::endl; // O(1)
    }
}