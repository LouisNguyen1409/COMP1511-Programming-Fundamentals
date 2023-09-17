#include <stdio.h>

int main(void) {
    char char_odd;
    char char_even;
    char final;

    while (scanf("%c", &char_even) == 1 && scanf("%c", &char_odd) == 1) {
        if (char_odd > char_even) {
            final = char_even;
            printf("%c", final);
        } else if (char_odd < char_even) {
            final = char_odd;
            printf("%c", final);
        } else if (char_odd == char_even) {
            final = char_odd;
            printf("%c", final);
        }
    }
    printf("\n");


    return 0;
}