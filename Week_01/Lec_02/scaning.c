#include <stdio.h>

int main (void)
{
    int number = 0;
    int number_2;
    printf("Please enter 2 number: ");
    scanf("%d %d", &number, &number_2);
    int total = number % number_2;

    printf("The result is: %d\n", total);
    // char character;
    // printf("Please enter a character: ");
    // scanf(" %c", &character);
    // printf("The character that was scanned in is: %c\n", character);
    // double decimal;
    // printf("Please enter a decimal number: ");
    // scanf("%lf", &decimal);
    // printf("The decimal that was sacnned in is: %.2lf\n", decimal);
    return 0;
}