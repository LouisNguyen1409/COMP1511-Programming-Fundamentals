// Echo a string in C - demonstrating how strings are read in with fgets()

// Sasha Week 4: Lecture 8: Strings

#include <stdio.h>

#define MAX 20

int main(void) {

    char array[MAX];
    printf("Type in a string to echo: ");
    // let's read in a string and echo it once
    while (fgets(array, MAX, stdin) != NULL) {
        
        printf("%s", array);
        printf("Type in a string to echo: ");
        // array[6] = '\0';
        // printf("%s", array);
    }
    // What about if we want to keep reading strings in and echoing until 
    // Ctrl+D is pressed? 
    // This is indicated by what keyword!?

    
    return 0;
}