// substitution
// substitution.c
//
// This program was written by Dinh Minh Nhat Nguyen z5428797
// on 29 March 2023
// 
// Reads characters from its input and writes the characters to its output
// encrypted with a Substitution cipher.

#include <stdio.h>
#include <ctype.h>

#define CHARACTERS 26

void print_output(char mapping[CHARACTERS + 2], char mapping_upper [CHARACTERS]
, char og[CHARACTERS], char op_upper[CHARACTERS]);

int main(void) {
    printf("Enter mapping:\n");
    char mapping[CHARACTERS + 2];
    char mapping_upper [CHARACTERS];
    char og[] = "abcdefghijklmnopqrstuvwxyz";
    char op_upper[CHARACTERS];
    fgets(mapping, CHARACTERS + 2, stdin);
    int i = 0;
    while (mapping[i] != '\n') {
        i ++;
    }
    mapping[i] = '\0';

    for (int oder_map = 0; mapping[oder_map]; oder_map++) {
        mapping_upper[oder_map] = toupper(mapping[oder_map]);
    }

    for (int order_og = 0; mapping[order_og]; order_og++) {
        op_upper[order_og] = toupper(og[order_og]);
    }


    print_output(mapping, mapping_upper, og, op_upper);

    return 0;
}

void print_output(char mapping[CHARACTERS + 2], char mapping_upper [CHARACTERS]
, char og[CHARACTERS], char op_upper[CHARACTERS]) {
    printf("Enter text:\n");
    char input;
    while (scanf("%c", &input) != EOF) {
        int place_og = -1;
        int place_upper = -1;
        for (int x = 0; x < CHARACTERS; x++) {
            if (input == og[x]) {
                place_og = x;
            } else if (input == op_upper[x]) {
                place_upper = x;
            }
        }

        if (place_og != -1) {
            input = mapping[place_og];
        } else if (place_upper != -1) {
            input = mapping_upper[place_upper];
        }
        
        printf("%c", input);
    }
}
