/**
 * @file array_processing.c
 * @brief Program to process array by replacing negatives with zeros
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10       ///< Size of the array
#define MAX_VALUE 5   ///< Maximum random value
#define MIN_VALUE -5  ///< Minimum random value
#define RANGE (MAX_VALUE - MIN_VALUE + 1)  ///< Range of random values

/**
 * @brief Main function to process array
 * 
 * The program:
 * 1. Takes a seed value from user for random number generation
 * 2. Fills array with random values (-5 to 5)
 * 3. Prints original array
 * 4. Replaces all negative elements with zeros
 * 5. Prints modified array
 * 
 * @return 0 on successful execution
 */
int main() {
    int array[SIZE];            ///< Array to store values
    int *ptr = array;          ///< Pointer to array start
    int *end_ptr = array + SIZE; ///< Pointer to end of array
    int seed;                  ///< Seed for random number generator

    // Get random seed from user
    scanf("%d", &seed);
    srand(seed);

    /* Fill array with random numbers (-5 to 5) */
    for (ptr = array; ptr < end_ptr; ptr++) {
        *ptr = rand() % RANGE + MIN_VALUE;
    }

    /* Print original array */
    ptr = array;
    while (ptr < end_ptr) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");

    /* Replace negative elements with zeros */
    ptr = array;
    while (ptr < end_ptr) {
        if (*ptr < 0) {
            *ptr = 0;
        }
        ptr++;
    }

    /* Print modified array */
    ptr = array;
    while (ptr < end_ptr) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");

    return 0;
}