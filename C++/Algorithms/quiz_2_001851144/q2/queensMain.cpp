//In class it was discussed that the use of a matrix method is acceptable
#define N 8 
#include<iostream>

using namespace std;

// Clears the board
void emptyBoard(int resetBoard[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) 
            resetBoard[i][j] = 0;
}

// Prints the input board
void printBoard(int solutionBoard[8][8]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++ j) {
            cout << solutionBoard[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

// Checks if current placing attempt is safe from other queens
bool placeSafe(int currentBoard[8][8], int row, int col) {
    // Check row
    for (int i = col - 1; i >= 0; --i) {
        if (currentBoard[row][i] == 1) {
            return false;
        }
    }
    // Check top left diagonal 
    for (int i = row, j = col; i >= 0  && j >= 0; i--, j--) {
        if (currentBoard[i][j]) {
            return false;
        }
    }
    // Check bottom left diagonal
    for (int i = 1; i < N - 1 - row; ++i) {
        if (currentBoard[row + 1][col - 1] == 1) {
            return false;
        }
    }

    return true;
}

// Recursive function that finds a solution to current board
bool recursBoard(int currentBoard[8][8], int col) {
    // If we have placed all queens, there is a solution
    if (col == N) {
        printBoard(currentBoard);
        emptyBoard(currentBoard);
        return true;
    }

    // Iterate through each column
    for (int i = 0; i < N; ++i) {
        // If the placement is safe, place the queen
        if (placeSafe(currentBoard, i, col)) {
            currentBoard[i][col] = 1;

            // Check if this leads to a solution
            if (recursBoard(currentBoard, col + 1)) {
                return true;
            }

            // Backtrack, try the next row
            currentBoard[i][col] = 0;
        }
    }

    return false;
}

int main() {
    // Board setups and their corresponding solutions
    int board[8][8] = {{0}};
    for (int i = 0; i < N; ++i) {
        board[i][0] = 1;
        recursBoard(board, 1);
    }
}