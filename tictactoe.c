#include <stdio.h>

// Function prototypes
void print_board(char board[3][3]);
int check_win(char board[3][3], char player);

int main() {
    char board[3][3] = { // Initialize the game board
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    int turn = 0; // Player 1's turn is 0, Player 2's turn is 1
    int row, col; // To hold the row and column input by the player

    printf("Welcome to Tic-Tac-Toe!\n\n");
    print_board(board);

    while (1) { // Loop until the game is over
        char player = (turn % 2 == 0) ? 'X' : 'O'; // Determine the current player

        printf("Player %c's turn.\n", player);
        printf("Enter row (0-2): ");
        scanf("%d", &row);
        printf("Enter column (0-2): ");
        scanf("%d", &col);

        if (board[row][col] == '-') { // Make sure the chosen spot is empty
            board[row][col] = player; // Place the player's symbol on the board
            print_board(board);

            if (check_win(board, player)) { // Check if the player has won
                printf("Player %c wins!\n", player);
                break; // End the game
            }

            turn++; // Switch to the other player's turn
        }
        else {
            printf("That spot is already taken. Try again.\n");
        }

        if (turn == 9) { // If all spots are taken and no one has won, it's a tie
            printf("It's a tie!\n");
            break; // End the game
        }
    }

    return 0;
}

// Prints the current state of the game board
void print_board(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Returns 1 if the given player has won, 0 otherwise
int check_win(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        // Check columns
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0; // If the player hasn't won yet, return 0
}