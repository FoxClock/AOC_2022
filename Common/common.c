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
// Opens a file of given file name/path
FILE* getfile(char *fileName)
{
    // open file
    FILE *fptr = fopen(fileName, "r");

    if (!fptr)
    {
        printf("Error reading file!");
        getchar();
        exit(1);
    }

    return fptr;
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


// Print the contents of an array
void printVals(int array[], size_t length)
{
    for (size_t j = 0; j < length; ++j)
    {
        printf("Item %zu:\t%i\n", j, array[j]);
    }
}


// Bubble sort values
// Sorts the integer values in an array
void bubbleSort(int array[], int size) {
  // loop to access each array element
  for (int step = 0; step < size - 1; ++step) {
      
    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {
      
      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] < array[i + 1]) {
        
        // swapping occurs if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}