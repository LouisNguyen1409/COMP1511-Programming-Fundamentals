// cs_defence
//
// This program was written by Dinh Minh Nhat Nguyen (z5428797)
// on 11/03/2023
//
// CS Defence is the game inspired by a specific genre of games that boomed 
// in the late 2000s

#include <stdio.h>

#define MAP_ROWS 6
#define MAP_COLUMNS 12

#define RIGHT 'r'
#define LEFT 'l'
#define UP 'u'
#define DOWN 'd'

#define SPAWN_ENEMIES 'e'
#define SPAWN_TOWER 't'
#define MOVE_ENEMIES 'm'
#define TOWER_UPGRADE 'u'
#define ATTACK_ENEMIES 'a'
#define RAIN 'r'
#define FLOODING 'f'
#define TELEPORT 'c'

////////////////////////////////////////////////////////////////////////////////
/////////////////////////// USER DEFINED TYPES  ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
enum land_type {
    GRASS,
    WATER,
    PATH_START,
    PATH_END,
    PATH_UP,
    PATH_RIGHT,
    PATH_DOWN,
    PATH_LEFT,
    TELEPORTER
};

enum entity {
    EMPTY,
    ENEMY,
    BASIC_TOWER,
    POWER_TOWER,
    FORTIFIED_TOWER,
};

struct tile {
    enum land_type land;
    enum entity entity;

    int n_enemies;
};

struct coordinate {
    int n_enemies;
    int row;
    int col;
};

