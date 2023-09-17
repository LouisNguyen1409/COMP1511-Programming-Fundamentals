// Does some calculations to make souffle pancakes
// Solution by Paula Tennent (2023)
// Solution fixed by Dinh Minh Nhat Nguyen z5428797

#include <stdio.h>

#define COOKING_TIME 15
#define PANCAKES_PER_PAN 4
#define HOUR 60

// TODO: Write function prototypes





// TODO: Write divide function
double divide(double num_1, double num_2);

// TODO: Write ceiling function
int ceiling(double num);

// TODO: Write print_time function
void print_time(int time);

//////////////// vvv DO NOT EDIT MAIN vvv //////////////////

int main(void) {

    printf("How many souffle pancakes do you want to make? ");
    int pancakes;
    scanf("%d", &pancakes);

    // for 3 pancakes, we need 2 eggs!
    double eggs_decimal = pancakes * divide(2, 3);
    // but we can't have part of an egg, so lets use ceiling
    int eggs = ceiling(eggs_decimal);

    int sugar_grams = pancakes * 10;
    int flour_grams = pancakes * 8;

    printf("You will need:\n");
    printf("- %d eggs\n", eggs);
    printf("- %dg sugar\n", sugar_grams);
    printf("- %dg flour\n", flour_grams);

    // also using ceiling for frying sessions as if we have 1 pancake left
    // it still needs the same time as full pan of pancakes.
    int frying_sessions = ceiling(divide(pancakes, PANCAKES_PER_PAN));
    int minutes = frying_sessions * COOKING_TIME;

    printf("Frying will take you ");
    print_time(minutes);
    printf(".\n");

    return 0;
}

//////////////// ^^^ DO NOT EDIT MAIN ^^^ //////////////////

double divide(double num_1, double num_2) {
    return num_1 / num_2;
}

int ceiling(double num) {
    int return_value = num;
    if (return_value - num != 0) {
        return_value = num + 1;
    }
    return return_value;
}

void print_time(int time) {
    int hour = time / HOUR;
    int min = time - (hour * HOUR);
    printf("%d hours and %d minutes", hour, min);
}