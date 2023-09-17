// A while inside a while (tick tock)
// Demonstrating how you can put a while inside a while to print out a 
// grid of numbers
// Sasha Week 2, Lecture 4

/* Problem: Print out a grid of numbers that looks like this: 

1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5

*/
#define MAX 5

#include <stdio.h>

int main(void) {

    // 1. Initialise a loop control
    // 2. Test Loop control
    // 3. Update loop control
    
    int col = 0;
    while (col < MAX) {
        int row = 0;
        while (row < MAX) {
            printf("%d ", row + 1);
            row ++;
        }
        printf("\n");
        col ++;
    }


    return 0;
}