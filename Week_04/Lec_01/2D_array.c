// This program will print out an array of arrays
// Welcome to 2D arrays!

// Declare and create a 3 x 3 two-dimensional array of integer numbers 
// with the numbers read in from the user. Then loop through the 
// two-dimensional array, printing out the values in the first row followed 
// by those in the second row and so on.

// Now loop through the array to count the number of even numbers in the 2D array

// Sasha Week 4: 2D Arrays

#include <stdio.h>

#define MAX_ROW 3
#define MAX_COL 3
// #define MAX 5

void print_array(int array[MAX_ROW][MAX_COL]);
int check_even(int array[MAX_ROW][MAX_COL]);

int main(void) {

    // Declare an array of arrays that will be able to house user input 
    // int array_1D[MAX] = {1, 2, 3, 4, 5};
    int array_2D[MAX_ROW][MAX_COL] = {{1, 2, 3}, {4, 5, 6}};

    int row = 0;
    int col = 0;
    for (row = 0; row < MAX_ROW; row++) {
        for (col = 0; col < MAX_COL; col++) {
            printf("Please enter a number: ");
            scanf("%d", &array_2D[row][col]);
            // printf("%d ", array_2D[row][col]);
        }
        // printf("\n");
    }

    print_array(array_2D);

    printf("The number of even number in the 2D array is %d\n", check_even(array_2D));
    
    /* Remember our while inside a while loop that printed out a grid
    while (col <= MAX) {
        row = 1;
        while (row <= MAX) {
            printf("%d ", row);
            row = row + 1;
        }
        printf("\n");
        col = col + 1;
    }*/



    return 0;
}

void print_array(int array[MAX_ROW][MAX_COL]) {
    for (int row = 0; row < MAX_ROW; row++) {
        for (int col = 0; col < MAX_COL; col++) {
            // printf("Please enter a number: ");
            // scanf("%d", &array_2D[row][col]);
            printf("%d ", array[row][col]);
        }
        printf("\n");
    }
}

int check_even(int array[MAX_ROW][MAX_COL]) {
    int even_counter = 0;
    for (int row = 0; row < MAX_ROW; row++) {
        for (int col = 0; col < MAX_COL; col++) {
            if (array[row][col] % 2 == 0) {
                even_counter ++;
            }
        }
    }
    return even_counter;
}