#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 1500

void add(char* result, char* num1, char* num2) {
    int carry = 0;
    for (int i = MAX_DIGITS-1; i >= 0; i--) {
        int sum = num1[i] - '0' + num2[i] - '0' + carry;
        carry = sum / 10;
        result[i] = (sum % 10) + '0';
    }
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    char current[MAX_DIGITS+1];
    char previous1[MAX_DIGITS+1];
    char previous2[MAX_DIGITS+1];
    char previous3[MAX_DIGITS+1];

    memset(previous1, '0', sizeof(previous1));
    memset(previous2, '0', sizeof(previous2));
    memset(previous3, '0', sizeof(previous3));
    previous1[MAX_DIGITS-1] = previous2[MAX_DIGITS-1] = previous3[MAX_DIGITS-1] = '1';

    if (n == 1 || n == 2 || n == 3) {
        printf("1");
        return 0;
    }

    for (int i = 4; i <= n; i++) {
        add(current, previous1, previous2);
        add(current, current, previous3);

        memcpy(previous1, previous2, sizeof(previous1));
        memcpy(previous2, previous3, sizeof(previous2));
        memcpy(previous3, current, sizeof(previous3));
    }

    int leadingZero = 1;
    for (int i = 0; i < MAX_DIGITS; i++) {
        if (current[i] != '0') {
            leadingZero = 0;
        }
        if (!leadingZero) {
            printf("%c", current[i]);
        }
    }
    printf("\n");

    return 0;
}
