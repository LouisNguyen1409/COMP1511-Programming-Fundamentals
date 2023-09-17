// A demonstration of arrays

// <CLASS>, <MONTH YEAR>

#include <stdio.h>
#define SIZE 10

void print_array (int numbers[SIZE]);

int main(void) {
    // Task 1: Create an integer array called 'numbers' of size SIZE.
    // Initialise all elements to 0.
    int numbers[SIZE] = {0};
    // Task 2: Print the elements of the array.
    print_array(numbers);
    // Task 3: Set the elements of the array to 1, 2, 3...
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = i + 1;
    }
    // Task 4: Print the elements of the array.
    print_array(numbers);
    // Task 5: Create a function that prints elements of an array and use it.

    return 0;
}

void print_array (int numbers[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ",numbers[i]);
    }
    printf("\n");
}