struct teleporter {
    int first_tele_row;
    int first_tele_col;
    int second_tele_row;
    int second_tele_col;
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////  YOUR FUNCTION PROTOTYPE  /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: Put your function prototypes here
void create_lake(struct coordinate lake, int height, int width
, struct tile map[MAP_ROWS][MAP_COLUMNS]);
int valid_point(struct coordinate point);
int valid_lake(struct coordinate lake, int height, int width);
void create_path(struct coordinate path, struct coordinate end_point
, struct tile map[MAP_ROWS][MAP_COLUMNS]);
void spawn_enemies(struct coordinate start_point
, struct tile map[MAP_ROWS][MAP_COLUMNS]);
int spawn_tower(int money, struct tile map[MAP_ROWS][MAP_COLUMNS]);
int tower_restriction(int money, struct coordinate tower
, struct tile map[MAP_ROWS][MAP_COLUMNS]);
int create_enemies_info(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate enemies_info[MAP_ROWS * MAP_COLUMNS], char first_path);
int next_row(int row, int col, struct tile map[MAP_ROWS][MAP_COLUMNS]
, int *second_row);
int next_col(int row, int col, struct tile map[MAP_ROWS][MAP_COLUMNS]
, int *second_col);
void print_end_enemies(int enemies_reach_end);
void update_location(int row, int col, struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate enemies_info[MAP_ROWS * MAP_COLUMNS], int num_enemies);
void clear_location(int row, int col, struct tile map[MAP_ROWS][MAP_COLUMNS]);
void move_enemies(int step, int *start_live, int *enemies_reach_end
, struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate enemies_info[MAP_ROWS * MAP_COLUMNS], int num_of_enemies
, int *second_row, int *second_col, struct tile temp_map[MAP_ROWS][MAP_COLUMNS]);
void final_check_tower(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate tower_up, int *start_money);
void second_check_tower(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate tower_up, int *start_money);
void first_check_tower(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate tower_up, int *start_money);
int scan_top_bot(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate enemies_info[MAP_ROWS * MAP_COLUMNS], int num_of_enemies);
int scan_bot_top(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate enemies_info[MAP_ROWS * MAP_COLUMNS], int num_of_enemies);
void identify_tower (struct tile map[MAP_ROWS][MAP_COLUMNS]
, int num_of_attack, int *enemies_destroy);
void create_attack_range(int row, int col
, struct tile map[MAP_ROWS][MAP_COLUMNS], int num_of_attack
, int *enemies_destroy, int power, int range_attack);
void attack_enemies(struct tile map[MAP_ROWS][MAP_COLUMNS], int num_of_attack
, int row_range, int col_range, int *enemies_destroy, int power);
int vaid_water_block(int row, int col, int min_limit_row, int max_limit_row
, int min_limit_col, int max_limit_col);
void create_water_block(struct tile map[MAP_ROWS][MAP_COLUMNS], int row
, int col);
void water_block_1st_quadrant(int row_offset, int column_offset, int row_spacing
, int column_spacing, struct tile map[MAP_ROWS][MAP_COLUMNS]);
void water_block_2nd_quadrant(int row_offset, int column_offset, int row_spacing
, int column_spacing, struct tile map[MAP_ROWS][MAP_COLUMNS]);
void water_block_3rd_quadrant(int row_offset, int column_offset, int row_spacing
, int column_spacing, struct tile map[MAP_ROWS][MAP_COLUMNS]);
void water_block_4th_quadrant(int row_offset, int column_offset, int row_spacing
, int column_spacing, struct tile map[MAP_ROWS][MAP_COLUMNS]);
void flood (int row, int col, struct tile map[MAP_ROWS][MAP_COLUMNS]);
int scan_water_block(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate water_location[MAP_ROWS * MAP_COLUMNS]);
void flood_all_water_block(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate water_location[MAP_ROWS * MAP_COLUMNS]
, int num_of_water_block);
void create_temp_map(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct tile temp_map[MAP_ROWS][MAP_COLUMNS]);
void update_main_map(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct tile clone_map[MAP_ROWS][MAP_COLUMNS]);
void create_tele(struct coordinate fist_teleporter, struct coordinate second_teleporter
, struct tile map[MAP_ROWS][MAP_COLUMNS], int first_row, int first_col
, int *second_row, int *second_col, struct tile temp_map[MAP_ROWS][MAP_COLUMNS]
, struct tile clone_map[MAP_ROWS][MAP_COLUMNS], struct coordinate start_point);
int tele_not_path(struct tile map[MAP_ROWS][MAP_COLUMNS], int first_row
, int first_col, int second_row, int second_col);
int tele_on_path(struct tile map[MAP_ROWS][MAP_COLUMNS], int first_row
, int first_col, int second_row, int second_col);
void find_start_tele(struct tile clone_map[MAP_ROWS][MAP_COLUMNS]
, int *tracking_row, int *tracking_col, int *second_row, int *second_col);
void find_end_tele(struct tile clone_map[MAP_ROWS][MAP_COLUMNS]
, int *tracking_row, int *tracking_col, int *second_row, int *second_col);
void scan_live_money(int *start_live, int *start_money);
void scan_initial_enemies(int *inital_enemies);
void check_initial_enemies(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate start_point, int inital_enemies);
void check_valid_lake(struct coordinate lake, int height, int width
, struct tile map[MAP_ROWS][MAP_COLUMNS]);
void minus_money(int *start_money, struct tile map[MAP_ROWS][MAP_COLUMNS]);
void valid_tower(struct coordinate tower_up
, struct tile map[MAP_ROWS][MAP_COLUMNS], int *start_money);
void live_check(int start_live);
void scan_start_end_point(struct coordinate *start_point
, struct coordinate *end_point, struct tile map[MAP_ROWS][MAP_COLUMNS]);
void scan_lake(struct coordinate *lake, int *height, int *width);
////////////////////////////////////////////////////////////////////////////////
////////////////////// PROVIDED FUNCTION PROTOTYPE  ////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void initialise_map(struct tile map[MAP_ROWS][MAP_COLUMNS]);
void print_map(struct tile map[MAP_ROWS][MAP_COLUMNS], int lives, int money);
void print_tile(struct tile tile, int entity_print);

int main(void) {
    // This `map` variable is a 2D array of `struct tile`s.
    // It is `MAP_ROWS` x `MAP_COLUMNS` in size (which is 6x12 for this
    // assignment!)
    struct tile map[MAP_ROWS][MAP_COLUMNS];
    // create temp map
    struct tile temp_map[MAP_ROWS][MAP_COLUMNS];
    //create clone map
    struct tile clone_map[MAP_ROWS][MAP_COLUMNS];
    // This will initialise all tiles in the map to have GRASS land and EMPTY
    // entity values.
    initialise_map(map);
    // TODO: Start writing code here!
    // TODO: Stage 1.1 - Scan in lives, money and start/ending points, then
    // print out the map!
    int start_live, start_money;
    scan_live_money(&start_live, &start_money);

    struct coordinate start_point;
    struct coordinate end_point;
    scan_start_end_point(&start_point, &end_point, map);
    print_map(map, start_live, start_money);
    // TODO: Stage 1.2 - Scan in the initial enemies. Make sure you change the
    // `entity` at the starting position to be ENEMY, and that you update the
    // `n_enemies` value at that position to be this scanned value!
    int inital_enemies;
    scan_initial_enemies(&inital_enemies);
    check_initial_enemies(map, start_point, inital_enemies);
    print_map(map, start_live, start_money);

    // Create Lake
    struct coordinate lake;
    int height, width;
    scan_lake(&lake, &height, &width);
    check_valid_lake(lake, height, width, map);
    print_map(map, start_live, start_money);

    // Adding Path
    struct coordinate path;
    path.row = start_point.row;
    path.col = start_point.col;
    create_path(path, end_point, map);
    print_map(map, start_live, start_money);

    // Command Loop
    char command;
    int first_row, first_col;
    int second_row = -1;
    int second_col = -1;
    create_temp_map(map, temp_map);
    printf("Enter Command: ");
    while (start_live > 0 && scanf(" %c", &command) == 1) {
        // command spawn enemies
        if (command == SPAWN_ENEMIES) {
            spawn_enemies(start_point, map);
        }
        // command add tower
        if (command == SPAWN_TOWER) {
            minus_money(&start_money, map);
        }
        // command move enemies
        if (command == MOVE_ENEMIES) {
            int step;
            scanf("%d", &step);

            struct coordinate enemies_info[MAP_ROWS * MAP_COLUMNS];
            char first_path = map[start_point.row][start_point.col].land;
            int num_of_enemies = create_enemies_info(map, enemies_info, first_path);
            int enemies_reach_end = 0;

            while (num_of_enemies > -1) {
                move_enemies(step, &start_live, &enemies_reach_end, map
                , enemies_info, num_of_enemies, &second_row, &second_col, temp_map);
                num_of_enemies--;
            }
            print_end_enemies(enemies_reach_end);
        }
        // command tower upgrade
        if (command == TOWER_UPGRADE) {
            struct coordinate tower_up;
            scanf("%d %d", &tower_up.row, &tower_up.col);
            valid_tower(tower_up, map, &start_money);
        }
        // command attack enemies
        if (command == ATTACK_ENEMIES) {
            int num_of_attack;
            scanf("%d", &num_of_attack);
            int enemies_destroy = 0;
            identify_tower(map, num_of_attack, &enemies_destroy);
            start_money += 5 * enemies_destroy;
            printf("%d enemies destroyed!\n", enemies_destroy);
        }
        // command to make rain
        if (command == RAIN) {
            int row_spacing, column_spacing, row_offset, column_offset;
            scanf("%d %d %d %d", &row_spacing, &column_spacing, &row_offset
            , &column_offset);
            water_block_1st_quadrant(row_offset, column_offset, row_spacing
            , column_spacing, map);
            water_block_2nd_quadrant(row_offset, column_offset, row_spacing
            , column_spacing, map);
            water_block_3rd_quadrant(row_offset, column_offset, row_spacing
            , column_spacing, map);
            water_block_4th_quadrant(row_offset, column_offset, row_spacing
            , column_spacing, map);
        }
        //command to cause flooding
        if (command == FLOODING) {
            int flood_times;
            scanf("%d", &flood_times);
            struct coordinate water_location[MAP_ROWS * MAP_COLUMNS];
            int num_of_water_block = -1;
            while (flood_times > 0) {
                num_of_water_block = scan_water_block(map, water_location);
                flood_all_water_block(map, water_location, num_of_water_block);
                flood_times --;
            }
        }
        // command to create teleporter
        if (command == TELEPORT) {
            scanf("%d %d %d %d", &first_row, &first_col, &second_row, &second_col);
            struct coordinate fist_teleporter;
            fist_teleporter.row = first_row;
            fist_teleporter.col = first_col;
            struct coordinate second_teleporter;
            second_teleporter.row = second_row;
            second_teleporter.col = second_col;
            create_tele(fist_teleporter, second_teleporter, map, first_row
            , first_col, &second_row, &second_col, temp_map, clone_map
            , start_point);
        }
        // This will print out the map
        print_map(map, start_live, start_money);
        // This will check for the lives is enough to continue or not
        live_check(start_live);
    }
    
    printf("\nGame Over!\n");
    

}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  YOUR FUNCTIONS //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: Put your functions here

// Scan in live and money
void scan_live_money(int *start_live, int *start_money) {
    printf("Starting Lives: ");
    scanf("%d", start_live);
    printf("Starting Money($): ");
    scanf("%d", start_money);
}

// Scan in initial enemies
void scan_initial_enemies(int *inital_enemies) {
    printf("Initial Enemies: ");
    scanf("%d", inital_enemies);
}

// Check initial enemies valid
void check_initial_enemies(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate start_point, int inital_enemies) {
    if (inital_enemies > 0) {
        map[start_point.row][start_point.col].entity = ENEMY;
        map[start_point.row][start_point.col].n_enemies = inital_enemies;
    }
}

// Scan in lake coordinate
void scan_lake(struct coordinate *lake, int *height, int *width) {
    printf("Enter Lake: ");
    scanf("%d %d %d %d", &lake->row, &lake->col, height, width);
}


// Scan in starting point and end point
void scan_start_end_point(struct coordinate *start_point
, struct coordinate *end_point, struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    printf("Start Point: ");
    scanf("%d %d", &start_point->row, &start_point->col);
    map[start_point->row][start_point->col].land = PATH_START;
    printf("End Point: ");
    scanf("%d %d", &end_point->row, &end_point->col);
    map[end_point->row][end_point->col].land = PATH_END;
}

// Check lake and print error
void check_valid_lake(struct coordinate lake, int height, int width
, struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    if (valid_point(lake) == 1 && valid_lake(lake, height, width) == 1) {
        create_lake(lake, height, width, map);
    } else {
        printf("Error: Lake out of bounds, ignoring...\n");
    }
}

// Minus money when build tower
void minus_money(int *start_money, struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    if (spawn_tower(*start_money, map) == 1) {
        *start_money -= 200;
    }
}
// This will return 1 if the point is valid 
// and return 0 if the point is not valid.
int valid_point(struct coordinate point) {
    return point.row >= 0 && point.col >= 0 && 
    point.col < MAP_COLUMNS && point.row < MAP_ROWS;
}

// This will return 1 if the lake is fit inside the map
// and return 0 if the lake is not fit in the map.
int valid_lake(struct coordinate lake, int height, int width) {
    int lake_height = lake.row + height;
    int lake_width = lake.col + width;
    return lake_height >= 0 && lake_height <= MAP_ROWS &&
    lake_width >= 0 && lake_width <= MAP_COLUMNS;
}

// This will create a lake.
void create_lake(struct coordinate lake, int height, int width
, struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    int lake_height = lake.row + height;
    int lake_width = lake.col + width;
    for (int row = lake.row; row < lake_height; row++) {
        for (int col = lake.col; col < lake_width; col++) {
            map[row][col].land = WATER;
        }
    }
}

// This will create the path on the map.
void create_path(struct coordinate path, struct coordinate end_point
, struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    printf("Enter Path: ");
    char direction;
    while (!(path.row == end_point.row && path.col == end_point.col)) {
        scanf(" %c", &direction);
        if (direction == RIGHT) {
            map[path.row][path.col].land = PATH_RIGHT; 
            path.col ++;
        } else if (direction == LEFT) {
            map[path.row][path.col].land = PATH_LEFT; 
            path.col --;
        } else if (direction == UP) {
            map[path.row][path.col].land = PATH_UP;
            path.row --; 
        } else if (direction == DOWN) {
            map[path.row][path.col].land = PATH_DOWN;
            path.row ++; 
        }
    }
}

// This will spawn enemies
void spawn_enemies(struct coordinate start_point
, struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    int spawn_enemies;
    scanf("%d", &spawn_enemies);
    map[start_point.row][start_point.col].entity = ENEMY;
    map[start_point.row][start_point.col].n_enemies += spawn_enemies;
}

// This will spawn tower
int spawn_tower(int money, struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    struct coordinate tower;
    scanf("%d %d", &tower.row, &tower.col);
    if (tower_restriction(money, tower, map) == 1) {
        map[tower.row][tower.col].entity = BASIC_TOWER;
        printf("Tower successfully created!\n");
        return 1;
    } else {
        printf("Error: Tower creation unsuccessful. Make sure you have at least"
        " $200 and that the tower is placed on a grass block with no entity.\n");
        return 0;
    }
    

}

// The restriction of tower
int tower_restriction(int money, struct coordinate tower
, struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    return money >= 200 && valid_point(tower) &&
            map[tower.row][tower.col].land == GRASS && 
            map[tower.row][tower.col].entity == EMPTY;
}

// Check tower inside the map
void valid_tower(struct coordinate tower_up
, struct tile map[MAP_ROWS][MAP_COLUMNS], int *start_money) {
    if (valid_point(tower_up) == 1) {
        first_check_tower(map, tower_up, start_money);
    } else {
        printf("Error: Upgrade target is out-of-bounds.\n");
    }
} 
// This will scan the map from right bottom to top left
int scan_top_bot(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate enemies_info[MAP_ROWS * MAP_COLUMNS], int num_of_enemies) {
    for (int row = 0; row < MAP_ROWS; row++) {
        for (int col = 0; col < MAP_COLUMNS; col++) {
            if (map[row][col].entity == ENEMY) {
                num_of_enemies ++;
                enemies_info[num_of_enemies].row = row;
                enemies_info[num_of_enemies].col = col;
                enemies_info[num_of_enemies].n_enemies = map[row][col].n_enemies;
            }
        }
    }
    return num_of_enemies;
}

// This will scan the map from top left to right bottom
int scan_bot_top(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate enemies_info[MAP_ROWS * MAP_COLUMNS], int num_of_enemies) {
    for (int row = MAP_ROWS - 1; row >= 0; row--) {
        for (int col = MAP_COLUMNS - 1; col >= 0; col--) {
            if (map[row][col].entity == ENEMY) {
                num_of_enemies ++;
                enemies_info[num_of_enemies].row = row;
                enemies_info[num_of_enemies].col = col;
                enemies_info[num_of_enemies].n_enemies = map[row][col].n_enemies;
            }
        }
    }
    return num_of_enemies;
}

// Create a struct in array of enemies information
int create_enemies_info(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate enemies_info[MAP_ROWS * MAP_COLUMNS], char first_path) {
    int num_of_enemies = -1;
    if (first_path == PATH_RIGHT || first_path == PATH_DOWN) {
        num_of_enemies = scan_top_bot(map, enemies_info, num_of_enemies);
    } else if (first_path == PATH_UP || first_path == PATH_LEFT) {
        num_of_enemies = scan_bot_top(map, enemies_info, num_of_enemies);
    }
    return num_of_enemies;
}

// next column value
int next_col(int row, int col, struct tile map[MAP_ROWS][MAP_COLUMNS], int *second_col) {
    if (map[row][col].land == PATH_RIGHT) {
        col ++;
    } else if (map[row][col].land == PATH_LEFT) {
        col --;
    } else if (map[row][col].land == TELEPORTER) {
        col = *second_col;
    }
    return col;
}

// next row value
int next_row(int row, int col, struct tile map[MAP_ROWS][MAP_COLUMNS], int *second_row) {
    if (map[row][col].land == PATH_UP) {
        row --;
    } else if (map[row][col].land == PATH_DOWN) {
        row ++;
    } else if (map[row][col].land == TELEPORTER) {
        row = *second_row;
    }
    return row;
}

// print message of enemies' status
void print_end_enemies(int enemies_reach_end) {
    if (enemies_reach_end != 0) {
        printf("%d enemies reached the end!\n", enemies_reach_end);
    } else {
        printf("0 enemies reached the end!\n");
    }
}

// clear the title
void clear_location(int row, int col, struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    map[row][col].entity = EMPTY; 
    map[row][col].n_enemies = 0;
}

// update the title
void update_location(int row, int col, struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate enemies_info[MAP_ROWS * MAP_COLUMNS], int num_enemies) {
    map[row][col].entity = ENEMY; 
    map[row][col].n_enemies = enemies_info[num_enemies].n_enemies;
}

// moving the enemies to new location
void move_enemies(int step, int *start_live, int *enemies_reach_end
, struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate enemies_info[MAP_ROWS * MAP_COLUMNS], int num_of_enemies
, int *second_row, int *second_col, struct tile temp_map[MAP_ROWS][MAP_COLUMNS]) {
    int temp_step = step;
    int current_row = enemies_info[num_of_enemies].row;
    int current_col = enemies_info[num_of_enemies].col;
    while (temp_step > 0 && map[current_row][current_col].land != PATH_END) {
        int current_enemies = map[current_row][current_col].n_enemies;
        if (enemies_info[num_of_enemies].n_enemies == current_enemies) {
            clear_location(current_row, current_col, map);
        }
        int old_row = current_row;
        int old_col = current_col;
        if (old_row == *second_row && old_col == *second_col) {
            current_col = next_col(old_row, old_col, temp_map, second_col);
            current_row = next_row(old_row, old_col, temp_map, second_row);
        } else {
            current_col = next_col(old_row, old_col, map, second_col);
            current_row = next_row(old_row, old_col, map, second_row);
        }

        update_location(current_row, current_col, map, enemies_info
        , num_of_enemies);
        temp_step--;
    }

    if (map[current_row][current_col].land == PATH_END) {
        *start_live -= map[current_row][current_col].n_enemies;
        *enemies_reach_end += map[current_row][current_col].n_enemies;
        map[current_row][current_col].n_enemies = 0;
        map[current_row][current_col].entity = EMPTY;
    } 
}

// This will check for enough money and upgrade the tower
void final_check_tower(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate tower_up, int *start_money) {
    if (map[tower_up.row][tower_up.col].entity == BASIC_TOWER && 
        *start_money >= 300) {
        map[tower_up.row][tower_up.col].entity = POWER_TOWER;
        *start_money -= 300;
        printf("Upgrade Successful!\n");
    } else if (map[tower_up.row][tower_up.col].entity == POWER_TOWER &&
                *start_money >= 500) {
        map[tower_up.row][tower_up.col].entity = FORTIFIED_TOWER;
        *start_money -= 500;
        printf("Upgrade Successful!\n");
    } else {
        printf("Error: Insufficient Funds.\n");
    }
}

// This will check for if the tower is max upgrade
void second_check_tower(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate tower_up, int *start_money) {
    if (map[tower_up.row][tower_up.col].entity != FORTIFIED_TOWER) {
        final_check_tower(map, tower_up, start_money);
    } else {
        printf("Error: Tower cannot be upgraded further.\n");
    }
}

// This will check for a place have or have not got a tower
void first_check_tower(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate tower_up, int *start_money) {
    if (map[tower_up.row][tower_up.col].entity == BASIC_TOWER ||
        map[tower_up.row][tower_up.col].entity == POWER_TOWER ||
        map[tower_up.row][tower_up.col].entity == FORTIFIED_TOWER) {
        second_check_tower(map, tower_up, start_money);
    } else {
        printf("Error: Upgrade target contains no tower entity.\n");
    }
}

// This will identify which type of tower that attack
void identify_tower (struct tile map[MAP_ROWS][MAP_COLUMNS]
, int num_of_attack, int *enemies_destroy) {
    int power = 0;
    int range_attack = 0;
    for (int row = 0; row < MAP_ROWS; row++) {
        for (int col = 0; col < MAP_COLUMNS; col++) {
            if (map[row][col].entity == BASIC_TOWER) {
                power = 1;
                range_attack = 1;
                create_attack_range(row, col, map, num_of_attack, enemies_destroy
                , power, range_attack);
            } else if (map[row][col].entity == POWER_TOWER) {
                power = 2;
                range_attack = 1;
                create_attack_range(row, col, map, num_of_attack, enemies_destroy
                , power, range_attack);
            } else if (map[row][col].entity == FORTIFIED_TOWER) {
                power = 3;
                range_attack = 2;
                create_attack_range(row, col, map, num_of_attack, enemies_destroy
                , power, range_attack);
            }
        }
    }
}

// This will create the range that the tower can attack
void create_attack_range(int row, int col
, struct tile map[MAP_ROWS][MAP_COLUMNS], int num_of_attack
, int *enemies_destroy, int power, int range_attack) {
    int top_row = row - range_attack;
    int top_col = col - range_attack;
    int bot_row = row + range_attack;
    int bot_col = col + range_attack;
    struct coordinate range;
    for (int row_range = top_row; row_range <= bot_row; row_range++) {
        for (int col_range = top_col; col_range <= bot_col; col_range++) {
            range.row = row_range;
            range.col = col_range;
            if (valid_point(range) == 1) {
                attack_enemies(map, num_of_attack, row_range, col_range
                , enemies_destroy, power);
            }
        }
    }
}

// This will destroy the enemies and update the money
void attack_enemies(struct tile map[MAP_ROWS][MAP_COLUMNS], int num_of_attack
, int row_range, int col_range, int *enemies_destroy, int power) {
    if (map[row_range][col_range].entity != BASIC_TOWER && 
        map[row_range][col_range].entity != POWER_TOWER && 
        map[row_range][col_range].entity != FORTIFIED_TOWER) {
        if (map[row_range][col_range].n_enemies != 0) {
            map[row_range][col_range].n_enemies -= num_of_attack * power;

            if (map[row_range][col_range].n_enemies < 0) {
                *enemies_destroy += num_of_attack * power;
                *enemies_destroy += map[row_range][col_range].n_enemies;
                map[row_range][col_range].entity = EMPTY;
                map[row_range][col_range].n_enemies = 0;
            } else if (map[row_range][col_range].n_enemies == 0) {
                *enemies_destroy += num_of_attack * power;
                map[row_range][col_range].entity = EMPTY;
            } else {
                *enemies_destroy += num_of_attack * power;
            }
        }
    }
}

// Check for water block in map
int vaid_water_block(int row, int col, int min_limit_row, int max_limit_row
, int min_limit_col, int max_limit_col) {

    if ((row < 0 && col >= 0) &&
            (col < MAP_COLUMNS && row < MAP_ROWS)) {
        return row >= 0 && col >= min_limit_col && 
        col <= max_limit_col && row <= max_limit_row;
    } else if ((row >= 0 && col < 0) &&
            (col < MAP_COLUMNS && row < MAP_ROWS)) {
        return row >= min_limit_row && col >= 0 && 
        col <= max_limit_col && row <= max_limit_row;
    } else if ((row >= 0 && col >= 0) &&
            (col < MAP_COLUMNS && row >= MAP_ROWS)) {
        return row >= min_limit_row && col >= 0 && 
        col <= max_limit_col && row < MAP_ROWS;
    } else if ((row >= 0 && col >= 0) &&
            (col >= MAP_COLUMNS && row < MAP_ROWS)) {
        return row >= min_limit_row && col >= 0 && 
        col < MAP_COLUMNS && row <= max_limit_row;
    } else if (row < 0 && col < 0) {
        return row >= 0 && col >= 0 && 
        col <= max_limit_col && row <= max_limit_row;
    } else if (row >= 0 && col >= 0) {
        return row >= min_limit_row && col >= min_limit_col && 
        col <= max_limit_col && row <= max_limit_row;
    }
    return 0;

}

// This will make water block on 1st quadrant
void water_block_1st_quadrant(int row_offset, int column_offset, int row_spacing
, int column_spacing, struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    for (int row = row_offset; row >= 0; row -= row_spacing) {
        for (int col = column_offset; col < MAP_COLUMNS; col += column_spacing) {
            if (vaid_water_block(row, col, 0
            , row_offset, column_offset, MAP_COLUMNS - 1) == 1 &&
            map[row][col].land == GRASS) {
                create_water_block(map, row, col);
            }
        }
    }
}

// This will make water block on 2nd quadrant
void water_block_2nd_quadrant(int row_offset, int column_offset, int row_spacing
, int column_spacing, struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    for (int row = row_offset; row >= 0; row -= row_spacing) {
        for (int col = column_offset; col >= 0; col -= column_spacing) {
            if (vaid_water_block(row, col, 0
            , row_offset, 0, column_offset) == 1 && map[row][col].land == GRASS) {
                create_water_block(map, row, col);
            }
        }
    }
}

// This will make water block on 3rd quadrant
void water_block_3rd_quadrant(int row_offset, int column_offset, int row_spacing
, int column_spacing, struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    for (int row = row_offset; row < MAP_ROWS; row += row_spacing) {
        for (int col = column_offset; col >= 0; col -= column_spacing) {
            if (vaid_water_block(row, col
            , row_offset, MAP_ROWS - 1, 0, column_offset) == 1 &&
            map[row][col].land == GRASS) {
                create_water_block(map, row, col);
            }
        }
    }
}

// This will make water block on 4th quadrant
void water_block_4th_quadrant(int row_offset, int column_offset, int row_spacing
, int column_spacing, struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    for (int row = row_offset; row < MAP_ROWS; row += row_spacing) {
        for (int col = column_offset; col < MAP_COLUMNS; col += column_spacing) {
            if (vaid_water_block(row, col
            , row_offset, MAP_ROWS - 1, column_offset
            , MAP_COLUMNS - 1) == 1 && map[row][col].land == GRASS) {
                create_water_block(map, row, col);
            }
        }
    }
}

// This will create a water block on the map
void create_water_block(struct tile map[MAP_ROWS][MAP_COLUMNS], int row
, int col) {
    map[row][col].land = WATER;
    if (map[row][col].entity == BASIC_TOWER || 
        map[row][col].entity == POWER_TOWER) {
        map[row][col].entity = EMPTY;
    }
}

// This will flood the map
void flood (int row, int col, struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    struct coordinate water_cor;
    water_cor.row = row;
    water_cor.col = col;
    if (valid_point(water_cor) == 1 && map[row][col].land == GRASS) {
        create_water_block(map, row, col);
    }
}

// Scan water block on map
int scan_water_block(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate water_location[MAP_ROWS * MAP_COLUMNS]) {
    int num_of_water_block = -1;
    for (int row = 0; row < MAP_ROWS; row++) {
        for (int col = 0; col < MAP_COLUMNS; col++) {
            if (map[row][col].land == WATER) {
                num_of_water_block ++;
                water_location[num_of_water_block].row = row;
                water_location[num_of_water_block].col = col;
            }
        }
    }
    return num_of_water_block;
}

// Flood all the water block on the map
void flood_all_water_block(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct coordinate water_location[MAP_ROWS * MAP_COLUMNS]
, int num_of_water_block) {
    while (num_of_water_block > -1) {
        int water_row = water_location[num_of_water_block].row;
        int water_col = water_location[num_of_water_block].col;
        // top water
        flood(water_row - 1, water_col, map);
        // bot water
        flood(water_row + 1, water_col, map);
        // right water
        flood(water_row, water_col + 1, map);
        // left water
        flood(water_row, water_col - 1, map);
        num_of_water_block --;
    }
}

// This will create a temperary map
void create_temp_map(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct tile temp_map[MAP_ROWS][MAP_COLUMNS]) {
    for (int row = 0; row < MAP_ROWS; row++) {
        for (int col = 0; col < MAP_COLUMNS; col++) {
            temp_map[row][col].land = map[row][col].land;
            temp_map[row][col].entity = map[row][col].entity;
            temp_map[row][col].n_enemies = map[row][col].n_enemies;
        }
    }
}

// This will update the main map
void update_main_map(struct tile map[MAP_ROWS][MAP_COLUMNS]
, struct tile clone_map[MAP_ROWS][MAP_COLUMNS]) {
    for (int row = 0; row < MAP_ROWS; row ++) {
        for (int col = 0; col < MAP_COLUMNS; col++) {
            if (clone_map[row][col].land == GRASS ||
                clone_map[row][col].land == TELEPORTER)
            map[row][col].land = clone_map[row][col].land;
            map[row][col].entity = clone_map[row][col].entity;
            map[row][col].n_enemies = clone_map[row][col].n_enemies;
        }
    }
}

// This will check and create teleporter
void create_tele(struct coordinate fist_teleporter, struct coordinate second_teleporter
, struct tile map[MAP_ROWS][MAP_COLUMNS], int first_row, int first_col
, int *second_row, int *second_col, struct tile temp_map[MAP_ROWS][MAP_COLUMNS]
, struct tile clone_map[MAP_ROWS][MAP_COLUMNS], struct coordinate start_point) {
    if (valid_point(fist_teleporter) != 1 ||
    valid_point(second_teleporter) != 1) {
        printf("Error: Teleporters can only be created on path tiles.\n");
    } else if (tele_not_path(map, first_row, first_col, *second_row
    , *second_col) == 1) {
        printf("Error: Teleporters can only be created on path tiles.\n");
    } else if (map[first_row][first_col].land == PATH_END) {
        printf("Error: Teleporters can only be created on path tiles.\n");
    } else if (tele_on_path(map, first_row, first_col, *second_row
    , *second_col) == 1) {
        create_temp_map(temp_map, clone_map);
        // *num_pair_tele++;
        // assign teleporter
        clone_map[first_row][first_col].land = TELEPORTER;
        clone_map[*second_row][*second_col].land = TELEPORTER;
        // delete path in between

        int tracking_row = start_point.row;
        int tracking_col = start_point.col;
        find_start_tele(clone_map, &tracking_row, &tracking_col, second_row,
        second_col);

        first_row = tracking_row;
        first_col = tracking_col;
        // pair_teleporter[*num_pair_tele].first_tele_row = tracking_row;
        // pair_teleporter[*num_pair_tele].first_tele_col = tracking_col;
        tracking_row = next_row(first_row, first_col, temp_map, second_row);
        tracking_col = next_col(first_row, first_col, temp_map, second_col);

        find_end_tele(clone_map, &tracking_row, &tracking_col, second_row
        , second_col);

        // pair_teleporter[*num_pair_tele].second_tele_row = tracking_row;
        // pair_teleporter[*num_pair_tele].second_tele_col = tracking_col;
        update_main_map(map, clone_map);
    }
}

// This willl check teleporter not on path
int tele_not_path(struct tile map[MAP_ROWS][MAP_COLUMNS], int first_row
, int first_col, int second_row, int second_col) {
    return (map[first_row][first_col].land != PATH_UP &&
    map[first_row][first_col].land != PATH_DOWN &&
    map[first_row][first_col].land != PATH_RIGHT &&
    map[first_row][first_col].land != PATH_LEFT) || 
    (map[second_row][second_col].land != PATH_UP &&
    map[second_row][second_col].land != PATH_DOWN &&
    map[second_row][second_col].land != PATH_RIGHT &&
    map[second_row][second_col].land != PATH_LEFT);
}

// This willl check teleporter on path
int tele_on_path(struct tile map[MAP_ROWS][MAP_COLUMNS], int first_row
, int first_col, int second_row, int second_col) {
    return (map[first_row][first_col].land == PATH_UP ||
    map[first_row][first_col].land == PATH_DOWN ||
    map[first_row][first_col].land == PATH_RIGHT ||
    map[first_row][first_col].land == PATH_LEFT) && 
    (map[second_row][second_col].land == PATH_UP ||
    map[second_row][second_col].land == PATH_DOWN ||
    map[second_row][second_col].land == PATH_RIGHT ||
    map[second_row][second_col].land == PATH_LEFT);
}

// This will find the start of teleporter
void find_start_tele(struct tile clone_map[MAP_ROWS][MAP_COLUMNS]
, int *tracking_row, int *tracking_col, int *second_row, int *second_col) {
    while (!(clone_map[*tracking_row][*tracking_col].land == TELEPORTER)) {
        int pre_row = *tracking_row;
        int pre_col = *tracking_col;
        *tracking_row = next_row(pre_row, pre_col, clone_map, second_row);
        *tracking_col = next_col(pre_row, pre_col, clone_map, second_col);
    }
}

// This will find the end of teleporter
void find_end_tele(struct tile clone_map[MAP_ROWS][MAP_COLUMNS]
, int *tracking_row, int *tracking_col, int *second_row, int *second_col) {
    while (!(clone_map[*tracking_row][*tracking_col].land == TELEPORTER)) {
        int pre_row = *tracking_row;
        int pre_col = *tracking_col;
        *tracking_row = next_row(pre_row, pre_col, clone_map, second_row);
        *tracking_col = next_col(pre_row, pre_col, clone_map, second_col);
        clone_map[pre_row][pre_col].land = GRASS;
        clone_map[pre_row][pre_col].n_enemies = 0;
    }
}

// This will check for the lives is enough to continue or not
void live_check(int start_live) {
    if (start_live <= 0) {
        printf("Oh no, you ran out of lives!");
    } else {
        printf("Enter Command: ");
    }
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////// PROVIDED FUNCTIONS  ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/**
 * Initialises map tiles to contain GRASS land and EMPTY entity.
 * 
 * Parameters:
 *     map - The map to initialise.
 * Returns:
 *     Nothing.
 */
void initialise_map(struct tile map[MAP_ROWS][MAP_COLUMNS]) {
    for (int row = 0; row < MAP_ROWS; ++row) {
        for (int col = 0; col < MAP_COLUMNS; ++col) {
            map[row][col].land = GRASS;
            map[row][col].entity = EMPTY;
            map[row][col].n_enemies = 0;
        }
    }
}

/**
 * Prints all map tiles based on their value, with a header displaying lives
 * and money.
 * 
 * Parameters:
 *     map   - The map to print tiles from.
 *     lives - The number of lives to print with the map.
 *     money - The amount of money to print with the map.
 * Returns:
 *     Nothing.
 */
void print_map(struct tile map[MAP_ROWS][MAP_COLUMNS], int lives, int money) {
    printf("\nLives: %d Money: $%d\n", lives, money);
    for (int row = 0; row < MAP_ROWS * 2; ++row) {
        for (int col = 0; col < MAP_COLUMNS; ++col) {
            print_tile(map[row / 2][col], row % 2);
        }
        printf("\n");
    }
}

/**
 * Prints either the land or entity component of a single tile, based on
 * the `land_print` parameter;
 * 
 * Parameters:
 *     tile         - The tile to print the land/entity from
 *     land_print - Whether to print the land part of the tile or the entity
 *         part of the tile. If this value is 0, it prints the land, otherwise
 *         it prints the entity.
 * Returns:
 *     Nothing.
 */
void print_tile(struct tile tile, int land_print) {
    if (land_print) {
        if (tile.land == GRASS) {
            printf(" . ");
        } else if (tile.land == WATER) {
            printf(" ~ ");
        } else if (tile.land == PATH_START) {
            printf(" S ");
        } else if (tile.land == PATH_END) {
            printf(" E ");
        } else if (tile.land == PATH_UP) {
            printf(" ^ ");
        } else if (tile.land == PATH_RIGHT) {
            printf(" > ");
        } else if (tile.land == PATH_DOWN) {
            printf(" v ");
        } else if (tile.land == PATH_LEFT) {
            printf(" < ");
        } else if (tile.land == TELEPORTER) {
            printf("( )");
        } else {
            printf(" ? ");
        }
    } else {
        if (tile.entity == EMPTY) {
            printf("   ");
        } else if (tile.entity == ENEMY) {
            printf("%03d", tile.n_enemies);
        } else if (tile.entity == BASIC_TOWER) {
            printf("[B]");
        } else if (tile.entity == POWER_TOWER) {
            printf("[P]");
        } else if (tile.entity == FORTIFIED_TOWER) {
            printf("[F]");
        } else {
            printf(" ? ");
        }
    }
}