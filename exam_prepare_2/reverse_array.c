#include <stdio.h>

#define MAX 100
int main(void) {
    int array[MAX];
    int clone_array[MAX];
    int index = 0;
    printf("Enter numbers forwards: \n");
    while (scanf("%d", &array[index]) == 1) {
        index++;
    }

    for (int i = 0; i < index; i++) {
        clone_array[i] = array[index - i - 1];
    }

    printf("Reversed:\n");
    for (int i = 0; i < index; i++) {
        printf("%d\n", clone_array[i]);
    }
    return 0;
}