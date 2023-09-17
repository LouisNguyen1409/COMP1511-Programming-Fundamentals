// This program demonstrates the use of enums

// Sasha Week 2 Lecture 4

#include <stdio.h>

// 1. Define enum outside your main 
enum weekdays {MON, TUE, WED, THU, FRI, SAT, SUN};

int main(void) {
    // 2. Declare an enum
    enum weekdays days;
    // 3. Initialise enum as needed 
    days = THU;
    printf("The day of the week is %d\n", days);

    return 0;
}    