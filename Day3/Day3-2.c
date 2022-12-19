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
#if (1)
    #define INPUT_FILE "testInput.txt"
#else
    #define INPUT_FILE "input.txt"
#endif

// Buffers
#define LINE_BUFFER 50


/* Function Definitions */
void clean_input(const char *input, char *output, size_t length);
char find_duplicate(char *input_array, size_t leng);
int get_index(char *array, size_t length);
int letter_to_score(char letter);
void reallocate_score_array(int *score_array, int count);
void sum_score_array(int *score_array, size_t array_length);
/*=====================*/

/* Main function*/
int main()
{
    // Variables
    FILE *fptr = open_file(INPUT_FILE, "r");
    char *line = malloc(LINE_BUFFER * sizeof(char));
    int *score_array = malloc(1 * sizeof(int));
    char letter = 0;

    int count = 0, line_count = 0;
    while (fgets(line, LINE_BUFFER, fptr))
    {
        // Create cumulative array
        size_t cumulative_size = 1;
        char *cumulative_array = malloc(cumulative_size * sizeof(char));

        // Get size of line
        size_t line_size = strlen(line);

        // on every third line, process the cumulative array
        if (count % 3 == 0 && count != 0)
        {
            printf("Cumulative array conts: %s\n", cumulative_array);

            count = 0;

            // Testing
            free(cumulative_array);
        }
        // Otherwise, append to cumulative array
        else 
        {
            printf("Count: %i\n", count);
            // realloc the cumulative array
            // sum the size of the cumulative array and 
            // the line_size, then realloc that size
            cumulative_size += line_size;
            cumulative_array = realloc(cumulative_array, cumulative_size * sizeof(cumulative_array[0]));

            // Concatenate the string to the end of the array
            strlcat(cumulative_array, line, line_size);
        }

        // update the counter
        count ++;
        line_count ++;
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

    // Reallocate the score array
    reallocate_score_array(score_array, count);

    // Assign value to score array
    score_array[count] = score;

    // Sum the scores in the score array
    sum_score_array(score_array, count);

    // Free memory
    free(line);
    free(score_array);
    fclose(fptr);

    return 0;
}

/* Support functions */
/* ================= */

/*
    Resizes the score array for each score.
*/
void reallocate_score_array(int *score_array, int count)
{
    // Assign value to array of scores
    size_t array_size = (sizeof(*score_array)) + (count * sizeof(int));
    score_array = realloc(score_array, array_size);

    if (!score_array)
    {
        printf("Issue with realloc\n");
        exit(1);
    }

}

/*
    Sums the contents of the score array.
*/
void sum_score_array(int *score_array, size_t array_length)
{
    // Variables
    int sum = 0;
    
    // For each item in the score array, sum the value
    for (int x = 0; x < (int)array_length; ++x)
    {
        // Total the scores
        sum += score_array[x];
    }

    // Print to stdout the totaled score
    printf("Final Score: %i\n", sum);
    printf("\n");
    
    return;
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
    index = get_index(input_array, leng);

    // Get letter from array
    letter = input_array[index];

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
int get_index(char *array, size_t length)
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
            if (array[i] == array[j])
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

/* Converts a char intput to the puzzle score.*/
/*
    lowercase  => 1 - 26
    Uppercase  => 27 - 52
*/
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