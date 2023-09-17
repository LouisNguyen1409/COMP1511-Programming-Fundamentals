#include <stdio.h>

#define SIZE 5
#define TRUE 1
#define FALSE 0

// Function Prototype
int did_player_fill_row(char player, char board[SIZE][SIZE]);
int did_player_fill_column(char player, char board[SIZE][SIZE]);
int did_player_fill_diagonal(char player, char board[SIZE][SIZE]);
int did_player_fill_secondary_diagonal(char player, char board[SIZE][SIZE]);
int did_player_win(char player, char board[SIZE][SIZE]);

int main(void) {
    char no_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {'X', ' ', ' ', ' ', 'O'},
    };

    char x_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {' ', 'X', ' ', ' ', 'O'},
    };
    char o_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'O', 'O', 'O', 'O'},
        {'X', 'X', ' ', ' ', 'O'},
    };

    if (did_player_win('X', o_wins_board)) {
        printf("X Won This Board!\n");
    } else if (did_player_win('O', o_wins_board)) {
        printf("O Won This Board!\n");
    } else {
        printf("Nobody has won this board!\n");
    }
}

// Function Implementation:
// Determines whether a given player has won the game of tictactoe
// by getting SIZE tokens in a row, in any direction.
int did_player_win(char player, char board[SIZE][SIZE]) {
    // TODO Implement this function.
    return did_player_fill_row(player,board)
        ||did_player_fill_column(player,board)
        ||did_player_fill_diagonal(player,board)
        ||did_player_fill_secondary_diagonal(player,board);
}

int did_player_fill_row(char player, char board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        int has_player_filled_row = TRUE;
        for (int col = 0; col < SIZE; col++) {
            if (player != board[row][col]) {
                has_player_filled_row = FALSE;
            }
        }
        if (has_player_filled_row) {
            return TRUE;
        }
    }
    return FALSE;
}

int did_player_fill_column(char player, char board[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        int has_player_filled_col = TRUE;
        for (int row = 0; row < SIZE; row++) {
            if (player != board[row][col]) {
                has_player_filled_col = FALSE;
            }
        }
        if (has_player_filled_col) {
            return TRUE;
        }
    }
    return FALSE;
}

int did_player_fill_diagonal(char player, char board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        if (player != board[row][row]) {
            return FALSE;
        }
    }
    return TRUE;
}

int did_player_fill_secondary_diagonal(char player, char board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        if (player != board[row][SIZE - 1 - row]) {
            return FALSE;
        }
    }
    return TRUE;
}