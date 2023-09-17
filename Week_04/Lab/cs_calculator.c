// 
// Written 08/03/2023
// By Dinh Minh Nhat Nguyen z5428797
//
// scan in instructions until End-Of-Input and prints the output as specified 
// below. Instruction is a character, followed by one or two positive integers

#include <stdio.h>

int power (int number_1, int number_2);
int main(void) {
    char instruction;
    int number_1 = 0;
    int number_2 = 0;
    int output_result = 0;
    int flag = 0;

    while (flag == 0) {
        printf("Enter instruction: ");
        int scanf_return = scanf(" %c", &instruction);

        if (scanf_return == EOF) {
            return 0;
        }

        if (instruction == 's') {
            scanf("%d", &number_1);
            output_result = power(number_1, 2);
        } else {
            scanf("%d %d", &number_1, &number_2);
            output_result = power(number_1, number_2);
        }
        printf("%d\n", output_result);
    }


    return 0;
}

int power (int number_1, int number_2) {
    int result = number_1;
    for (int i = 1; i < number_2; i++) {
        result *= number_1;
    }
    return result;
}