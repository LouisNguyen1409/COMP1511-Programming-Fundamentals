// Recapping 1D arrays! (an array of structs)
// Problem: A dog walking business is keeping track of which dogs are 
// being walked on which day. Each dog is represented as a struct where
// information is stored about the dog's name, age and size. On Monday, 
// we are walking three dogs:
// name: b, age: 4, size: L
// name: a, age: 3, size: XL
// name: c, age: 7, size: M
// Input these into the array and then print out what is happening for the 
// dog walk on Monday. 

// You just got a call, that B is not going to be walking with you tomorrow, 
// and instead you will walk:
// name: d, age: 6, size: M

#include <stdio.h>

struct dog {
    char name;
    int age;
    char size;
};

#define MAX 5


int main(void) {

    struct dog array_dogs[MAX];

    array_dogs[0].age = 7;
    array_dogs[0].size = 'M';

    for (int i = 0; i < MAX; i++) {
        printf("Please enter age of the dog: ");
        scanf("%d", &array_dogs[i].age);
        printf("Please enter size of the dog: ");
        scanf(" %c", &array_dogs[i].size);
    }

    for (int i = 0; i < MAX; i++) {
        printf("The age of the dog is %d, "
        "and the size is %c\n", array_dogs[i].age, array_dogs[i].size);
    }

    return 0;
}