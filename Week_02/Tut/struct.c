#include <stdio.h>

struct fraction{
    int numberator;
    int denominator;
};


void print_error(void) {
    printf("Denominator cannot be 0");
}


int main (void) {
    int num = 0;
    int denom = 0;
    printf("Enter numberator and denominator: ");
    scanf("%d %d", &num, &denom);
    if (denom == 0) {
        print_error();
        return 1;
    }
    struct fraction f;
    f.numberator = num;
    f.denominator = denom;

    int quotient = f.numberator / f.denominator;
    double fraction_value = (1.5 * f.numberator) / f.denominator;
    // print value 
    printf("");
    return 0;
}