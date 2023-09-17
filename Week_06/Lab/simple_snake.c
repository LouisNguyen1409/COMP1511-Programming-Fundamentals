// A simpler version of the famous Snake game!
//
// Written by Rory Golledge (z5308772) on 3/3/23
// Modified by Dinh Minh Nhat Nguyen (z5428797) on 16/03/2023
//

#include <stdio.h>

#define SIZE 8
#define UP 'u'
#define DOWN 'd'
#define LEFT 'l'
#define RIGHT 'r'

enum land {
    NOT_VISITED,
    VISITED,
    SNAKE,
    APPLE
};

struct coordinate {
    int row;
    int col;
};

void initialise_map(enum land map[SIZE][SIZE]);
void print_map(enum land map[SIZE][SIZE]);
void moving_snake (int snake_row, int snake_col, int apple_row, int apple_col
, enum land map[SIZE][SIZE]);

int main(void) {
    enum land map[SIZE][SIZE];
    initialise_map(map);

    printf("Welcome to Snake!\n");

    // TODO: Complete the program
    struct coordinate apple;
    struct coordinate snake;
    printf("Please enter apple location: ");
    scanf("%d %d", &apple.row, &apple.col);
    map[apple.row][apple.col] = APPLE;
    printf("Please enter snake location: ");
    scanf("%d %d", &snake.row, &snake.col);
    map[snake.row][snake.col] = SNAKE;
    print_map(map);
    moving_snake (snake.row, snake.col, apple.row, apple.col, map);
    printf("Chomp!\n");

    return 0;
}

void moving_snake (int snake_row, int snake_col, int apple_row, int apple_col
, enum land map[SIZE][SIZE]
) {
    while (snake_row != apple_row || snake_col != apple_col) {
        char direction;
        scanf(" %c", &direction);
        if (direction == UP) {
            map[snake_row][snake_col] = VISITED;
            snake_row --;
        } else if (direction == DOWN) {
            map[snake_row][snake_col] = VISITED;
            snake_row ++;
        } else if (direction == LEFT) {
            map[snake_row][snake_col] = VISITED;
            snake_col --;
        } else if (direction == RIGHT) {
            map[snake_row][snake_col] = VISITED;
            snake_col ++;
        }
        map[snake_row][snake_col] = SNAKE;
        print_map(map);
    }
}


/**
 * Initialises the given `map` such that all tiles are `NOT_VISITED`
 * 
 * Parameters:
 *     map - The map to initialise
 * 
 * Returns:
 *     Nothing
 */
void initialise_map(enum land map[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            map[row][col] = NOT_VISITED;
        }
    }
}

/**
 * Prints the given `map` such that all enum values are printed as nice
 * characters.
 * 
 * Parameters:
 *     map - The map to print out
 * 
 * Returns:
 *     Nothing
 */
void print_map(enum land map[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (map[row][col] == NOT_VISITED) {
                printf(". ");
            } else if (map[row][col] == VISITED) {
                printf("- ");
            } else if (map[row][col] == SNAKE) {
                printf("S ");
            } else if (map[row][col] == APPLE) {
                printf("A ");
            }
        }
        printf("\n");
    }
}
