// Carriage Simulator
//
// This program was written by Dinh Minh Nhat Nguyen (z5428797)
// on 03/04/2023
//
// In order to address complaints about Light Rail, Transport NSW has hired you 
// to make a program that can design and test train layouts, with the end goal 
// being to increase passenger happiness.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

////////////////////////////////////////////////////////////////////////////////
///////////////////////////      Contants       ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Provided constants
#define ID_SIZE 6

// Provided enums
enum carriage_type {INVALID_TYPE, PASSENGER, BUFFET, RESTROOM, FIRST_CLASS};

#define HELP '?'
#define ADD_CARRIAGES 'a'
#define PRINT_TRAIN 'p'
#define INSERT_CARRIAGE 'i'
#define ADD_PASSENGERS 's' 
#define REMOVE_PASSENGERS 'd'
#define COUNT_PASSENGERS 'T'
#define COUNT_PASSENGERS_RANGE 'c'
#define MOVE_PASSENGERS 'm'
#define NEW_EMPTY_TRAIN 'N'
#define SELECT_NEXT_TRAIN '>'
#define SELECT_PRE_TRAIN '<'
#define PRINT_TRAINS 'P'
#define IS_SELECTED 1
#define NOT_SELECTED 0
#define REMOVE_CARRIAGE 'r'
#define REMOVE_TRAIN 'R'
#define MERGE_TRAIN 'M'
#define SPLIT_TRAIN 'S'

////////////////////////////////////////////////////////////////////////////////
/////////////////////////// USER DEFINED TYPES  ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



// A Train Carriage
struct carriage {
    // carriage id in the form #"N1002", unique, null terminated
    char carriage_id[ID_SIZE];
    //  Type of the carriage
    enum carriage_type type;
    // Maximum number of passengers 
    int capacity;
    // Current number of passengers
    int occupancy;

    struct carriage *next;
};

struct train {
    struct carriage *carriages;
    // Feel free to add more fields here if you want.
    struct train *previous;
    struct train *next;
};

////////////////////////////////////////////////////////////////////////////////
////////////////////// PROVIDED FUNCTION PROTOTYPE  ////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void print_usage(void);
void print_carriage(struct carriage *carriage);
void scan_id(char id_buffer[ID_SIZE]);
enum carriage_type scan_type(void);
void print_train_summary(
    int is_selected, 
    int n, 
    int capacity, 
    int occupancy,
    int num_carriages
);
int compare_double(double n1, double n2);

// Additional provided function prototypes
// You won't need to use these functions!
// We use just them to implement some of the provided helper functions.
int scan_token(char *buffer, int buffer_size);
char *type_to_string(enum carriage_type type);
enum carriage_type string_to_type(char *type_str);

