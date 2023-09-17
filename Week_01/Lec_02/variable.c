#include <stdio.h>

int main(void)
{
    int number = 42; 
    // int number_2 = 13;
    // single quote '' is using ascii table
    char letter = 'S';
    double decimal = 3.14;
    // %d for int
    // %c for char
    // %lf for double
    printf("The number %d, the char is %c, the decimal is %.2lf\n", number, letter, decimal);
    return 0;
}