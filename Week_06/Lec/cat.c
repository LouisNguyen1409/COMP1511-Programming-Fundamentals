#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // printf("%s\n", argv[1]);
    // printf("%d\n", argc);
    // for (int i = 0; i < argc; i++) {
    //     printf("%s ", argv[i]);
    // }
    // printf("\n");
    // int x = atoi(argv[1]);
    // int y = atoi(argv[2]);
    // printf("%d\n", x);
    // printf("%d\n", y);
    if (strcmp(argv[1], argv[2]) == 0) {
        printf("Same\n");
    } else {
        printf("Diff\n");
    }

}