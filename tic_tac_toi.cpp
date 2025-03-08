#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Columns
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Anti-diagonal
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false; // If any cell is empty, the game is not a draw
        }
    }
    return true;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // Initialize empty board
    char currentPlayer = 'X'; // Start with player X
    int row, col;
    bool playAgain = true;

    cout << "Welcome to Tic-Tac-Toe!\n";

    while (playAgain) {
        // Reset the board for a new game
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X'; // Reset to player X

        bool gameOver = false;

        while (!gameOver) {
            // Display the current board
            displayBoard(board);

            // Get the current player's move
            cout << "Player " << currentPlayer << ", enter your move (row and column, 1-3): ";
            cin >> row >> col;

            // Adjust to 0-based indexing
            row--;
            col--;

            // Validate the move
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = currentPlayer; // Update the board

                // Check if the current player has won
                if (checkWin(board, currentPlayer)) {
                    displayBoard(board);
                    cout << "Player " << currentPlayer << " wins!\n";
                    gameOver = true;
                }
                // Check if the game is a draw
                else if (checkDraw(board)) {
                    displayBoard(board);
                    cout << "It's a draw!\n";
                    gameOver = true;
                }
                // Switch players
                else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }

        // Ask if the players want to play again
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        playAgain = (choice == 'y' || choice == 'Y');
    }

    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}