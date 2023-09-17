#include <stdio.h>

int main(void) {
    int total = 0;
    for (int i = 0; i < 100;i++) {
        total += i;
    }
    fprintf("%d\n", total);
}