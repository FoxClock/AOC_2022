// AUTHOR:	Hayden Foxwell
// DATE:	08-12-2022
// PURPOSE:	Day 1 -
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

// buffer size
#define BUFFSIZE 10 * sizeof(char)
#define ARRSIZE 100


/* Function definitions */
void bubbleSort(int arr[], int n);
void swap(int* xp, int* yp);


/* Main function */

int main() {

    // Variables
    char *number = malloc(BUFFSIZE);
    int total = 0, count = 0;
    int *cal_list;

    // Set memory location to value
    cal_list = (int*) malloc(ARRSIZE * sizeof(int));
    cal_list = (int*) memset(cal_list, 0, ARRSIZE * sizeof(int));

    // Open file
    FILE *file = open_file(INPUT_FILE, "r");
    
    // Read a line from the file
    while (fgets(number, sizeof(number), file) != NULL) {

        if (number) {
            int value = atoi(number);
            if (value)
            {
                printf("Value:\t%i\n", value);
                total = total + value;
                value =  0; 
            } else {
                cal_list[count] = total;
                total = 0; count++;
            }
        }

    }

    // Sort the array first
    bubbleSort(cal_list, sizeof(*cal_list) / sizeof(cal_list[0]));
    
    // Sum first 3 items
    total = 0;
    for (int x = 0; x < 3; ++x)
    {
        printf("%i\t%i\n", x, cal_list[x]);
        total = total + cal_list[x];
    }
    
    // Print total
    printf("total: %i\n", total);

    // Free memory
    free(number);
    fclose(file);
    return 1;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j > n - i - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}