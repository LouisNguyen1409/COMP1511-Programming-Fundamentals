// Recapping 1D arrays! 
// Problem: A user is asked to enter 5 numbers. We will
// then go through these numbers and find the lowest
// number and output what the lowest number is to the
// user.

#include <stdio.h>

#define MAX 5

int main(void) {

    int lowest_number;

    // Declare an array to store the numbers that the user will enter
    int array[MAX] = {0};

    for (int i = 0; i < MAX; i++) {
        printf("Please enter a number: ");
        int scanf_return = scanf("%d", &array[i]);
        // error checking
        if (scanf_return != 1) {
            printf("You did not enter a number!\n");
            return 1;
        }
    }

    lowest_number = array[0];
    for (int i = 0; i < MAX; i++) {
        if (array[i] < lowest_number) {
            lowest_number = array[i];
        }
    }


    printf("The lowest number is %d\n", lowest_number);

    return 0;
}