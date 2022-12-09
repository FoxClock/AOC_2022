// AUTHOR:	Hayden Foxwell
// DATE:	08-12-2022
// PURPOSE:	Day 1 -

// Imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char *number = malloc(10 * sizeof(char));
    
    // Open file
    FILE *file = open_file(INPUT_FILE, "r");
    
    // Read a line from the file
    while (fgets(number, sizeof(number), file) != NULL) {
        
        number = number - 2;
        
        printf("%s", number);
    }

    // Free memory
    free(number);
    fclose(file);
    return 1;
}

void printStrings(char *contents) {
    char* number = NULL;
    number = strtok(contents, "\n");

    while (number != NULL)
    {
        printf("%s\t", number);
        number = strtok(NULL, "\n");
        printf(
            "size: %ld\n", sizeof(number)
        );
    }
}