// AUTHOR:	Hayden Foxwell
// DATE:	08-12-2022
// PURPOSE:	Day 1 -

// Imports
#include <stdio.h>
#include <stdlib.h>

#include "../Common/common.h"


// Defines
#if (1)
    #define INPUT_FILE "testInput.txt"
#else
    #define INPUT_FILE "input.txt"
#endif



/* Main function */

int main() {

    // Variables
    char *string;
    
    // Open file
    FILE *file = open_file(INPUT_FILE, "r");

    // Allocate buffer memory
    fseek(file, 0L, SEEK_END);
    int sz = ftell(file);
    rewind(file);

    string = malloc(sz * sizeof(char));

    // Read into file
    fread(string, sz, 1, file);

    printf("%s", string);
    
    fclose(file);
    return 1;
}