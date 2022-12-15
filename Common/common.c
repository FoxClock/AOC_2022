/*
    Author:     Hayden Foxwell
    Date:       08/12/22
    Purpose:
        Contains common functions for the Advent of code challenges.
*/

// Includes
#include "common.h"

// Defines

/* Functions */

///
/// Opens a file and returns a file pointer
FILE* open_file(char* filepath, char* mode) {
    FILE *file;

    // Check that filepath is not empty
    if (!filepath) {
        printf("Error, No input file Specified.\n");
    }

    // Open file from filepath
    file = fopen(filepath, mode);

    if (!file) {
        printf("Error, could not open File: %s \n", filepath);
        exit(1);
    }

    return file;
}

char  *get_string_contents(FILE *input_file) {
    // Find size of file
    fseek(input_file, 0L, SEEK_END);
    int sz = ftell(input_file);
    rewind(input_file);

    // allocate string buffer of size
    char *file_contents = malloc(sz * sizeof(char));

    // Read file into array
    fread(file_contents, sz, 1, input_file);

    return file_contents;
}

/* Reallocate an array to a particular size */

/*
    Reallocates the size of an array
    inputs:
        int **starting_array: double pointer to the starting array, allows for in-place change 
        so original passed address is reassigned

        size_t inital_size: Inital size of the array

        size_t amount: the amount to resize by, this needs to be specified in terms of the data 
            to resize with, ie; size_of(int)

    returns:
    size_t new size of array
*/
size_t reallocate_array(int **starting_array, size_t inital_size, size_t amount) {
    
    // Calculate size to make array
    size_t new_size = inital_size + amount;

    // Reallocate the array to the new size
    *starting_array = (int*) realloc(*starting_array, new_size);

    printf("new size = %zu\n", sizeof(starting_array));
    return new_size;
}
