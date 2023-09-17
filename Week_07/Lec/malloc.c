// This program gives an example of how you can allocate memory
// for an array and then read in the array and print it out in 
// reverse order.

// We will then dynamically change the memory allocation with realloc()

// From previous weeks, do you remember that the only way to give an array
// necessary space is really to guess the size needed - so often we will guess
// a huge number and waste a lot of space... What if we knew the size of the
// array and could give memory based on size of the array?

// Sasha Vassar Week 7 Lecture 11

#include <stdio.h>

// malloc(), realloc() and free() live inside the <stdlib.h>
#include <stdlib.h>


// some functions that may be useful
void read_array(int *numbers, int size);
//void reverse_array(int *numbers, int size);
void print_array(int *ptr, int size); 


int main (void) {
    
    // Find out the size of the array:
    int size;
    printf("How many numbers would you like to scan: ");
    scanf("%d", &size); //size = 5
    
    // TODO Allocate some memory space for my array to store 
    // size number of elements and return a pointer
    // to the first element
    // Syntax of malloc()
    // int *ptr = malloc(x * sizeof(data_type))
    int *ptr = malloc(size * sizeof(int)); // allocate enough space for 5 * 4bytes
    
    // TODO Check if there is actually enough space to allocate
    // memory, exit the program if there is not enough memory
    // to allocate.
    if (ptr == NULL) {
        printf("There is not enough memory to allocate\n");
        return 1;
    } 
    
    // Perform some functions here  
    read_array(ptr, size);

    print_array(ptr, size);
    // Decide to extend array and need a bigger array now

    // Find out the new size of the array:
    int new_size;
    printf("How many more numbers would you like to scan: ");
    scanf("%d", &new_size); 

    // Extend the array to three extra numbers
    // realloc()
    // int *new_ptr = realloc(previous_ptr, x * sizeof(data_type))
    int *new_ptr = realloc(ptr, new_size * sizeof(int));

    //for(int i = 0; i)

    // continue loading the array:
    //continue_array(, size, new_size);

    // For funsies:
    //reverse_array(numbers, size);
    
    // Free the allocated memory
    // (In this case, it would happen on program exit anyway)
    free(ptr);
    print_array(ptr, size);
    return 0;
}

// TODO Helper function that reads in numbers and places them into an array
void read_array(int *ptr, int size) {
    // TODO
    for(int i = 0; i < size; i++) {
        printf("Enter in a number: ");
        scanf("%d", &ptr[i]);
    }
}


void print_array(int *ptr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}
// TODO Helper function that reads in numbers and places them into an array
// with new size
//void continue_array(int *numbers, int size, int new_size) {
    // TODO
//}

// TODO: Finish the helper function to reverse the elements of the array
//void reverse_array(int *numbers, int size) {
    // TODO
//}

// We can play with other functions if there is time!