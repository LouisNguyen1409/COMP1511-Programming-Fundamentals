// This is the main file in our program
// This is where we drive the program from and where
// we make the calls to our modules. We need to include
// our header file here again, and in every module where
// we will want to use the functions defined in the header.

// Include it by: 
// #include "my_header.h"
#include <stdio.h>

#include "maths.h"

int main (void) {
    double radius;
    printf("Enter a radius: ");
    scanf("%lf", &radius);

    printf("The area of the circle with radius %lf is %lf\n", radius, area_circle(radius));

    printf("The absolute value of -3 is %d\n", absolute_value(-3));

    printf("The sum of 3 + 5 is %d\n", sum(3,5));

    return 0;
}