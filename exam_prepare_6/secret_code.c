#include <stdio.h>

int main(void) {
    char char_1;
    char char_2;
    while (scanf("%c", &char_1) == 1 && scanf("%c", &char_2) == 1) {
        if (char_1 > char_2) {
            printf("%c", char_2);
        } else if (char_1 < char_2) {
            printf("%c", char_1);
        } else if (char_1 == char_2) {
            printf("%c", char_1);
        }
    }
    printf("\n");
    return 0;
}