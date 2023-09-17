#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    // Remember that the command line arguments are all strings, so if you 
    // need to do mathematical operations, you will need to convert them 
    // to numbers
    // You can do this with a really handy function atoi() in the stdlib.h library!

    // Let's print out all the command line arguments given and then add
    // them together to give the sum of the command line arguments

    int sum = 0;
    for (int i = 1; i < argc; i++) {
        printf("The command line argument at index %d (argv[%d]) is %d\n", 
                i, i, atoi(argv[i]));
        sum = sum + atoi(argv[i]);
    }
    printf("The sum of the arguments is %d\n", sum);
    
    return 0;
}