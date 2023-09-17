// Program which prints a letter depending on the user's request.
// by z5428797

#include <stdio.h>

int main(void) {

    char is_uppercase;
    printf("Uppercase: ");
    scanf(" %c", &is_uppercase);

    int index;
    printf("Index: ");
    scanf("%d", &index);
    index += 65;
    if (is_uppercase == 'n') {
        index += 97 - 65;
    }
    printf("The letter is %c\n", index);


    return 0;
}