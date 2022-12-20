
// AUTHOR:	Hayden Foxwell
// DATE:	16-12-2022
// PURPOSE:	Day 3 -
// Imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Common/common.h"


/* ======== Defines ================ */
#if (1)
    #define INPUT_FILE "testInput.txt"
#else
    #define INPUT_FILE "input.txt"
#endif

#define LINE_BUFFER 20
#define GRIDSIZE_BUFFER (LINE_BUFFER/2)

/* -------------------------------- */

/* ======== Functions ============= */
int *create_numberArray(const char *input, size_t input_length);

/* -------------------------------- */

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
    while (fgets(line, LINE_BUFFER, fptr))
    {
        char *grid1, *grid2;

        // Malloc grids
        size_t grid_size = GRIDSIZE_BUFFER * sizeof(char);
        grid1 = malloc(grid_size);
        grid2 = malloc(grid_size);

        // Parse line along csv
        int n = split_string(line, grid1, LINE_BUFFER, ',');
        n = split_string(&line[n + 1], grid2, LINE_BUFFER, ',');
        if (!(n > 0))
        {
            printf("could not parse string\n");
        }

        // Diagnostic - Print grid 1 contents
        printf("Grid 1 contents: %s\n", grid1);
        printf("Grid 2 contents: %s\n", grid2);

        // Get val1 and val 2
        int *val_array1 = create_numberArray(grid1);

        // Free memory
        free(grid1);
        free(grid2);
    }

    // Free allocated memory and pointers
    free(line);
    fclose(fptr);
}

int *create_numberArray(const char *input, size_t input_length)
{
    // Constants
    const int bottom = 0;
    const int top = 1000; 
    

    // variables 
    int *int_array;
    char var1[2], var2[2];
    int low = 0, high = 0;
    int index = 0;
    char *ptr;

    // Allocate the int array and set all values to zero
    size_t size = top * sizeof(int);
    int_array = malloc(size);
    int_array = memset(int_array, 0, top);

    // Split input into two separate numbers
    index = split_string(input, var1, input_length, '-');
    index = split_string(&input[index + 1], var2, input_length, '-');

    // Convert the two strings into numbers
    low = (int) strtol(var1, &ptr, 10);
    high = (int) 


    // From the first integer to the last
    // add that number to the array


}


