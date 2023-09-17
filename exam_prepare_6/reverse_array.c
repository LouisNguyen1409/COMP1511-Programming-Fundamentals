#include <stdio.h>

int main(void) {
    int array[100];
    int clone_array[100];
    int index = 0;
    
    printf("Enter numbers forwards:\n");
    while (scanf("%d", &clone_array[index]) == 1) {
        index++;
    }

    for (int i = 0; i < index; i++) {
        array[i] = clone_array[index - 1 - i];
    }

    printf("Reversed:\n");
    for (int i = 0; i < index; i++) {
        printf("%d\n", array[i]);
    }
    return 0;
}