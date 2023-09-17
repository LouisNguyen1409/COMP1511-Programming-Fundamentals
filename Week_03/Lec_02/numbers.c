#include <stdio.h>

#define MAX_ARRAY 7

void print_array(int array[MAX_ARRAY]);

int main (void) {
    int array[MAX_ARRAY] = {1,3,4,5,9,10,11};
    int product;

    print_array(array);
    array[MAX_ARRAY - 1] = 40;
    print_array(array);

    for (int i = 0; i < MAX_ARRAY; i++) {
        product = product * array[i];
    }

    printf("The product is %d", product);

    return 0;
}

void print_array(int array[MAX_ARRAY]) {
    for (int i = 0; i < MAX_ARRAY; i++) {
        printf("%d\n", array[i]);
    }
}