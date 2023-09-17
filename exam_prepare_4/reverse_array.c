#include <stdio.h>

int main(void) {
    int array[100];
    int clone_array[100];
    printf("Enter numbers forwards:\n");
    int index = 0;
    while (scanf("%d", &array[index]) == 1) {
        index++;
    }

    printf("Reversed:\n");
    for (int i = 0; i < index; i++) {
        clone_array[i] = array[index - 1 - i];
    }

    for (int i = 0; i < index; i++) {
        printf("%d\n", clone_array[i]);
    }
    return 0;
}