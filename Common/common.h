/* Header file containing all functions in the common library */

// Includes
#pragma once
#include <stdio.h>
#include <stdlib.h>

// Defines

// Function Definitions
FILE* open_file(char* filepath, char* mode);
char  *get_string_contents(FILE *input_file);
