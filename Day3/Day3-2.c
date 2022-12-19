
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
    

// AUTHOR:	Hayden Foxwell
// DATE:	16-12-2022
// PURPOSE:	Day 3 -
// Imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../Common/common.h"


// Defines
#if (0)
    #define INPUT_FILE "testInput.txt"
#else
    #define INPUT_FILE "input.txt"
#endif

// Buffers
#define LINE_BUFFER 50


/* Function Definitions */
void clean_input(const char *input, char *output, size_t length);
char find_duplicate(char *input_array, size_t leng);
int get_index(char *array1, char *array2, size_t length);
int letter_to_score(char letter);
/*=====================*/

/* Main function*/
int main()
{
    // Variables
    FILE *fptr = open_file(INPUT_FILE, "r");
    char *line = malloc(LINE_BUFFER * sizeof(char));
    int *score_array = malloc(1 * sizeof(int));
    char letter = 0;

    int count = 0;
    while (fgets(line, LINE_BUFFER, fptr))
    {
        // Allocate cleaned contents array
        size_t line_len = strlen(line);
        char *contents = malloc(line_len * sizeof(char));

        // copy the line into the contents array
        // minus the /n character a the end of the line
        clean_input(line, contents, line_len);

        /* 
            get 3 lines of input and concatenate into one 
            single array.
            This will then be linearly checked for triplets of 
            letters, which will indicate the badge of the elf.
        */
        
        
        // Find triplet character in array
        letter = find_duplicate(compartment1, compartment2, half_length);

        // Verify letter is not zero
        if (!letter)
        {
            printf("Failure to find character.\n");

            // Free loop mallocs
            free(compartment1);
            free(compartment2);
            free(contents);

            // Skip loop
            continue;

        } else {
            printf("Letter found: '%c'\n", letter);
        }

        // Get score value for letter
        /* 
            Lower case scores: 1 -> 26 
            Uppercase scores: 27 -> 52
        */
        int score = letter_to_score(letter);

        // Diagnostic, Print score
        printf("Score: %i\n", score);
        // =======================

        // Assign value to array of scores
        size_t array_size = (sizeof(*score_array)) + (count * sizeof(int));
        score_array = realloc(score_array, array_size);
        score_array[count] = score;

        if (!score_array)
        {
            printf("Issue with realloc\n");
        }

        // Increment counter
        count++;

        // Free loop mallocs
        free(compartment1);
        free(compartment2);
        free(contents);
    }

    // Sum the array of scores and print
    int sum = 0;
    for (int x = 0; x < count; ++x)
    {
        sum += score_array[x];
    }
    printf("Final Score: %i\n", sum);
    printf("\n");

    // Free memory
    free(line);
    free(score_array);
    fclose(fptr);

    return 0;
}


/*
    Take an input array, and find which character is repeated
    three times in the array.
*/
char find_duplicate(char *input_array, size_t leng)
{
    // variables
    int index = -1;
    char letter = 0;

    // get index of duplicate
    index = get_index(array1, array2, leng);

    // Get letter from array
    letter = array1[index];

    if (!letter)
    {
        printf("Could not locate duplicate!\n");
        return 0;
    }

    return letter;
}

/*
    Return the index of the first letter to have 3 
    identical letters also present in the array
*/
int get_index(char *array1, char *array2, size_t length)
{
    int index;      // Index of character
    uint8_t flag = 0;
    
    // Loop through all letters comparing array 1 to array 2
    for (int i = 0; i < (int)length; ++i)
    {
        // Set index to i in first array
        index = i;
        
        // Check every character against current in the second string
        for (int j = 0; j < (int)length; ++j)
        {
            // If letters are the same, break loops
            if (array1[i] == array2[j])
            {
                flag = 1;
            }
        }

        // If letter found flag is true, break loop
        if (flag)
        {
            break;
        }
    }

    // return index to caller
    return index;
}

void clean_input(const char *input, char *output, size_t length)
{
    strlcpy(output, input, length);
}

int letter_to_score(char letter)
{
    // Constants
    const int lowercase_shift = 96;     // Subtract 96 from ascii 97 to make 1
    const int uppercase_shift = 38;     // Subtract 38 from ascii 64 to make 27
    
    // Variables
    int value = 0;

    // Subtract shift from value to give score
    if (isupper(letter))
    {
        value = (int)letter - uppercase_shift;
    } else {
        value = (int)letter - lowercase_shift;
    }

    // If for whatever reason an error occurs and 
    // value remains 0, show error. 
    if (!value)
    {
        printf("Could not convert to score!\n");
        return -1;
    }

    return value;
}