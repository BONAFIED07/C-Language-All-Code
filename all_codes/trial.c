#include <stdio.h>

#define BOARD_SIZE 3

// Function to initialize the board with empty spaces
void initializeBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < BOARD_SIZE - 1) {
                printf(" | ");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("---------\n");
        }
    }
}

// Function to check if a player has won
char checkWin(char board[][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return board[0][j];
        }
    }
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }
    // No winner yet
    return ' ';
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer = 0; // 0 for X, 1 for O
    int moves = 0;

    initializeBoard(board);

    while (moves < BOARD_SIZE * BOARD_SIZE) {
        // Print the board
        printf("Current board:\n");
        printBoard(board);

        // Get user input for row and column
        int row, col;
        printf("Player %c's turn. Enter row number (0-2): ", currentPlayer == 0 ? 'X' : 'O');
        scanf("%d", &row);
        printf("Enter column number (0-2): ");
        scanf("%d", &col);

        // Check if the chosen cell is empty
        if (board[row][col] == ' ') {
            // Place the player's mark in the chosen cell
            board[row][col] = currentPlayer == 0 ? 'X' : 'O';
            moves++;

            // Check for a win
            char winner = checkWin(board);
            if (winner != ' ') {
                printf("Player %c wins!\n", winner);
                printBoard(board);
                return 0;
            }

            // Switch players
            currentPlayer = (currentPlayer + 1) % 2;
        } else {
            printf("That cell is already taken. Try again.\n");
        }
    }

    // If no winner found and the board is full, it's a draw
    printf("It's a draw!\n");
    printBoard(board);

    return 0;
}
