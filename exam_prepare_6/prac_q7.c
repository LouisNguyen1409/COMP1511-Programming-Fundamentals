#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int array[10000];
    int index = 0;
    while (scanf("%d", &array[index]) && array[index] != 0) {
        index += 1;
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
}
