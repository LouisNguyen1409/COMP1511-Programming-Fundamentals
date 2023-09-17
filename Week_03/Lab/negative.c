// Read in a number, and determine whether it is negative.
// by Dinh Minh Nhat Nguyen z5428797


#include <stdio.h>

//////////////// DO NOT CHANGE ANY OF THE CODE BELOW HERE //////////////////
// Procedures for outputting user messages:

// Outputs: "You have entered a positive number.\n"
void print_positive_message(void) {
    printf("You have entered a positive number.\n");
}

// Outputs: "Don't be so negative!\n"
void print_negative_message(void) {
    printf("Don't be so negative!\n");
}

// Outputs: "You have entered zero.\n"
void print_zero_message(void) {
    printf("You have entered zero.\n");
}

//////////////// DO NOT CHANGE ANY OF THE CODE ABOVE HERE //////////////////


int main(void) {

    // TODO: scan in a number and test whether it is positive, negative or 0.
    int user_input = 0;
    scanf("%d", &user_input);
    // TODO: use the procedures defined above to print the relevant message.
    if (user_input < 0) {
        print_negative_message();
    } else if (user_input == 0) {
        print_zero_message();
    } else if (user_input > 0) {
        print_positive_message();
    }

    return 0;
}
