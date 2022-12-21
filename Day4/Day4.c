
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
int *create_numberArray(char *input, size_t input_length);
int parse_number(char *input, size_t length);
int array_encompassed(int *array1, int *array2, size_t array1_length, size_t array2_length);
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
    size_t overlap_count = 0;


    // Get a line
    while (fgets(line, LINE_BUFFER, fptr))
    {
        // Variables
        int flag = 0;
        char *grid1, *grid2;
        size_t array1_size, array2_size;

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
        int *val_array1 = create_numberArray(grid1, n);
        int *val_array2 = create_numberArray(grid2, n);

        array1_size = sizeof(val_array1) * sizeof(val_array1[0]);

        // Diagnostic print of array sizes
        printf("Array1 size: %zu\n", array1_size);
        printf("Array2 size: %zu\n", array2_size);
        
        
        // Check if overlap is found
        flag = array_encompassed(val_array1, val_array2, array1_size, array2_size);

        if (flag > 0)
        {
            printf("overlap: True\n");
        } else {
            printf("overlap: False\n");
        }
        printf("\n");

        // Free memory
        free(val_array1);
        free(val_array2);
        free(grid1);
        free(grid2);
    }

    // Free allocated memory and pointers
    free(line);
    fclose(fptr);
}

int *create_numberArray(char *input, size_t input_length)
{
    // Constants
    const int bottom = 0;
    const int Base = 10;
    

    // variables 
    int *int_array;
    int array_size = 0;
    int low = 0, high = 0;
    char *e;
    int index;


    // Split input into two separate numbers
    e = strchr(input, '-');                     // Find the offset of the '-' character
    index = (int)(e - input);                   // Converting the offset to an int position
    low = parse_number(input, input_length);
    high = parse_number(&input[index + 1], input_length);

    // get the size of the array
    array_size = high - low;
    
    // Allocate the int array and set all values to zero
    size_t size = array_size * sizeof(int);
    int_array = malloc(size);
    int_array = memset(int_array, 0, array_size);

    /* Diagnostics print numbers */
    printf("Num1 = %i\n", low);
    printf("Num2 = %i\n", high);
    printf("Array size: %i\n", array_size);

    // From the first integer to the last
    // add that number to the array
    for (int i = 0; i <= array_size; ++i)
    {
        if (i >= low && i <= high)
        {
            int_array[i] = i;
        }
    }

    return int_array;
}

int parse_number(char *input, size_t length)
{
    // Constants
    const int BASE = 10;

    // Variables
    int output = 0;
    int index = 0;
    char *ptr;
    char *var = malloc(length * sizeof(char));

    index = split_string(input, var, length, '-');

    output = (int) strtol(var, &ptr, 10);

    return output;
}

int array_encompassed(int *array1, int *array2, size_t array1_length, size_t array2_length)
{

    /*
        Problem to solve:
            Each array contains a list of values
            which can either be a part of the 
            other array or not.

            This function needs to find if a set of values
            is encompassed by the other array.
            So if all values of one array, is encompassed
            by the values of the other array, it should 
            return true.
    */

   // Constants


   // Variables
   int i, j;

   // Brute force
   for (i = 0; i < (int)array2_length; i++)
   {
    for (j = 0; j < (int)array1_length; j++)
    {
        if (array2[i] == array1[j])
        {
            break;
        }
    }
    if (j == (int)array1_length)
    {
        return -1;
    }
   }
   

    // Return the flag
   return 1;
}

