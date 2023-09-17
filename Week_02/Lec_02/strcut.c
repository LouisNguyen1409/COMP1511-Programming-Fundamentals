// This program demonstrates the use of structs

// Sasha Week 2 Lecture 4

#include <stdio.h>

// 1. Define the struct outside our main
struct jellybean {
    char colour;
    int amount;
    double weight;
    int tastiness;

};
struct packet {
    double wieght;
    int packet_size;
    char brad;
};

int main(void) {

    // 2. Declare that you will use a struct
    struct jellybean bean;


    // 3. Assign values to a struct variable
    bean.colour = 'c';
    bean.amount = 5;
    bean.weight = 6.4;
    bean.tastiness = 3;

    printf("The jellybean of colour %c, has amount %d\n", bean.colour, bean.amount);
    return 0;
}