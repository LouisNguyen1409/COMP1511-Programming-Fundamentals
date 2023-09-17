// Program to determine if a given C file has valid brackets in it.
// Written by YOUR-NAME (YOUR-ZID) on DD-MM-YYYY

#include <stdio.h>
#include <stdlib.h>

#define RETURN_INVALID_ARGUMENTS 1
#define RETURN_FILE_NOT_FOUND 2
#define RETURN_NOT_ENOUGH_MEMORY 3

void valid_c_brackets(char *file_contents);

////////////////////////////////////////////////////////////////////////////////
/////// DO NOT CHANGE THIS MAIN FUNCTION. YOU DO NOT NEED TO UNDERSTAND ////////
///////                         WHAT IT DOES                            ////////
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
    // Must provide a single argument specifying file
    if (argc != 2) {
        fprintf(stderr, "Usage: ./valid_c_brackets <file.c>\n");
        return RETURN_INVALID_ARGUMENTS;
    }

    // Open the file for reading
    FILE *file = fopen(argv[1], "rb");

    // File must exist to run the program
    if (file == NULL) {
        fprintf(stderr, "File %s not found\n", argv[1]);
        return RETURN_FILE_NOT_FOUND;
    }

    // Gets the length of the file
    fseek(file, 0, SEEK_END);
    long int file_length = ftell(file);

    // Allocate a string large enough to hold the file
    char *file_contents = malloc(sizeof(char) * (file_length + 1));

    if (file_contents == NULL) {
        fprintf(stderr, "There was not enough memory to store the file.");
        return RETURN_NOT_ENOUGH_MEMORY;
    }

    // Rewind back to the start of the file
    fseek(file, 0, SEEK_SET);

    // Read file into `file_contents` array
    fread(file_contents, 1, file_length, file);

    file_contents[file_length] = '\0';
    
    valid_c_brackets(file_contents); 
    
    fclose(file);
}

// Given a string containing the contents of a C file, print out whether it has
// correct matching brackets. If it does not, print out which line that didn't
// have a correct matching bracket.
void valid_c_brackets(char *file_contents) {
    // TODO: COMPLETE THIS FUNCTION AND REMOVE THE PRINTF BELOW
    printf("valid_c_brackets() has not been implemented yet.\n");
}
