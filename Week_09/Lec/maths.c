// This is the implementation file of maths.h
// This is where you will implement all the functions
// that were defined (prototyped) in the header file

// Include the header file in the implementation file
// so that everyone knows where your definitions are
// #include "my_header.h"

#include "maths.h"

int absolute_value(int number) {
    if (number < 0) {
        return number  * -1;
    } 
    return number;
}

double area_circle(double radius) {
    double area = Pi * radius * radius;
    return area;
}

int sum(int num_1, int num_2) {
    return num_1 + num_2;
}

