// This program demonstrates a string in C and all the 
// wonderful things we can do with strings using our special
// library <string.h>
// Sasha Week 4: Lecture 8: Strings (An array of char)

#include <stdio.h>
// You will have to include a string library here, if you want
// to use all the wonderful functions that already exist for 
// strings! 
#include <string.h>

// Define the maximum size of the array
#define MAX 6

int main(void) {

    char array[MAX];

    // How would I put a word into my array from terminal?
    printf("Enter a word: ");

    fgets(array, MAX, stdin);

    printf("%s\n", array);

    // What happens when I manipulate the string and change 
    // things in the array (eg. move the null terminating char)?



  	// Example using strcpy to copy from one string
    // to another (destination, source)
    char array2[MAX];
    strcpy(array2, array);
    printf("%s\n", array2);

  	// Example using strlen to find string length
  	// returns the int length NOT including '\0'
    int length = strlen(array);
    printf("%d\n", length);


  	// Example using strcmp to compare two strings character
  	// by character - function will return:
  	// 0 = two strings are equal
  	// other int if not the same
    if (strcmp("hello", array) == 0) {
        printf("The two string are the same.\n");
    } else {
        printf("The two string are difference.\n");
    }


    
    return 0;
}