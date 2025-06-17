/**
 * @file array_swap_extremes.c
 * @brief Program to swap first minimal and last negative elements in an array
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 8               ///< Size of the array
#define MAX_VALUE 7          ///< Maximum random value (inclusive)
#define MIN_VALUE -5         ///< Minimum random value (inclusive)
#define RANGE (MAX_VALUE - MIN_VALUE + 1)  ///< Range of random values

/**
 * @brief Main function to process array
 * 
 * The program:
 * 1. Takes a seed value from user for random number generation
 * 2. Fills array with random values (-5 to 7)
 * 3. Prints original array
 * 4. Finds first minimal and last negative elements
 * 5. Performs swap according to rules:
 *    - Swaps first minimal with last negative if negatives exist
 *    - Otherwise swaps first minimal with element at index 2
 * 6. Prints modified array
 * 
 * @return 0 on successful execution
 */
int main() {
    int array[SIZE];            ///< Array to store and process values
    int *ptr = array;          ///< Pointer for array traversal
    int *end_ptr = array + SIZE; ///< Pointer to end of array (one past last element)
    int seed;                  ///< Seed for random number generator

    /* Get random seed from user */
    scanf("%d", &seed);
    srand(seed);

    /**
     * @brief Fill array with random numbers in range [-5, 7]
     */
    for (ptr = array; ptr < end_ptr; ptr++) {
        *ptr = rand() % RANGE + MIN_VALUE;
    }

    /**
     * @brief Print original array
     */
    ptr = array;
    while (ptr < end_ptr) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");

    /* Find first minimal element */
    int *min_ptr = array;  ///< Pointer to first minimal element
    ptr = array + 1;
    while (ptr < end_ptr) {
        if (*ptr < *min_ptr) {
            min_ptr = ptr;
        }
        ptr++;
    }

    /* Find last negative element */
    int *last_neg_ptr = NULL;  ///< Pointer to last negative element (NULL if none)
    ptr = array;
    while (ptr < end_ptr) {
        if (*ptr < 0) {
            last_neg_ptr = ptr;
        }
        ptr++;
    }

    /**
     * @brief Perform element swap
     * 
     */
    if (last_neg_ptr != NULL) {
        // Case 1: Swap with last negative
        int temp = *min_ptr;
        *min_ptr = *last_neg_ptr;
        *last_neg_ptr = temp;
    } else {
        // Case 2: Swap with index 2
        int temp = *min_ptr;
        *min_ptr = array[2];
        array[2] = temp;
    }

    /**
     * @brief Print modified array
     */
    ptr = array;
    while (ptr < end_ptr) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");

    return 0;
}