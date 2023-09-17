// Demonstrating how to play with characters in C
// Program asks the user for a letter, checks if the letter is upper or lower
// case and then converts it to the opposite case

// Sasha Week 2, Lecture 3

// Problem: A user inputs a letter, we must check 
// if the letter is upper or lower case and then 
// output the same letter, but in the opposite case
// Possibilities/Breakpoints?
// 


#include <stdio.h>

int main (void){


    // How will we solve the problem?
    // How can we break it?
    
    // Declare and initialise any variables we may use in our solution
    char letter;
    printf("Please eneter a letter: ");
    scanf(" %c", &letter);

    if (letter >= 'a' && letter <= 'z') {
        letter = letter - 'a' + 'A';
    } else if (letter >= 'A' && letter <= 'Z') {
        letter = letter - 'A' + 'a';
    } else {
        printf("You did not enter a number ...\n");
    }

    printf("The new letter is: %c\n", letter);
    return 0;
}