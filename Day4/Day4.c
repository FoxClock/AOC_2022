
// AUTHOR:	Hayden Foxwell
// DATE:	16-12-2022
// PURPOSE:	Day 3 -
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

#define LINE_BUFFER 10

/* Main function */
int main()
{
    // Constants
    char sep = ',';
    char grid_sep = '-';

    // variables
    FILE *fptr = open_file(INPUT_FILE, "r");
    char *line = malloc(LINE_BUFFER * sizeof(char));

    // Get a line
    while (fgets(line,10, fptr))
    {
        char *grid1, *grid2;

        // Malloc lines


        // Parse line along csv

    }

    // Free allocated memory and pointers
    free(line);
    fclose(fptr);
}

