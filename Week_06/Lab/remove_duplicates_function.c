// Written by Dinh Minh Nhat Nguyen (z54528797) 
// on 16/03/2023

#include <stdio.h>

int remove_duplicates(int length, int source[length], int destination[length]);
int main(void) {
    int source[6] = {3, 1, 4, 1, 5, 9};
    int destination[10];

    printf("%d\n", remove_duplicates(6, source, destination));

    for (int i = 0; i < 6; i++) {
        printf("%d ", source[i]);
    }
    printf("\n");

    for (int i = 0; i < 6; i++) {
        printf("%d ", destination[i]);
    }
    printf("\n");
    return 0;
}
int remove_duplicates(int length, int source[length], int destination[length]) {
    int num_transfer = 0;
    for (int i = 0; i < length; i++) {
            int is_transfer = 0;
        for (int x = 0; x < length; x++) {
            if (x == 0) {
                destination[num_transfer] = source[i];
                num_transfer += 1;
            } else if (source[i] != destination[x]) {
                is_transfer = 1;
            }
        }
        if (is_transfer == 1) {
            destination[num_transfer] = source[i];
            num_transfer += 1;
        }
    }
    return num_transfer;
}
