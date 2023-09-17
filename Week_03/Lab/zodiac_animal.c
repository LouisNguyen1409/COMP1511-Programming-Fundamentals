// ask the user to enter their birth year. It should then print out what
// (approximate) Chinese zodiac animal that year corresponds to.
// Written by Dinh Minh Nhat Nguyen (z5428797) 
// on 27/02/2023

#include <stdio.h>

// This year corresponds to the Rat.
#define MIN_YEAR 1900

// Enum defining the different zodiac ANIMALS
enum zodiac_animal {
    RAT,
    OX,
    TIGER,
    RABBIT,
    DRAGON,
    SNAKE,
    HORSE,
    GOAT,
    MONKEY,
    ROOSTER,
    DOG,
    PIG
};

int main(void) {
    printf("Enter the year of your birth: ");
    //TODO complete the program:
    enum zodiac_animal animal;
    int year = 0;
    scanf("%d", &year);
    year = (year - MIN_YEAR) % (animal + 1);

    // animal = RAT;
    if (year == RAT) {
        printf("You were born in the year of the Rat!\n");
    } else if (year == animal + 1) {
        printf("You were born in the year of the Ox!\n");
    } else if (year == animal + 2) {
        printf("You were born in the year of the Tiger!\n");
    } else if (year == animal + 3) {
        printf("You were born in the year of the Rabbit!\n");
    } else if (year == animal + 4) {
        printf("You were born in the year of the Dragon!\n");
    } else if (year == animal + 5) {
        printf("You were born in the year of the Snake!\n");
    } else if (year == animal + 6) {
        printf("You were born in the year of the Horse!\n");
    } else if (year == animal + 7) {
        printf("You were born in the year of the Goat!\n");
    } else if (year == animal + 8) {
        printf("You were born in the year of the Monkey!\n");
    } else if (year == animal + 9) {
        printf("You were born in the year of the Rooster!\n");
    } else if (year == animal + 10) {
        printf("You were born in the year of the Dog!\n");
    } else if (year == animal + 11) {
        printf("You were born in the year of the Pig!\n");
    }

    return 0;
}