////////////////////////////////////////////////////////////////////////////////
////////////////////////  YOUR FUNCTION PROTOTYPE  /////////////////////////////
////////////////////////////////////////////////////////////////////////////////
struct carriage *create_carriage(
    char id[ID_SIZE], 
    enum carriage_type type,
    int capacity
);
struct carriage *adding_carriage_tail(
    char id[ID_SIZE], 
    enum carriage_type type,
    int capacity,
    struct carriage *head
);
void print_train(struct carriage *head);
struct carriage *check_repeat_id(struct carriage *head, char id[ID_SIZE]);
int check_carriage(
    struct carriage *head,
    char id[ID_SIZE],
    enum carriage_type type,
    int capacity
);
void calculate_train_length(struct carriage *head, int *train_lenth);
struct carriage *adding_carriage_head(
    char id[ID_SIZE], 
    enum carriage_type type,
    int capacity,
    struct carriage *head
);
struct carriage *adding_carriage_middle(
    char id[ID_SIZE], 
    enum carriage_type type,
    int capacity,
    struct carriage *head,
    int position
);
struct carriage *insert_carriage(
    struct carriage *head,
    int position,
    char id[ID_SIZE], 
    enum carriage_type type,
    int capacity
);
int check_insert_carriage(
    struct carriage *head,
    char id[ID_SIZE],
    enum carriage_type type,
    int capacity,
    int position
);
struct carriage *find_carriage( struct carriage *head, char id[ID_SIZE]);
int check_passenger( 
    int passenger,
    struct carriage *head,
    char id[ID_SIZE]
);
struct carriage *add_passenger(
    struct carriage *head,
    char id[ID_SIZE],
    int *passengers
);
struct carriage *remove_passenger(
    struct carriage *head,
    char id[ID_SIZE],
    int *passengers
);
int total_occupancy_ht( struct carriage *head);
int total_unoccupied_capacity_ht(struct carriage *head);
int check_order(struct carriage *head, struct carriage *tail);
int occupancy_range(struct carriage *head, struct carriage *tail);
int unoccupied_capacity_range(struct carriage *head, struct carriage *tail);
void print_count_passengers_range(
    struct carriage *head,
    char start_id[ID_SIZE],
    char end_id[ID_SIZE]
);
struct carriage *move_passengers(
    struct carriage *source,
    struct carriage *destination,
    int *passengers,
    char destination_id[ID_SIZE]
);
struct carriage *add_passengers(
    struct carriage *head,
    int *passengers,
    char source_id[ID_SIZE]
);
struct carriage *check_and_move(
    int *passengers,
    struct carriage *head,
    char source_id[ID_SIZE],
    char destination_id[ID_SIZE]
);
struct train *create_train(
    struct train *previous_train,
    struct train *selected,
    struct carriage *head_carriage
);
int total_capacity (struct carriage *head);
struct train *add_new_train(struct train *selected, struct train *new_train);
void printing_train( struct train *selected);
struct carriage *remove_carriage(
    struct carriage *head,
    char carriage_id[ID_SIZE]
);
struct train *remove_train(struct train *selected);
void remove_all(struct train *selected);
struct train *merge_train (struct train *selected);
struct train *remove_same_id_carriage(
    struct train *selected,
    struct carriage *next_head
);
int split_id_count (
    int number_ids,
    struct carriage *head,
    char intial_ids[number_ids][ID_SIZE]
);
struct train *split_train(
    struct train *selected,
    char final_ids[][ID_SIZE],
    int array_size
);
void store_split_ids(
    int counter,
    char intial_ids[][ID_SIZE],
    struct carriage *current,
    int *counter_2,
    char final_ids[][ID_SIZE]
);
struct train *check_split_train(int number_ids, struct train *selected);
struct train *check_split_empty(
    int *counter,
    struct train *selected,
    char intial_ids[][ID_SIZE]
);
struct train *remove_train_merge(struct train *selected);
struct train *add_carriage_function(struct train *selected);
struct train *insert_carriage_function(struct train *selected);
struct train *add_passengers_function(struct train *selected);
struct train *remove_passengers_function(struct train *selected);
void count_passengers_function(struct train *selected);
void count_passengers_range_function(struct train *selected);
struct train *move_passengers_function(struct train *selected);
struct train *select_next_train(struct train *selected);
struct train *select_pre_train(struct train *selected);
struct train *remove_carriage_function(struct train *selected);
struct train *split_train_funcion(struct train *selected);
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(void) {
    printf("Welcome to Carriage Simulator\n");
    printf("All aboard!\n");
    char command;
    printf("Enter command: ");
    struct train *trains = create_train(NULL, NULL, NULL);
    struct train *selected = trains;
    struct train *new_train = NULL;
    while (scanf(" %c", &command) != EOF) {
        if (command == HELP) {
            print_usage();
        } else if (command == ADD_CARRIAGES) {
            selected = add_carriage_function(selected);
        } else if (command == PRINT_TRAIN) {
            print_train(selected->carriages);
        } else if (command == INSERT_CARRIAGE) {
            selected = insert_carriage_function(selected);
        } else if (command == ADD_PASSENGERS) {
            selected = add_passengers_function(selected);
        } else if (command == REMOVE_PASSENGERS) {
            selected = remove_passengers_function(selected);
        } else if (command == COUNT_PASSENGERS) {
            count_passengers_function(selected);
        } else if (command == COUNT_PASSENGERS_RANGE) {
            count_passengers_range_function(selected);
        } else if (command == MOVE_PASSENGERS) {
            selected = move_passengers_function(selected);
        } else if (command == NEW_EMPTY_TRAIN) {
            selected = add_new_train(selected, new_train);
        } else if (command == SELECT_NEXT_TRAIN) {
            selected = select_next_train(selected);
        } else if (command == SELECT_PRE_TRAIN) {
            selected = select_pre_train(selected);
        } else if (command == PRINT_TRAINS) {
            printing_train(selected);
        } else if (command == REMOVE_CARRIAGE) {
            selected = remove_carriage_function(selected);
        } else if (command == REMOVE_TRAIN) {
            selected = remove_train(selected);
        } else if (command == MERGE_TRAIN) {
            selected = merge_train(selected);
        } else if (command == SPLIT_TRAIN) {
            selected = split_train_funcion(selected);
        }
        printf("Enter command: ");
    }
    printf("\nGoodbye\n");
    remove_all(selected);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  YOUR FUNCTIONS //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// This function creates new carriage
struct carriage *create_carriage(
    char id[ID_SIZE], 
    enum carriage_type type,
    int capacity
) {
    struct carriage *new_carriage;
    new_carriage = malloc(sizeof(struct carriage));
    strcpy(new_carriage->carriage_id, id);
    new_carriage->type = type;
    new_carriage->capacity = capacity;
    new_carriage->occupancy = 0;
    new_carriage->next = NULL;
    return new_carriage; 
}

// This function checks for command to split train
struct train *split_train_funcion(struct train *selected) {
    int number_ids;
    scanf("%d", &number_ids);
    selected = check_split_train(number_ids, selected);
    return selected;
}

// This function checks for command to remove carriage
struct train *remove_carriage_function(struct train *selected) {
    char carriage_id[ID_SIZE];
    scan_id(carriage_id);
    selected->carriages = remove_carriage(selected->carriages, carriage_id);
    return selected;
}


// This function checks for command to select the previous train
struct train *select_pre_train(struct train *selected) {
    if (selected->previous != NULL) {
        selected = selected->previous;
    }
    return selected;
}

// This function checks for command to select the next train
struct train *select_next_train(struct train *selected) {
    if (selected->next != NULL) {
        selected = selected->next;
    }
    return selected;
}

// This function checks for command to move the passengers
struct train *move_passengers_function(struct train *selected) {
    char source_id[ID_SIZE];
    scan_id(source_id);
    char destination_id[ID_SIZE];
    scan_id(destination_id);
    int passengers;
    scanf("%d", &passengers);
    selected->carriages = check_and_move(&passengers, selected->carriages,
                                            source_id, destination_id);
    return selected;
}

// This function checks for command to print out the number of passengers in
// range
void count_passengers_range_function(struct train *selected) {
    char start_id[ID_SIZE];
    scan_id(start_id);
    char end_id[ID_SIZE];
    scan_id(end_id);
    print_count_passengers_range(selected->carriages, start_id, end_id);
}

// This function checks for command to print out the total number of passengers
void count_passengers_function(struct train *selected) {
    printf("Total occupancy: %d\n", total_occupancy_ht(selected->carriages));
    printf("Unoccupied capacity: %d\n", 
            total_unoccupied_capacity_ht(selected->carriages));
}

// This function checks for command to remove passengers
struct train *remove_passengers_function(struct train *selected) {
    char id[ID_SIZE];
    scan_id(id);
    int passengers;
    scanf("%d", &passengers);
    selected->carriages = remove_passenger(selected->carriages, id, 
                                            &passengers);
    return selected;
}

//This function checks for command to add passengers
struct train *add_passengers_function(struct train *selected) {
    char id[ID_SIZE];
    scan_id(id);
    int passengers;
    scanf("%d", &passengers);
    if (check_passenger(passengers, selected->carriages, id) == 1) {
        selected->carriages = add_passenger(selected->carriages, id, 
                                            &passengers);
    }
    return selected;
}

// This function checks for command to insert the carriage
struct train *insert_carriage_function(struct train *selected) {
    int position;
    scanf("%d", &position);
    char id[ID_SIZE];
    scan_id(id);
    enum carriage_type type;
    type = scan_type();
    int capacity;
    scanf("%d", &capacity);
    if (check_insert_carriage(selected->carriages, id, type, capacity,
                                position) == 1) {
        selected->carriages = insert_carriage(selected->carriages, position, id,
                                                type, capacity);
    }
    return selected;
}

// This function checks for command to add the carriage
struct train *add_carriage_function(struct train *selected) {
    char id[ID_SIZE];
    scan_id(id);
    enum carriage_type type;
    type = scan_type();
    int capacity;
    scanf("%d", &capacity);
    if (check_carriage(selected->carriages, id, type, capacity) == 1) {
        selected->carriages = adding_carriage_tail(id, type, capacity,
                                                    selected->carriages);
        printf("Carriage: '%s' attached!\n", id);
    }
    return selected;
}

// This function checks for the train is vaild to split
struct train *check_split_train(int number_ids, struct train *selected) {
    if (number_ids > 0) {
        int counter = 0;
        char intial_ids[number_ids][ID_SIZE];
        printf("Enter ids:\n");
        for (int i = 0; i < number_ids; i++) {
            char split_id[ID_SIZE];
            scan_id(split_id);
            if (find_carriage(selected->carriages, split_id) == NULL) {
                printf("No carriage exists with id: '%s'. Skipping\n",
                        split_id);
            } else {
                strcpy(intial_ids[counter], split_id);
                counter += 1;
            }
        }
        selected = check_split_empty(&counter, selected, intial_ids);
    }
    return selected;
}

// This function checks for the train is empty when split
struct train *check_split_empty(
    int *counter,
    struct train *selected,
    char intial_ids[][ID_SIZE]
) {
    if (*counter > 0) {
        char final_ids [*counter][ID_SIZE];
        struct carriage *current = selected->carriages;
        int counter_2 = -1;
        while (current != NULL) {
            store_split_ids(*counter, intial_ids, current, &counter_2,
                            final_ids);
            current = current->next;
        }
        selected = split_train(selected, final_ids, *counter);
    }
    return selected;
}

// This function stores the input ids for split train
void store_split_ids(
    int counter,
    char intial_ids[][ID_SIZE],
    struct carriage *current,
    int *counter_2,
    char final_ids[][ID_SIZE]
) {
    for (int i = 0; i < counter; i++) {
        if (strcmp(intial_ids[i], current->carriage_id) == 0) {
            *counter_2 += 1;
            strcpy(final_ids [*counter_2], current->carriage_id);
        }
    }
}

// This function splits the train
struct train *split_train(
    struct train *selected,
    char final_ids[][ID_SIZE],
    int array_size
) {
    struct train *current = selected;

    if (current->carriages == NULL) {
        return selected;
    }

    struct train *next_train = NULL;
    if (current->next != NULL) {
        next_train = current->next;
    }

    for (int i = 0; i < array_size; i++) {
        struct carriage *split_carriage = find_carriage(current->carriages,
                                                        final_ids[i]);
        struct train *new_train = create_train(current, next_train,
                                                split_carriage);
        current->next = new_train;
        if (next_train != NULL) {
            next_train->previous = new_train;
        }
        struct carriage *curr_carriage = current->carriages;
        while (
                curr_carriage->next != split_carriage &&
                curr_carriage != split_carriage
        ) {
            curr_carriage = curr_carriage->next;
        }

        if (curr_carriage == split_carriage) {
            current->carriages = NULL;
        } else {
            curr_carriage->next = NULL;
        }
        current = new_train;
    }
    return selected;
}

// This function counts how many time we need to split the train
int split_id_count(
    int number_ids,
    struct carriage *head,
    char intial_ids[number_ids][ID_SIZE]
) {
    int slit_time = 0;
    for (int i = 0; i < number_ids; i++) {
        if (find_carriage(head, intial_ids[i]) == NULL) {
            printf("No carriage exists with id: '%s'. Skipping\n",
                    intial_ids[i]);
        } else {
            slit_time += 1;
        }
    }
    return slit_time;
}

// This function adds a carriage to the tail
struct carriage *adding_carriage_tail(
    char id[ID_SIZE], 
    enum carriage_type type,
    int capacity,
    struct carriage *head
) {
    if (head == NULL) {
        return create_carriage(id, type, capacity);
    }

    struct carriage *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = create_carriage(id, type, capacity);
    return head;
}

// This function prints out the train
void print_train(struct carriage *head) {
    if (head != NULL) {
        struct carriage *current_carriage = head;
        while (current_carriage != NULL) {
            print_carriage(current_carriage);
            current_carriage = current_carriage->next;
        }
    } else {
        printf("This train is empty!\n");
    }
} 

// This function checks for repeat id
struct carriage *check_repeat_id(struct carriage *head, char id[ID_SIZE]) {
    struct carriage *current = head;
    while (current != NULL) {
        if (strcmp(current->carriage_id, id) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// This function checks for valid carriage
int check_carriage(
    struct carriage *head,
    char id[ID_SIZE],
    enum carriage_type type,
    int capacity
) {
    struct carriage *check_id = check_repeat_id(head, id);
    if (type == INVALID_TYPE) {
        printf("ERROR: Invalid carriage type\n");
        return 0;
    } else if (capacity <= 0 || capacity > 999) {
        printf("ERROR: Capacity should be between 1 and 999\n");
        return 0;
    } else if (check_id != NULL) {
        printf("ERROR: a carriage with id: '%s' already exists in this train\n",
                check_id->carriage_id);
        return 0;
    } 
    return 1;
}

// This function calculates the length of the train (count the number of 
// carriages in the train)
void calculate_train_length(struct carriage *head, int *train_lenth) {
    struct carriage *current = head;
    while (current != NULL) {
        *train_lenth += 1;
        current = current->next;
    }
}

// This function adds the carriage to the head
struct carriage *adding_carriage_head(
    char id[ID_SIZE], 
    enum carriage_type type,
    int capacity,
    struct carriage *head
) {
    struct carriage *new_carriage = create_carriage(id, type, capacity);
    new_carriage->next = head;
    return new_carriage;
}

// This function adds the carriage to the middle
struct carriage *adding_carriage_middle(
    char id[ID_SIZE], 
    enum carriage_type type,
    int capacity,
    struct carriage *head,
    int position
) {
    struct carriage *current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    struct carriage *new_carriage = create_carriage(id, type, capacity);
    new_carriage->next = current->next;
    current->next = new_carriage;
    return head;
}

// This function inserts the carriage
struct carriage *insert_carriage(
    struct carriage *head,
    int position,
    char id[ID_SIZE], 
    enum carriage_type type,
    int capacity
) {
    int train_length = 1;
    calculate_train_length(head, &train_length);
    if (position == 0) {
        head = adding_carriage_head(id, type, capacity, head);
        printf("Carriage: '%s' inserted!\n", id);
    } else if (position >= train_length) {
        head = adding_carriage_tail(id, type, capacity, head);
        printf("Carriage: '%s' inserted!\n", id);
    } else {
        head = adding_carriage_middle(id, type, capacity, head, position);
        printf("Carriage: '%s' inserted!\n", id);
    }
    return head;
}

// This function checks for valid insert carriage return 1 for valid  
// and return 0 for invalid
int check_insert_carriage(
    struct carriage *head,
    char id[ID_SIZE],
    enum carriage_type type,
    int capacity,
    int position
) {
    if (position < 0) {
        printf("ERROR: n must be at least 0\n");
        return 0;
    }
    if (check_carriage(head, id, type, capacity) == 1) {
        return 1;
    }
    return 0;

}

// This function finds the carriage with the id
struct carriage *find_carriage(struct carriage *head, char id[ID_SIZE]) {
    struct carriage *current = head;
    if (current == NULL) {
        return current;
    }

    while (strcmp(current->carriage_id, id) != 0) {
        current = current->next;
        if (current == NULL) {
            return current;
        }
    }
    return current;
}

// This function checks for valid passengers return 1 for valid 
// and return 0 for invalid
int check_passenger( 
    int passenger,
    struct carriage *head,
    char id[ID_SIZE]
) {
    if (passenger <= 0) {
        printf("ERROR: n must be a positive integer\n");
        return 0;
    } else if (find_carriage(head, id) == NULL) {
        printf("ERROR: No carriage exists with id: '%s'\n", id);
        return 0;
    }
    return 1;
}

// This function adds passengers
struct carriage *add_passenger(
    struct carriage *head,
    char id[ID_SIZE],
    int *passengers
) {
    struct carriage *current = find_carriage(head, id);
    while (!(*passengers <= 0 || current == NULL)) {
        if (current->occupancy == current->capacity) {
            current = current->next;
        } else if (current->occupancy < current->capacity) {
            int remain_seat = current->capacity - current->occupancy;
            if (*passengers <= remain_seat) {
                current->occupancy += *passengers;
                printf("%d passengers added to %s\n", *passengers,
                        current->carriage_id);
                *passengers = 0;
            } else if (*passengers > remain_seat) {
                current->occupancy += remain_seat;
                printf("%d passengers added to %s\n", remain_seat,
                        current->carriage_id);
                *passengers -= remain_seat;
            }
        }
    }

    if (*passengers > 0) {
        printf("%d passengers could not be seated\n", *passengers);
    }
    return head;
}

// This function removes passengers
struct carriage *remove_passenger(
    struct carriage *head,
    char id[ID_SIZE],
    int *passengers
) {
    struct carriage *current = find_carriage(head, id);
    if (*passengers <= 0) {
        printf("ERROR: n must be a positive integer\n");
    } else if (current == NULL) {
        printf("ERROR: No carriage exists with id: '%s'\n", id);
    } else if (*passengers > current->occupancy) {
        printf("ERROR: Cannot remove %d passengers from %s\n", *passengers, id);
    } else {
        printf("%d passengers removed from %s\n", *passengers, id);
        current->occupancy -= *passengers;
    }
    return head;
}

// This functions returns the total number of total occupancy
int total_occupancy_ht(struct carriage *head) {
    struct carriage *current = head;
    int total_occupancy = 0;
    while (current != NULL) {
        total_occupancy += current->occupancy;
        current = current->next;
    }
    return total_occupancy;
}

// This function returns the total number of unoccupied capacity
int total_unoccupied_capacity_ht(struct carriage *head) {
    struct carriage *current = head;
    int unoccupied_capacity = 0;
    while (current != NULL) {
        unoccupied_capacity += current->capacity - current->occupancy;
        current = current->next;
    }
    return unoccupied_capacity;
}

// This function returns the total number of capacity
int total_capacity(struct carriage *head) {
    struct carriage *current = head;
    int capacity = 0;
    while (current != NULL) {
        capacity += current->capacity;
        current = current->next;
    }
    return capacity;
}

// This function checks for the input order which one comes before the other
// and return 1 if it is in order and return 0 when it is not
int check_order(struct carriage *head, struct carriage *tail) {
    struct carriage *current = head;
    while (current != NULL) {
        if (current == tail) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// This function returns the total number of occupancy in the range
int occupancy_range(struct carriage *head, struct carriage *tail) {
    struct carriage *current = head;
    int occupancy_range = 0;
    while (current != tail->next) {
        occupancy_range += current->occupancy;
        current = current->next;
    }
    return occupancy_range;
    printf("Occupancy: %d\n", occupancy_range);
}

// This function returns the total number of unoccupied capacity in the range
int unoccupied_capacity_range(struct carriage *head, struct carriage *tail) {
    struct carriage *current = head;
    int unoccupied_capacity_range = 0;
    while (current != tail->next) {
        unoccupied_capacity_range += current->capacity - current->occupancy;
        current = current->next;
    }
    return unoccupied_capacity_range;
}

// This function checks and prints out the information in the range
void print_count_passengers_range(
    struct carriage *head,
    char start_id[ID_SIZE],
    char end_id[ID_SIZE]
) {
    struct carriage *start = find_carriage(head, start_id);
    struct carriage *end = find_carriage(head, end_id);
    if (start == NULL) {
        printf("ERROR: No carriage exists with id: '%s'\n", start_id);
    } else if (end == NULL) {
        printf("ERROR: No carriage exists with id: '%s'\n", end_id);
    } else if (check_order(start, end) == 0) {
        printf("ERROR: Carriages are in the wrong order\n");
    } else {
        printf("Occupancy: %d\n", occupancy_range(start, end));
        printf("Unoccupied: %d\n", unoccupied_capacity_range(start, end));
    }
}

// This function moves the passengers
struct carriage *move_passengers(
    struct carriage *source,
    struct carriage *destination,
    int *passengers,
    char source_id[ID_SIZE]
) {
    int remainder_seat = total_unoccupied_capacity_ht(destination);
    if (*passengers > remainder_seat) {
        printf("ERROR: not enough space to move passengers\n");
        return source;
    } else {
        source->occupancy -= *passengers;
        destination = add_passengers(destination, passengers, source_id);
    }
    return source;
}

// This function adds the passengers
struct carriage *add_passengers(
    struct carriage *head,
    int *passengers,
    char source_id[ID_SIZE]
) {
    struct carriage *current = head;
    while (!(*passengers <= 0 || current == NULL)) {
        if (current->occupancy == current->capacity) {
            current = current->next;
        } else if (current->occupancy < current->capacity) {
            int remain_seat = current->capacity - current->occupancy;
            if (*passengers <= remain_seat) {
                current->occupancy += *passengers;
                printf("%d passengers moved from %s to %s\n", *passengers,
                        source_id, current->carriage_id);
                *passengers = 0;
                
            } else if (*passengers > remain_seat) {
                current->occupancy += remain_seat;
                printf("%d passengers moved from %s to %s\n", remain_seat,
                        source_id, current->carriage_id);
                *passengers -= remain_seat;
            }
        }
    }
    return head;
}

// This functions checks for valid and move the passengers
struct carriage *check_and_move(
    int *passengers,
    struct carriage *head,
    char source_id[ID_SIZE],
    char destination_id[ID_SIZE]
) {
    if (*passengers <= 0) {
        printf("ERROR: n must be a positive integer\n");
    } else if (find_carriage(head, source_id) == NULL) {
        printf("ERROR: No carriage exists with id: '%s'\n", source_id);
    } else if (*passengers > find_carriage(head, source_id)->occupancy) {
        printf("ERROR: Cannot remove %d passengers from %s\n", *passengers,
                source_id); 
    } else if (find_carriage(head, destination_id) == NULL) {
        printf("ERROR: No carriage exists with id: '%s'\n", destination_id);
    } else {
        struct carriage *source = find_carriage(head, source_id);
        struct carriage *destination = find_carriage(head, destination_id);
        source = move_passengers(source, destination, passengers, source_id);
    }
    return head;
}

// This function creates train 
struct train *create_train(
    struct train *previous_train,
    struct train *selected,
    struct carriage *head_carriage
) {
    struct train *new_train = malloc(sizeof(struct train));
    new_train->carriages = head_carriage;
    new_train->previous = previous_train;
    new_train->next = selected;
    return new_train;
}

// This function adds new train
struct train *add_new_train(struct train *selected, struct train *new_train) {
    if (selected->previous == NULL) {
        new_train = create_train(NULL, selected, NULL);
        selected->previous = new_train;
    } else {
        struct train *pre_train = new_train;
        new_train = create_train(pre_train, selected, NULL);
        pre_train->next = new_train;
        selected->previous = new_train;
    }
    return selected;
}

// This funcion prints out train information
void printing_train(struct train *selected) {
    struct train *current = selected;

    while (current->previous != NULL) {
        current = current->previous;
    }

    int counter = 0;
    while (current != NULL) {
        int train_length = 0;
        int capacity = total_capacity(current->carriages);
        int occupancy = total_occupancy_ht(current->carriages);
        calculate_train_length(current->carriages, &train_length);

        if (current == selected) {
            print_train_summary(IS_SELECTED, counter, capacity, occupancy,
                                train_length);
        } else {
            print_train_summary(NOT_SELECTED, counter, capacity, occupancy,
                                train_length);
        }

        counter ++;
        current = current->next;
    }
}

// This function removes carriage
struct carriage *remove_carriage(
    struct carriage *head,
    char carriage_id[ID_SIZE]
) {
    struct carriage *current = head;
    struct carriage *previous = NULL;

    if (current == NULL) {
        printf("ERROR: No carriage exists with id: '%s'\n", carriage_id);
        return head;
    }

    if (strcmp(current->carriage_id, carriage_id) == 0) {
        head = current->next;
        free(current);
        return head;
    }

    while (current != NULL && strcmp(current->carriage_id, carriage_id) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("ERROR: No carriage exists with id: '%s'\n", carriage_id);
        return head;
    } else if (strcmp(current->carriage_id, carriage_id) == 0) {
        previous->next = current->next;
        free(current);
    }
    return head;
}

// This function removes train
struct train *remove_train(struct train *selected) {
    int train_length = 0;
    calculate_train_length(selected->carriages, &train_length);
    if (selected->previous == NULL && selected->next == NULL) {
        struct train *new_selected = create_train(NULL, NULL, NULL);
        for (int i = 0; i < train_length; i++) {
            struct carriage *curr = selected->carriages;
            selected->carriages = remove_carriage(curr, curr->carriage_id);
        }
        free(selected);
        return new_selected;
    }

    if (selected->previous == NULL) {
        struct train *new_selected = selected->next;
        new_selected->previous = NULL;
        for (int i = 0; i < train_length; i++) {
            struct carriage *curr = selected->carriages;
            selected->carriages = remove_carriage(curr, curr->carriage_id);
        }
        free(selected);
        return new_selected;
    }

    if (selected->next == NULL) {
        struct train *new_selected = selected->previous;
        new_selected->next = selected->next;
        for (int i = 0; i < train_length; i++) {
            struct carriage *curr = selected->carriages;
            selected->carriages = remove_carriage(curr, curr->carriage_id);
        }
        free(selected);
        return new_selected;
    }

    struct train *new_selected = selected->previous;
    new_selected->next = selected->next;
    selected->next->previous = new_selected;
    for (int i = 0; i < train_length; i++) {
        struct carriage *curr = selected->carriages;
        selected->carriages = remove_carriage(curr, curr->carriage_id);
    }
    free(selected);
    return new_selected;
}

// This function removes train when merging
struct train *remove_train_merge(struct train *selected) {
    if (selected->next == NULL) {
        struct train *new_selected = selected->previous;
        new_selected->next = selected->next;
        free(selected);
        return new_selected;
    }

    struct train *new_selected = selected->previous;
    new_selected->next = selected->next;
    selected->next->previous = new_selected;
    free(selected);
    return new_selected;
}

// This function free and remove all trains and carriages to prevent memory leak
void remove_all(struct train *selected) {
    struct train *curr = selected;
    struct train *previous = NULL;
    while (curr->previous != NULL) {
        curr = curr->previous;
    }

    while (curr != NULL) {
        int train_length = 0;
        calculate_train_length(curr->carriages, &train_length);
        for (int i = 0; i < train_length; i++) {
            curr->carriages = remove_carriage(curr->carriages,
                                                curr->carriages->carriage_id);
        }
        previous = curr;
        curr = curr->next;
        free(previous);
    }
}

// This function merges the train
struct train *merge_train (struct train *selected) { 
    struct train *current = selected;
    struct train *next_train = selected->next;
    
    if (next_train == NULL) {
        return current;
    }
    struct carriage *head = selected->carriages;
    struct carriage *next_head = selected->next->carriages;

    if (head == NULL && next_head == NULL) {
        current = remove_train_merge(next_train);
        return current;
    } else if (head == NULL) {
        selected->carriages = next_head;
        current = remove_train_merge(next_train);
        return current;
    } else if (next_head == NULL) {
        current = remove_train_merge(next_train);
        return current;
    }

    current = remove_same_id_carriage(current, next_head);

    current->carriages = head;
    next_train->carriages = next_head;
    while (current->carriages->next != NULL) {
        current->carriages = current->carriages->next;
    }
    current->carriages->next = next_train->carriages;
    next_train->carriages = NULL;
    selected->carriages = head;
    current = remove_train_merge(next_train);

    return current;
}

// This functions merge the train with the same id and remove 1 of them
struct train *remove_same_id_carriage(
    struct train *selected,
    struct carriage *next_head
) {
    struct train *curr = selected;
    struct train *next_train = selected->next;
    while (curr->carriages != NULL) {
        next_train->carriages = next_head;
        while (next_train->carriages != NULL) {
            if (strcmp(curr->carriages->carriage_id,
                        next_train->carriages->carriage_id) == 0) {

                curr->carriages->capacity += next_train->carriages->capacity;
                curr->carriages->occupancy += next_train->carriages->occupancy;
                char remove_id[ID_SIZE];
                strcpy(remove_id, next_train->carriages->carriage_id);
                next_train->carriages = next_train->carriages->next;
                next_head = remove_carriage(next_head, remove_id);
            } else {
                next_train->carriages = next_train->carriages->next;
            }
        }
        curr->carriages = curr->carriages->next;
    }
    return curr;
}
////////////////////////////////////////////////////////////////////////////////
///////////////////////////  PROVIDED FUNCTIONS  ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Prints the Carriage simulator usage instructions,
// displaying the different commands and their arguments.
//
void print_usage(void) {
    printf(
        "=====================[ Carriage Simulator ]=====================\n"
        "      ===============[     Usage Info     ]===============      \n"
        "  a [carriage_id] [type] [capacity]                             \n"
        "    Add a carriage to the train                                 \n"
        "  p                                                             \n"
        "    Print out all of the carriages in the train                 \n"
        "  i [n] [carriage_id] [type] [capacity]                         \n"
        "    Insert a carriage into the train at position `n`            \n"
        "                                                                \n"
        "  s [carriage_id] [n]                                           \n"
        "    Seat `n` passengers onto the train starting from carriage   \n"
        "    `carriage_id`                                               \n"
        "  d [carriage_id] [n]                                           \n"
        "    Remove `n` passengers from carriage `carriage_id`           \n"
        "  T                                                             \n"
        "    Display the total number of passengers and empty seats on   \n"
        "    the train                                                   \n"
        "  c [start_id] [end_id]                                         \n"
        "    Display the number of passengers and empty seats on between \n"
        "    carriage `start_id` and carriage `end_id`                   \n"
        "  m [source_id] [destination_id] [n]                            \n"
        "    Move `n` passengers from one carrige to another, without    \n"
        "    kicking anyone off the train.                               \n"
        "  h [carriage_id]                                               \n"
        "    Display the happiness of passengers in carriage             \n"
        "    `carriage_id`                                               \n"
        "  H                                                             \n"
        "    Display the average happiness of all passengers on the train\n"
        "                                                                \n"
        "  N                                                             \n"
        "    Create a new empty train                                    \n"
        "  >                                                             \n"
        "    Select the next train in the train list.                    \n"
        "  <                                                             \n"
        "    Select the previous train in the train list.                \n"
        "  P                                                             \n"
        "    Display the train list.                                     \n"
        "  r [carriage_id]                                               \n"
        "    Remove carriage `carriage_id` from the selected train.      \n"
        "  R                                                             \n"
        "    Remove the selected train.                                  \n"
        "                                                                \n"
        "  M                                                             \n"
        "    Merge the selected train with the train after it.           \n"
        "  S [n]                                                         \n"
        "    Split the current train into smaller trains.                \n"
        "  O                                                             \n"
        "    Rearrange passengers on the selected train to optimise      \n"
        "    happiness.                                                  \n"
        "  ?                                                             \n"
        "    Show help                                                   \n"
        "================================================================\n"
    );
}


// Scan in the a carriage id string into the provided buffer, placing 
// '\0' at the end.
//
// Parameters:
//      id_buffer - a char array of length ID_SIZE, which will be used
//                  to store the id.
// 
// Usage: 
// ```
//      char id[ID_SIZE];
//      scan_id(id);
// ```
void scan_id(char id_buffer[ID_SIZE]) {
    scan_token(id_buffer, ID_SIZE);
}


// Scans a string and converts it to a carriage_type.
//
// Returns:
//      The corresponding carriage_type, if the string was valid,
//      Otherwise, returns INVALID_TYPE.
// 
// Usage: 
// ```
//      enum carriage_type type = scan_type();
// ```
//
enum carriage_type scan_type(void) {
    // This 20 should be #defined, but we've kept it like this to
    // avoid adding additional constants to your code.
    char type[20];
    scan_token(type, 20);
    return string_to_type(type);
}


// Formats and prints out a train carriage struct,
//
// Parameters:
//      carriage - The struct carriage to print.
// 
void print_carriage(struct carriage *carriage) {
    int line_length = 20;

    char *id = carriage->carriage_id;
    char *type = type_to_string(carriage->type);

    printf(" ---------\\/--------- \n");

    int padding = line_length - strlen(id);
    printf("|%*s%s%*s|\n", padding / 2, "", id, (padding + 1) / 2, "");

    padding = line_length - 2 - strlen(type);
    printf("|%*s(%s)%*s|\n", padding / 2, "", type, (padding + 1) / 2, "");

    printf("| Occupancy: %3d/%-3d |\n", 
            carriage->occupancy, 
            carriage->capacity);
    printf(" ---------||--------- \n");
}


// Formats and prints out various information about a given train.
//
// Parameters:
//      is_selected - 1, if this train is the currently selected train, 
//                    0, otherwise.
//      n           - The position of the given train in the list of trains, 
//                    starting from 0.
//      capacity    - The total capacity of the given train.
//      capacity    - The total occupancy of the given train
//      num_carriages   - The number of carriages in the given train.
//
void print_train_summary(
    int is_selected, 
    int n, 
    int capacity, 
    int occupancy,
    int num_carriages
) {
    if (is_selected) {
        printf("--->Train #%d\n", n);
    } else  {
        printf("    Train #%d\n", n);
    }

    printf("        Carriages: %3d\n", num_carriages);
    printf("        Capacity : %3d/%-3d\n", occupancy, capacity);
    printf("    ----------------------\n");

}



// Compares two double (floating point) values. Value are considered
// equal if there is a less than 0.01 difference between them.
// Note: You should use this function if you need to compare doubles
//       to eachother, as it reduces inconsistencies caused by double
//       imprecision.
//
// Parameters:
//      n1 - a floating point value
//      n2 - a floating point value
// 
// Returns:
//      0, if the two values are considered equal.
//      a negative number, if n1 is less than n2,
//      a positive number, if n2 is less than n1,
//
// Usage: 
// ```
//      if (compare_double(n1, n2) > 0) {
//          printf("n1 greater than n2\n");
//      } else if (compare_double(n1, n2) == 0) {
//          printf("n1 is equal to n2\n");
//      } else {
//          printf("n1 is less than n2\n");
//      }
// ```
int compare_double(double n1, double n2) {
    double delta = 0.01;

    double difference = n1 - n2;
    // abs(n1 - n2) < delta 
    if (difference < delta && difference > -delta) {
        return 0;
    }
    if (n1 < n2) {
        return -1;
    }

    return 1;
}


////////////////////////////////////////////////////////////////////////////////
////////////////////// ADDITIONAL PROVIDED FUNCTIONS ///////////////////////////
////////////////////////////////////////////////////////////////////////////////
// You don't need to use any of these, or understand how they work!
// We use them to implement some of the provided helper functions.

enum carriage_type string_to_type(char *type_str) {
    int len = strlen(type_str);

    if (strncasecmp(type_str, "passenger", len) == 0) {
        return PASSENGER;
    } 
    if (strncasecmp(type_str, "buffet", len) == 0) {
        return BUFFET;
    } 
    if (strncasecmp(type_str, "restroom", len) == 0) {
        return RESTROOM;
    }
    if (strncasecmp(type_str, "first_class", len) == 0) {
        return FIRST_CLASS;
    } 

    return INVALID_TYPE;
}


char *type_to_string(enum carriage_type type) {
    if (type == PASSENGER) {
        return "PASSENGER";
    } else if (type == BUFFET) {
        return "BUFFET";
    } else if (type == FIRST_CLASS) {
        return "FIRST CLASS";
    } else if (type == RESTROOM) {
        return "RESTROOM";
    }

    return "INVALID";
}

int scan_token(char *buffer, int buffer_size) {
    if (buffer_size == 0) {
        return 0;
    }

    char c;
    int i = 0;
    int num_scanned = 0;

    // consume all leading whitespace
    scanf(" ");

    // Scan in characters until whitespace
    while (i < buffer_size - 1
        && (num_scanned = scanf("%c", &c)) == 1 
        && !isspace(c)) {

        buffer[i++] = c;
    }

    if (i > 0) {
        buffer[i] = '\0';
    }

    return num_scanned;
}
