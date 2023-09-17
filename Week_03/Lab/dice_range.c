// dice_range
// dice_range.c
//
// This program was written by Dinh Minh Nhat Nguyen z5428797
// on 27/02/2023
//
// Reads the number of sides on a set of dice and how many of them are being 
//rolled. It then outputs the range of possible totals that these dice can 
//produce as well as the average value.

#include <stdio.h>

int main (void) {
    int side = 0;
    int roll = 0;
    printf("Enter the number of sides on your dice: ");
    scanf("%d", &side);
    printf("Enter the number of dice being rolled: ");
    scanf("%d", &roll);

    if (side > 0 && roll > 0) {
        int range = side * roll;
        double average = (roll + range) / 2.0;
        printf("Your dice range is %d to %d.\n", roll, range);
        printf("The average value is %lf\n", average);
    } else {
        printf("These dice will not produce a range.\n");
        return 1;
    }
    return 0;
}