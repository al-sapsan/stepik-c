/**
 * @file array_2d_operations.c
 * @brief Program to fill, print and count zeros in a 2D array using pointers
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 4       ///< Number of rows in the 2D array
#define COLS 3       ///< Number of columns in the 2D array
#define MAX_VAL 11   ///< Upper bound for random values (0-10 inclusive)

/**
 * @brief Main function to operate on 2D array
 * 
 * The program:
 * 1. Takes a seed value from user for random number generation
 * 2. Fills a 4x3 array with random values (0-10)
 * 3. Prints the array in tabular format
 * 4. Counts and prints the number of zero elements
 * 
 * @return 0 on successful execution
 */
int main() {
    int array2D[ROWS][COLS];       ///< 2D array to store values
    int seed;                      ///< Seed for random number generator
    int *start_ptr = &array2D[0][0]; ///< Pointer to start of array
    int *end_ptr = &array2D[0][0] + (ROWS * COLS); ///< Pointer to end of array

    // Get random seed from user
    scanf("%d", &seed);
    srand(seed);

    /* Fill array with random values 0-10 */
    for (; start_ptr < end_ptr; start_ptr++) {
        *start_ptr = rand() % MAX_VAL;
    }

    /* Print array in tabular format */
    start_ptr = &array2D[0][0]; // Reset pointer to start
    for (int i = 0; start_ptr < end_ptr; start_ptr++, i++) {
        printf("%d\t", *start_ptr);
        // Move to new line after each row
        if ((i + 1) % COLS == 0) {
            printf("\n");
        }
    }

    /* Count zero elements */
    int zero_counter = 0; ///< Counter for zero elements
    start_ptr = &array2D[0][0]; // Reset pointer to start
    for (; start_ptr < end_ptr; start_ptr++) { 
        if (*start_ptr == 0) {
            zero_counter++;
        }
    }
    printf("%d\n", zero_counter);
    
    return 0;
}