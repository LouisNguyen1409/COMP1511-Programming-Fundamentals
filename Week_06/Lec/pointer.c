#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int ben;
    ben = 56;
    int *tom;
    tom = &ben;
    *tom = 8;
    printf("%d\n", ben);
    *tom = 45;
    printf("%d\n", ben);
    *tom = 26;
    printf("%d\n", ben);
    printf("%d\n", *tom);
    int sofia = 100;
    tom = &sofia;
    printf("\n");
    printf("%d\n", sofia);
    printf("%d\n", *tom);
}