// get_letter
// get_letter.c
//
// This program was written by Dinh Minh Nhat Nguyen z5428797
// on 19/02/2023
//
// Program which prints a letter depending on the user's request.

#define UPPER 65
#define LOWER 97

#include <stdio.h>

int main(void) {

    char is_uppercase;
    printf("Uppercase: ");

    // TODO: scan is_uppercase
    scanf("%c", &is_uppercase);

    int index;
    printf("Index: ");

    // TODO: finish the program
    scanf("%d", &index);

    if (is_uppercase == 'y') {
        printf("The letter is %c\n", index + UPPER);
    } else if (is_uppercase == 'n') {
        printf("The letter is %c\n", index + LOWER);
    }


    return 0;
}