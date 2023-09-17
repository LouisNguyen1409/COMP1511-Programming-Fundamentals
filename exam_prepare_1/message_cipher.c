#include <stdio.h>

#define ALPHABET 26

void determine_ciphering(char letter1, char letter2, char letter3, char letter4) {
    printf("Would you like to encipher or decipher this message (e/d)? ");
    char cipher;
    scanf(" %c", &cipher);
    printf("Enter numbers to decipher by:");
    int num_1, num_2, num_3, num_4;
    scanf("%d %d %d %d", &num_1, &num_2, &num_3, &num_4);
    num_1 = num_1 % ALPHABET;
    num_2 = num_2 % ALPHABET;
    num_3 = num_3 % ALPHABET;
    num_4 = num_4 % ALPHABET;
    if (cipher == 'e') {
        if ()
    }
}

void encipher(char letter, int number) {
    if (letter >= 65 && letter <= 90) {
        letter += number;
        if (letter < 65 && letter > 90) {
            
        }
    } else if (letter >= 97 && letter <= 122) {
        letter += number;
    }
}   

int main(void) {

    char letter1;
    char letter2;
    char letter3;
    char letter4;

    printf("Message: ");
    scanf(
        "%c %c %c %c",
        &letter1, &letter2, &letter3, &letter4
    );

    determine_ciphering(letter1, letter2, letter3, letter4);
}
