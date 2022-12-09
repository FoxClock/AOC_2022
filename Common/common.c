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