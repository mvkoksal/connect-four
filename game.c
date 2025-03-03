#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_WIDTH 7
#define BOARD_HEIGHT 6
#define BOARD_LENGTH 41

// Constants to print in bold red text, bold yellow text, and to reset text style
#define START_RED "\033[1m\033[31m"
#define START_YELLOW "\033[1m\033[33m"
#define RESET_COLOR "\033[0m"

// Print the current board
void print_choices (char board[]) {
    printf(" A B C D E F G\n");
    printf("|");
    for (int i=0; i<=BOARD_LENGTH; i++) {
        // print in red or yellow according to the input
        if (board[i] == 'R') {
            printf(START_RED "%c" RESET_COLOR, board[i]);
        } else if (board[i] == 'Y') {
            printf(START_YELLOW "%c" RESET_COLOR, board[i]);
        } else {
            printf("%c", board[i]);
        }
        // Newline at the end of the row
        if ((i+1)%7==0) {
            printf("|");
            printf("\n");
        }
        // Separate each cell with | until the board is complete
        if (i != 41) {
            printf("|");
        }
    }
    printf("---------------\n");
}

// Variables that record the amount of empty slots in a given column
int column_A = 5;
int column_B = 5;
int column_C = 5;
int column_D = 5;
int column_E = 5;
int column_F = 5;
int column_G = 5;

// Return false if the chosen column is full, return true otherwise
bool column_full_check (char letter) {
    if (((letter == 'A') & (column_A == -1)) ||
        ((letter == 'B') & (column_B == -1)) ||
        ((letter == 'C') & (column_C == -1)) ||
        ((letter == 'D') & (column_D == -1)) ||
        ((letter == 'E') & (column_E == -1)) ||
        ((letter == 'F') & (column_F == -1)) ||
        ((letter == 'G') & (column_G == -1))) {
        return 0;
    } else {
        return 1;
    }
}

// Ask for input until valid input is given, print the relevant error message
// Return the input if it is valid
char column_choice () {
    char letter;
    char extra;

    printf("Choose a column. (A-G)\n");
    while (1) {
        letter = getchar();
        extra = getchar();
        // Check if the input is just 1 character
        if (extra != '\n') {
            printf("Too many characters.\n");
            while (getchar() != '\n');
            continue;
        }
        // Check if the chosen column is full
        if (column_full_check(letter) == 0) {
           printf ("This column is full. Please choose another column.\n");
        // Check if the input is a capital letter from A-G
        } else if  ((letter == 'A') || (letter == 'B') ||
                    (letter == 'C') || (letter == 'D') ||
                    (letter == 'E') || (letter == 'F') ||
                    (letter == 'G')) {
                    break;
                } else {
                    printf("Invalid input. Please enter a capital letter from A-G.\n");
                }
    }
    return letter;
}


// Return the index in the board array where the current input should be placed
// Decrease the column variable corresponding to the given input
int input_index (char letter) {
    if (letter == 'A') {
        int index1 = (column_A * 7);
        column_A -= 1;
        return index1;
    } else if (letter == 'B') {
        int index2 = ((column_B * 7) + 1);
        column_B -= 1;
        return index2;
    } else if (letter == 'C') {
        int index3 = ((column_C * 7) + 2);
        column_C -= 1;
        return index3;
    } else if (letter == 'D') {
        int index4 = ((column_D * 7) + 3);
        column_D -= 1;
        return index4;
    } else if (letter == 'E') {
        int index5 = ((column_E * 7) + 4);
        column_E -= 1;
        return index5;
    } else if (letter == 'F') {
        int index6 = ((column_F * 7) + 5);
        column_F -= 1;
        return index6;
    } else if (letter == 'G') {
        int index7 = ((column_G * 7) + 6);
        column_G -= 1;
        return index7;
    } else {
      return -1;
    }
}

// Check all possible column wins, return true if there is one, return false otherwise
bool column_win (char board[], char player) {
    // Loop through each column
    for (int k=0; k<7; k++) {
        // Check the current column for wins
        for (int i=k; i<=14; i += 7) {
            if ((board[i] == player) && (board[i+7] == player) && (board[i+14] == player) && (board[i+21] == player)) {
                return true;
            }
        }
    }
    return false;
}

// Check all possible row wins, return true if there is one, return false otherwise
bool row_win (char board[], char player) {
    // Loop through each row
    for (int k=0; k<=35; k += 7) {
        // Check the current row for wins
        for (int i=k; (i+3)%7!=0; i++) {
            if ((board[i] == player) && (board[i+1] == player) && (board[i+2] == player) && (board[i+3] == player)) {
                return true;
            }
        }
    }
    return false;
}

// Check all possible diagonal wins, return true if there is one, return false otherwise
bool diagonal_win (char board[], char player) {
    // Loop through each right to left diagonal
    for (int k=3; k<=17; k += 7) {
        // Loop through the current right to left diagonal
        for (int i=k; i%7!=0; i++) {
            if ((board[i] == player) && (board[i+6] == player) && (board[i+12] == player) && (board[i+18] == player)) {
                return true;
            }
        }
    }
    // Loop through each left to right diagonal
    for (int k=0; k<=14; k += 7) {
        // Loop through the current left to right diagonal
        for (int i=k; (i+3)%7!=0; i++) {
            if ((board[i] == player) && (board[i+8] == player) && (board[i+16] == player) && (board[i+24] == player)) {
                return true;
            }
        }
    }
    return false;
}

// Return true if the board is full, return false otherwise
bool tie () {
    if ((column_A == -1) &&
        (column_B == -1) &&
        (column_C == -1) &&
        (column_D == -1) &&
        (column_E == -1) &&
        (column_F == -1) &&
        (column_G == -1)) {
        return true;
    } else {
        return false;
    }
}

int main () {
    // Create an empty board
    char board[42];
    for (int i = 0; i < 43; i++) {
        board[i] = ' ';
    }

    printf("Welcome to Connect Four!\n");
    printf("Players take turns to drop a token into the board.\n");
    printf("The first to get 4 in a row (horizontal, vertical or diagonal) wins!\n");
    printf("Use letters A-G to choose a column to place your token.\n");

    // Player R starts the game
    char current_player = 'R';
    print_choices (board);

    // Play one round of the game, check for a win or tie, and exit the loop if either is found
    // If not, switch the player and continue
    while (1) {
        char choice = column_choice();
        int index = input_index (choice);

        if (current_player == 'R') {
            board[index] = 'R';
        } else {
            board[index] = 'Y';
        }

        print_choices (board);

        if ((column_win (board, current_player)) || (row_win(board, current_player)) || (diagonal_win (board, current_player))) {
            printf("Player %c won!\n", current_player);
            break;
        }

        if (tie()) {
            printf("It's a tie!\n");
            break;
        }

        // Switch the player
        if (current_player == 'R') {
            current_player = 'Y';
        } else {
            current_player = 'R';
        }
    }
}