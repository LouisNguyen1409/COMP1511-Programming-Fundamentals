#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256
int main(void) {
    char str_1[SIZE];
    char str_2[SIZE];
    fgets(str_1, SIZE, stdin);
    fgets(str_2, SIZE, stdin);

    for (int i = 0; i < strlen(str_1); i++) {
        for (int j = i + 1; j < strlen(str_1); j++) {
            if (str_1[i] == str_1[j]) {
                for (int k = j; k < strlen(str_1); k++) {
                    str_1[k] = str_1[k + 1];
                }
                j--;
            }
            
        }
    }

    for (int i = 0; i < strlen(str_2); i++) {
        for (int j = i + 1; j < strlen(str_2); j++) {
            if (str_2[i] == str_2[j]) {
                for (int k = j; k < strlen(str_2); k++) {
                    str_2[k] = str_2[k + 1];
                }
                j--;
            }
            
        }
    }
    
    int counter = 0;
    for (int i = 0; i < strlen(str_1); i++) {
        for (int j = 0; j < strlen(str_2); j++) {
            if ((str_1[i] == str_2[j] || str_1[i] == str_2[j] + 32 || str_1[i] == str_2[j] - 32) && str_1[i] != '\n' && str_1[i] != '\0' && str_1[i] != ' ') {
                counter += 1;
            }
        }
    }

    printf("%d\n", counter);

}
