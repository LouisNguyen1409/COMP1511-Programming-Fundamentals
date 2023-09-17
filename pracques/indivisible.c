// Read integers > 1 until EOF (or non-number)
// then print integers not exactly divisible by any other integer read

#include <stdio.h>

#define MAX_NUMBERS 1001

// print integers in array which are not exactly divisible by any other 
// integers in array
void divisible(int array_length, int array[]) {
    for (int i = 0; i < array_length; i++) {
        int factor = 0;
        for (int j = 0; j < array_length; j++) {
            if (array[i] % array[j] == 0) {
                factor++;
            }
        }
        if (factor == 1) {
            printf(" %d", array[i]);
        }
    }
    // Print if the number is indivisible by any other integer in the array
    //printf(" %d", array[i]);
    
}


// DO NOT CHANGE THE MAIN FUNCTION
int main(void) {

    int numbers[MAX_NUMBERS];

    int i = 0;
    while (i < MAX_NUMBERS && scanf("%d", &numbers[i]) == 1) {
        i++;
    }

    printf("Indivisible numbers:");
    divisible(i, numbers);
    printf("\n");

    return 0;
}
