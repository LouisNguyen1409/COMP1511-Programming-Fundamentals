// Let's create a simple program that will 
// calculate area of a rectangle, and let's try 
// and use some functions in this program! 

// Sasha Week 3 Lecture 5

#include <stdio.h>

int calculate_area(int lenght, int width);

int main(void) {
    int lenght = 0;
    int width = 0;
    
    printf("Please enter the length and width of the rectangle: ");
    int scanf_return = scanf("%d %d", &lenght, &width);
    if (scanf_return == 2){
        int area = calculate_area(lenght, width);
        printf("The area is %d\n", area);
    }
    
    return 0;
}

int calculate_area(int lenght, int width) {
    int area = lenght * width;
    return area;
}