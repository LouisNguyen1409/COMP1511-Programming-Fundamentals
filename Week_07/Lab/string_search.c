// string_search
// string_search.c
//
// This pro was written by Dinh Minh Nhat Nguyen z5428797
// on 29 March 2023
//
// Lets us count the number of times we see any our of "search terms" in a list
// of words.

#include <stdio.h>
#include <string.h>

#define MAX 128

int main(int argc, char *argv[]) {
    char string_input[MAX];
    int counter = 0;

    printf("Enter list of words:\n");
    while (fgets(string_input, MAX, stdin) != NULL) {
        int i = 0;
        while (string_input[i] != '\n') {
            i++;
        }
        string_input[i] = '\0';
        for (int x = 1; x < argc; x++) {
            if (strcmp(argv[x], string_input) == 0) {
                counter += 1;
            }
        }
    }
    printf("There were %d occurrence(s) in the input.\n", counter);

    return 0;
}