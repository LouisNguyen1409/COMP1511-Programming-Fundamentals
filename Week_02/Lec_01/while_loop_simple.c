#include <stdio.h>

int main (void) {
    int counter = 0; 
    int number_prints = 0 ;
    printf("how many time would you like to print something? ");
    scanf("%d", &number_prints);

    while (counter < number_prints) {
        printf("I love COMP 1511\n");
        counter ++;
    }

    return 0;
}