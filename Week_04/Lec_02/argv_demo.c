#include <stdio.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
    printf("There are %d command line arguments in this program\n", argc);

    //argv[0] is always the program name
    printf("The program name is %s (argv[0])\n", argv[0]);

    // What about the other command line arguments? Let's loop through
    // the array and print them all out! 
    for (int i = 0; i < argc; i++) {
        printf("The command line argument at index %d"
                "argv[%d] is %s\n", i, i, argv[i]);
    }
    printf("%c\n", argv[2][1]);
    
    return 0;
}