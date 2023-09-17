// This program demonstrates how sizeof() function works
// It returns the size of a specified data type
// We use format specifier %lu because sizeof() returns an unsigned long int  

// Sasha Vassar Week 7, Lecture 11


#include <stdio.h>

int main (void) {

    // Declare and initialise an array of size 10 to use as an example for 
    // array sizing
    int array[10] = {0};
    
    //Example of using the sizeof() function
    printf("The size of an int is %lu bytes\n", sizeof(int));
    printf("The size of an array of ints is %lu bytes\n", sizeof(array));
    printf("The size of 10 ints is %lu bytes\n", 10 * sizeof(int));
    printf("The size of a double is %lu bytes\n",sizeof(double));
    printf("The size of a char is %lu bytes\n", sizeof(char));
    
    return 0;
}
