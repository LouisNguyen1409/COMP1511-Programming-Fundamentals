// Demonstrating the use of functions with a program 
// that takes in two die rolls and checks whether the 
// sum of the dice is equal to the target number - you win 
// if that is the case! 

// Extending the problem: Otherwise you can roll again... 

#include <stdio.h>

#define TARGET 7

int sum_dice(int die_one, int die_two);
int compare(int sum);

int main(void) {
    int die_one = 0;
    int die_two = 0;

    int flag = 1;

    while (flag == 1) {
        printf("What is the result of rolling die one? ");
        scanf("%d", &die_one); //error checking
        printf("What is the result of rolling die two? ");
        scanf("%d", &die_two); //error checking

        int sum = sum_dice(die_one, die_two); //error checking 1 and 6

        flag = compare(sum);
    }
    return 0;
}

// Let's make some functions!
int sum_dice(int die_one, int die_two) {
    int sum = die_one + die_two;
    return sum;
}

int compare(int sum) {
    int flag = 1;
    if (sum < TARGET) {
        printf("The sum is less than the target number.\n");
        return flag;
    } else if (sum == TARGET) {
        printf("You have the target number! YAY.\n");
        return 0;
    } else {
        printf("The sum is greater than the target number.\n");
        return flag;
    }
}