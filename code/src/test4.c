/**
 * @file max_consecutive_zeros.c
 * @brief Program to find maximum consecutive zeros in an array
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20               ///< Size of the array
#define MAX_VALUE 1           ///< Maximum random value (inclusive)
#define MIN_VALUE -1          ///< Minimum random value (inclusive)
#define RANGE (MAX_VALUE - MIN_VALUE + 1)  ///< Range of random values

int main() {
    int array[SIZE];            ///< Array to store and process values
    int *ptr = array;           ///< Pointer for array traversal
    int *end_ptr = array + SIZE; ///< Pointer to end of array (one past last element)
    int seed;                   ///< Seed for random number generator

    /* Get random seed from user */
    scanf("%d", &seed);
    srand(seed);

    /**
     * @brief Fill array with random numbers in range [-1, 1]
     * 
     * Uses pointer arithmetic to traverse and fill the array
     */
    for (ptr = array; ptr < end_ptr; ptr++) {
        *ptr = rand() % RANGE + MIN_VALUE;
    }

    /**
     * @brief Print original array
     * 
     * Elements are space-separated with space after last element
     */
    ptr = array;
    while (ptr < end_ptr) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");

    /* Find maximum consecutive zeros */
    int max_zeros = 0;         ///< Maximum consecutive zeros found
    int current_zeros = 0;     ///< Current streak of consecutive zeros
    ptr = array;
    
    while (ptr < end_ptr) {
        if (*ptr == 0) {
            current_zeros++;
            if (current_zeros > max_zeros) {
                max_zeros = current_zeros;
            }
        } else {
            current_zeros = 0;
        }
        ptr++;
    }

    /* Print maximum consecutive zeros */
    printf("%d\n", max_zeros);

    return 0;
}