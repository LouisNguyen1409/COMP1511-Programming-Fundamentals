// print_grid
// print_grid.c
//
// This program was written by Dinh Minh Nhat Nguyen z5428797
// on 27/02/2023
//
// Reads an integer n from standard input. and prints an n x n grid with all 
// the coordinates of the grid shown.

#include <stdio.h>

int main (void) {
    int size = 0;
    printf("Enter size: ");
    scanf("%d", &size);
    

    int row = 0;
    while (row < size) {
        int col = 0;
        while (col < size) {
            printf("(%d, %d) ", row, col);
            col ++;
        }
        printf("\n");
        row ++;
    }

    return 0;
}