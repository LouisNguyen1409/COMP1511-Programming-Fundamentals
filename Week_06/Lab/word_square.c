// word_square
// word_square.c
//
// This program was written by Dinh Minh Nhat Nguyen z5428797
// on 16/03/2023
//
// prompts the user to enter a word, and afterwards, prints that word out n 
// amount of times, where n is the length of the word.


#include <stdio.h>
#include <string.h>

#define MAX 1081

int main(void) {
    char user_input[MAX];
    printf("Input word: ");
    fgets(user_input, MAX, stdin);
    printf("\n");
    int str_length  = strlen(user_input);
    user_input[str_length - 1] = '\0';
    printf("Word square is: \n");
    for (int i = 0; i < str_length - 1; i++) {
        printf("%s\n", user_input);
    }
    return 0;
}