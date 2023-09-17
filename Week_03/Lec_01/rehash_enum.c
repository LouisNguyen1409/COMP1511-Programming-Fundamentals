#include <stdio.h>


enum month {
    JAN,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

enum favourite_month {
    MAR,
    DEC
};

int main(void) {
    enum month month_name;
    month_name = SEP;
    printf("The month is %d\n", month_name);
    return 0;
}