// message_cipher
// message_cipher.c
//
// This program was written by Dinh Minh Nhat Nguyen z5428797
// on 19/02/2023
//
// scans in a message and either enciphers or deciphers it

#include <stdio.h>

struct message {
    char letter1;
    char letter2;
    char letter3;
    char letter4;
};

struct number {
    int number1;
    int number2;
    int number3;
    int number4;
};

#define ALPHABET 26


// You may find it helpful to add extra procedures here. Procedures that
// encipher/decipher the entire `msg` may be useful.
//


int check_char(char letter) {
    int is_upper = 0;
    if (letter >= 'A' && letter <= 'Z') {
        is_upper =  0;
    } else if (letter >= 'a' && letter <= 'z') {
        is_upper = 1;
    }
    return is_upper;
}

char check_inrange_upper(char letter, int number) {
    int diff = 0;
    char final_char = letter + number;
    if ((letter + number) > 'Z') {
        diff = (letter + number) - 'Z' - 1;
        final_char = 'A' + diff;
    } else if ((letter + number) < 'A') {
        diff = 'A' - (letter + number) - 1;
        final_char = 'Z' - diff;
    }
    return final_char;
}

char check_inrange_lower(char letter, int number) {
    int diff = 0;
    char final_char = letter + number;
    if ((letter + number) > 'z') {
        diff = (letter + number) - 'z' - 1;
        final_char = 'a' + diff;
    } else if ((letter + number) < 'a') {
        diff = 'a' - (letter + number) - 1;
        final_char = 'z' - diff;
    }
    return final_char;
}

void encipher(char letter, int number) {
    int upper_result = check_char(letter);
    char final_char = 'a';
    if (upper_result == 0) {
        final_char = check_inrange_upper(letter, number);
    } else if (upper_result == 1) {
        final_char = check_inrange_lower(letter, number);
    }

    printf("%c", final_char);
}

void decipher(char letter, int number) {
    int upper_result = check_char(letter);
    char final_char = 'a';
    if (upper_result == 0) {
        final_char = check_inrange_upper(letter, -number);
    } else if (upper_result == 1) {
        final_char = check_inrange_lower(letter, -number);
    }
    printf("%c", final_char);
}


// Likewise, procedures that encipher/decipher single letters will help reduce
// code repetition. It is completely up to you whether to create these
// procedures, but we *highly* recommend you do for practice!

// Determines cyphering for a given msg and prints out the result
void determine_ciphering(struct message msg) {
    // TODO: Complete this procedure. This IS needed to compile your program.
    
    struct number number;

    char choice;
    printf("Would you like to encipher or decipher this message (e/d)? ");
    scanf(" %c", &choice);

    if (choice == 'e') {
        printf("Enter numbers to encipher by: ");
        scanf("%d %d %d %d", 
        &number.number1, &number.number2, &number.number3, &number.number4
        );
    
        encipher(msg.letter1, number.number1 % ALPHABET);
        encipher(msg.letter2, number.number2 % ALPHABET);
        encipher(msg.letter3, number.number3 % ALPHABET);
        encipher(msg.letter4, number.number4 % ALPHABET);
        printf("\n");

    } else if (choice == 'd') {
        printf("Enter numbers to decipher by: ");
        scanf("%d %d %d %d", 
        &number.number1, &number.number2, &number.number3, &number.number4
        );

        decipher(msg.letter1, number.number1 % ALPHABET);
        decipher(msg.letter2, number.number2 % ALPHABET);
        decipher(msg.letter3, number.number3 % ALPHABET);
        decipher(msg.letter4, number.number4 % ALPHABET);
        printf("\n");
    }
}

////////////////////////////////////////////////////////////////////////////////
///////////////////// DO NOT EDIT THIS MAIN FUNCTION ///////////////////////////
////////////////////////////////////////////////////////////////////////////////
// This main function scans a message and then calls your determine_ciphering
// procedure, passing in the message.
int main(void) {
    struct message msg;
    
    // Scan message into `msg` struct
    printf("Message: ");
    scanf(
        "%c %c %c %c",
        &msg.letter1, &msg.letter2, &msg.letter3, &msg.letter4
    );

    // Call your determine_ciphering function and pass in the message.
    determine_ciphering(msg);
}
