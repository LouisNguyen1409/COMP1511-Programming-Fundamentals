// count_up_down
// count_up_down.c
// 
// This program was written by Dinh Minh Nhat Nguyen z5428797
// on 27/02/2023
// 
// Reads one integer n and prints all integers from 0 to n inclusive one per line.

#include <stdio.h>

int main (void) {
    int user_input = 0;
    int i = 0;
    printf("Enter number: ");
    scanf("%d", &user_input);
    if (user_input > 0) {
        while (i <= user_input) {
            printf("%d\n", i);
            i ++;
        }
    } else if (user_input < 0) {
        while (i >= user_input) {
            printf("%d\n", i);
            i --;
        }
    }

    return 0;
}