#include <stdio.h>

int main(void) {
    int array[100];
    int clone_array[100];

    printf("Enter numbers forwards:\n");
    int index = 0;
    while (scanf("%d", &clone_array[index]) == 1) {
        index ++;
    }
    printf("Reversed:\n");
    for (int i = 0; i < index; i++) {
        array[i] = clone_array[index - 1 - i];
        printf("%d\n", array[i]);
    }

    return 0;
}