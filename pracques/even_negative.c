// Read integers until a negative integer is read 
// and then print odd and even integers on separate lines

#include <stdio.h>

#define MAX_NUMBERS 1001

// Let's try and think of a smart way to do this, there are a number
// of different ways to solve - what are some thoughts?
void print_odd_even(int array_length, int array[], int mod);

int main(void) {
    int array[MAX_NUMBERS] = {0};
    int i = 0;
    while ((scanf("%d", &array[i]) == 1) && i < MAX_NUMBERS - 1 && array[i] >= 0) {
        i++;
    }
    

    printf("Odd numbers were:");
    print_odd_even(i, array, 1);
    printf("\n");
    printf("Even numbers were:");
    print_odd_even(i, array, 0);
    printf("\n");
    return 0;
}


void print_odd_even(int array_length, int array[], int mod){

// PUT YOUR CODE HERE
    for (int i = 0; i < array_length; i++) {
        if (array[i] % 2 == mod) {
            printf("%d ", array[i]);
        }
    }
} 