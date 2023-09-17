// COMP1511 Week 5 Lecture 2
// Bubble Tea Adventure!
// Tammy Zhong

#include <stdio.h>

#define MAP_ROWS 6
#define MAP_COLUMNS 8

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

enum entity {
    PERSON,
    BOBA,
    FOOTPRINT_UP,
    FOOTPRINT_DOWN,
    FOOTPRINT_LEFT,
    FOOTPRINT_RIGHT,
    EMPTY
};

enum place_type {
    SHOP,
    GYM,
    HOME,
    UNDEVELOPED
};

struct location {
    enum entity entity;
    enum place_type place;
};

// struct position {

// }

void initialise_map(struct location map[MAP_ROWS][MAP_COLUMNS]);
void print_map(struct location map[MAP_ROWS][MAP_COLUMNS]);
void print_location(struct location location, int place_print);

int check_vaid_inputs(int row, int col);
void find_boba(struct location map[MAP_ROWS][MAP_COLUMNS], int home_row, int home_col, int shop_row, int shop_col);

int main(void) {

    struct location map[MAP_ROWS][MAP_COLUMNS];

    initialise_map(map);

    // TODO...
    int home_row, home_col;
    printf("Where is my home: ");
    scanf("%d %d", &home_row, &home_col);

    int shop_row, shop_col;
    printf("Where is the boba shop: ");
    scanf("%d %d", &shop_row, &shop_col);

    if (check_vaid_inputs(home_row, home_col) == 0
        || check_vaid_inputs(shop_row, shop_col) == 0) {
        printf("Inputs are not valid\n");
        return 1;
    }

    char want_gym;
    printf("Do you want to build a gym? (y/n): ");
    scanf(" %c", &want_gym);
    if (want_gym == 'y') {
        printf("Where do you want the gym? ");
        int gym_row, gym_col;
        scanf("%d %d", &gym_row, &gym_col);

        int row = gym_row;
        while (row < gym_row + 2) {
            int col = gym_col;
            while (col < gym_col + 2) {
                map[row][col].place = GYM;
                col++;
            }
            row ++;
        }
    }






    map[home_row][home_col].entity = PERSON;
    map[home_row][home_col].place = HOME;

    map[shop_row][shop_col].entity = BOBA;
    map[shop_row][shop_col].place = SHOP;
    printf("Print initial map: \n");
    print_map(map);

    find_boba(map, home_row, home_col, shop_row, shop_col);

    return 0;
}

// return 1 when is valid 
// return 0 when is not valid
int check_vaid_inputs(int row, int col) {
    return row >= 0 && row < MAP_ROWS && col >= 0 && col < MAP_COLUMNS;
}

// explore until person find boba
void find_boba(struct location map[MAP_ROWS][MAP_COLUMNS], int home_row, int home_col, int shop_row, int shop_col) {
    int current_row = home_row;
    int current_col = home_col;
    char direction_input;
    while(current_row != shop_row || current_col != shop_col && scanf(" %c", &direction_input)) {
        if (direction_input == UP) {
            map[current_row][current_col].entity = FOOTPRINT_UP;
            current_row--;
        } else if (direction_input == LEFT) {
            map[current_row][current_col].entity = FOOTPRINT_LEFT;
            current_col--;
        } else if (direction_input == DOWN) {
            map[current_row][current_col].entity = FOOTPRINT_DOWN;
            current_row++;
        } else if (direction_input == RIGHT) {
            map[current_row][current_col].entity = FOOTPRINT_RIGHT;
            current_col++;
        }
        map[current_row][current_col].entity = PERSON;
        printf("Updated map: \n");
        print_map(map);
    }
}



// STARTER FUNCTIONS BELOW THIS POINT:
// initialises the map with empty undeveloped areas
void initialise_map(struct location map[MAP_ROWS][MAP_COLUMNS]) {
    int row = 0;
    while (row < MAP_ROWS) {
        int col = 0;
        while (col < MAP_COLUMNS) {
            map[row][col].place = UNDEVELOPED;
            map[row][col].entity = EMPTY;
            col++;
        }
        row++;
    }
}

// print out the map
void print_map(struct location map[MAP_ROWS][MAP_COLUMNS]) {
    int row = 0;
    while (row < MAP_ROWS * 2) {
        int col = 0;
        while (col < MAP_COLUMNS) {
            print_location(map[row / 2][col], row % 2);
            col++;
        }
        row++;
        printf("\n");
    }

}

// prints specific location on map (used by print_map)
void print_location(struct location location, int place_print) {
    if (place_print) {
        if (location.place == SHOP) {
            printf(" S ");
        } else if (location.place == HOME) {
            printf(" H ");
        } else if (location.place == GYM) {
            printf(" G ");
        } else if (location.place == UNDEVELOPED) {
            printf(" . ");
        } else {
            printf(" ? ");
        }
    } else {

        if (location.entity == EMPTY) {
            printf("   ");
        } else if (location.entity == PERSON) {
            printf("(P)");
        } else if (location.entity == BOBA) {
            printf("(B)");
        } else if (location.entity == FOOTPRINT_UP) {
            printf("(^)");
        } else if (location.entity == FOOTPRINT_RIGHT) {
            printf("(>)");
        } else if (location.entity == FOOTPRINT_DOWN) {
            printf("(v)");
        } else if (location.entity == FOOTPRINT_LEFT) {
            printf("(<)");
        } else {
            printf(" ? ");
        }
    }
}