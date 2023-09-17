// devowel
// devowel.c
//
// This program was written by Dinh Minh Nhat Nguyen z5428797
// on 08/03/2023
//
// reads characters from its input and writes the same characters to its output
// , except it does not write lower case vowels ('a', /'e', 'i', 'o', 'u').



#include <stdio.h>

#define VOWELS 5

int main (void) {
    char array[VOWELS] = {'a', 'e', 'i', 'o', 'u'};
    char user_input;

    while (VOWELS == 5) {
        int scanf_return = scanf("%c", &user_input);
        int flag = 0;
        if (scanf_return == EOF) {
            return 0;
        }
        for (int i = 0; i < VOWELS; i++) {
            
            if (user_input == array[i]) {
                flag = 1;
            }
        }
        if (flag != 1) {
            printf("%c", user_input);
        }
    }
    return 0;
}
