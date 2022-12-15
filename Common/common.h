/* Header file containing all functions in the common library */

// Includes
#pragma once
#include <stdio.h>
#include <stdlib.h>

// Defines

// Structs
/* Could be used to track a file for input */
struct File
{
    /* data */
} File;


// Function Definitions
FILE* open_file(char* filepath, char* mode);
char  *get_string_contents(FILE *input_file);
size_t reallocate_array(int **starting_array, size_t inital_size, size_t amount);
void printVals(int array[], size_t length);
void bubbleSort(int array[], int size);