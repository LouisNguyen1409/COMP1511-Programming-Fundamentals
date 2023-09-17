// Demonstrating the use of a while loop with a sentinel
// condition.
// Sasha Week 2, Lecture 3

// Problem: I want to read in some numbers until a negative number has been 
// entered, and sum up all the positive numbers. 
// Let's think through the steps to solve this!


#include <stdio.h>

int main (void){
    int number = 0;
    int flag = 0;
    int sum = 0;
    while (flag == 0) {
        scanf("%d", &number);
        if (number < 0) {
            flag = 1;
        } else {
            sum += number;
        }
    }
    printf("The sum is: %d\n", sum);


    return 0;
}