#include <stdio.h>

#define MAX 100
int main(void) {
    printf("Enter numbers forwards:\n");
    int array[MAX];
    int clone_array[MAX];
    int index = 0;

    while (scanf("%d", &array[index]) == 1) {
        index++;
    }

    for (int i = 0; i < index; i++) {
        clone_array[i] = array[index - 1 - i];
    }

    printf("Reversed:\n");
    for (int i = 0; i < index; i++) {
        printf("%d\n", clone_array[i]);
    }
    return 0;
}