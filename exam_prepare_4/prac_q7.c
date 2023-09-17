#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int array[10000];
    int index = 0;
    while (scanf("%d", &array[index]) == 1 && array[index] != 0) {
        index ++;
    }

    for (int i = 0; i < index; i++) {
        if (i % 2 == 0) {
            printf("%d ", array[i]);
        }
    }

    for (int i = 0; i < index; i++) {
        if (i % 2 != 0) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
    return 0;
}
