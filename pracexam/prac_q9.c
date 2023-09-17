#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 256
int main(void) {
    char string_1[LENGTH];
    char string_2[LENGTH];
    fgets(string_1, LENGTH, stdin);
    fgets(string_2, LENGTH, stdin);

    for (int i = 0; i < strlen(string_1); i++) {
        for (int j = i + 1; j < strlen(string_1); j++) {
            if (string_1[i] == string_1[j] || string_1[i] == string_1[j] - 32 || string_1[i] == string_1[j] + 32) {
                for (int k = j; k < strlen(string_1); k++) {
                    string_1[k] = string_1[k + 1]; 
                }
                j--;
            }
        }
    }

    for (int i = 0; i < strlen(string_2); i++) {
        for (int j = i + 1; j < strlen(string_2); j++) {
            if (string_2[i] == string_2[j] || string_2[i] == string_2[j] - 32 || string_2[i] == string_2[j] + 32) {
                for (int k = j; k < strlen(string_2); k++) {
                    string_2[k] = string_2[k + 1]; 
                }
                j--;
            }
        }
    }

    int counter = 0;
    for (int i = 0; i < strlen(string_1); i++) {
        for (int j = 0; j < strlen(string_2); j++) {
            if (string_1[i] == string_2[j] || string_1[i] == string_2[j] + 32 || string_1[i] == string_2[j] - 32) {
                if (string_1[i] != '\n' && string_1[i] != '\0' && string_1[i] != ' ') {
                    counter++;
                }
                
            }
        }
    }
    printf("%d\n", counter);
}
