// This program demonstrates how to access pointers of type struct. 
// Usually we access with a . , however, when we refer to a pointer
// we access with a -> (shorthand, much less likely to make mistakes!) 

// Sasha Vassar, Week 7 Lecture 11

#include <stdio.h>
// we will want to use strcpy function, so get access to the string.h library
#include <string.h>

#define MAX 15

// 1. Define struct
struct ice_cream {
    char name[MAX];
    double price;
};

int main (void) {
    // 2. Declare struct
    struct ice_cream my_ice_cream;

    // TODO: Demonstrating pointers of type struct
    // Have a pointer that points to the variable my_ice_cream of type 
    // struct ice_cream   
    // pointer to an int: int *my_ptr
    struct ice_cream *ice_cream_ptr = &my_ice_cream;

    // TODO:3. Initialise struct (access members with .)
    // my_ice_cream.price = 2.50;
    //my_ice_cream.name = "Dulce";
    // strcpy(my_ice_cream.name, "Dulce");  

    ice_cream_ptr->price = 2.50;
    strcpy(ice_cream_ptr->name, "Dulce");

    // TODO: Demonstrating pointers of type struct - accessing
    // How would we initialise it using the pointer?
    // Perhaps dereference the pointer and access the member?
    printf("The ice cream %s costs %lf\n", ice_cream_ptr->name, ice_cream_ptr->price); 
    
    return 0;
}