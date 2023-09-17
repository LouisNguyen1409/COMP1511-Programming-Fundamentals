// Demonstrating using IF statements
// with logical operators AND and OR

// Sasha Vassar, Week 2 Lecture 3

// Problem 0: "Can we take song requests?" Ask the question and take a song
// request if the answer is yes, otherwise quit the program
// 1. Make a decision based on taking a song request
// 2. We need to ask a question if we take a song request
// 3. We need to take the input in (scanf) y/n
// 4. Branch - ask for a song if yes
// 5. Branch - quit if not


// Problem 1: Let the user provide you a number 1-100, that you then check 
// and decide how many digits that number has. 
// number >= 0 && number <= 9
// number >= 10 && number <=99
// number >= 100


// Problem 2: Let the user provide you any number, and you must determine if
// the number is even or odd.

// Let's do problem 0 first and see how we go

#include <stdio.h>

int main(void) {
    
    // Declare and initialise some variables that you want to store things in
    int number = 0;
    printf("Please enter a number: ");

    int scanf_return;
    scanf_return = scanf("%d", &number);
    printf("scanf_return is equal to %d\n", scanf_return);
    
    if (scanf_return == 1) {
        if (number >= 0 && number <= 9) {
            printf("The number has 1 digit.\n");
        } else if (number >= 10 && number <=99) {
            printf("The number has 2 digits.\n");
        } else if (number >= 100) {
            printf("The number has more than 2 digits.\n");
        } else {
            printf("The number is negative.\n");
        }
    }



    return 0;
}