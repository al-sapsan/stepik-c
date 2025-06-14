/**
 * @brief Initializes an array with random values, finds the first negative and last positive elements, 
 * swaps them, and prints the results.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10  ///< Number of elements in the array

/**
 * @brief Entry point of the program.
 *
 * Initializes an array with random integers in the range [-10, 10], finds the first negative
 * and last positive elements, swaps them, and prints the array before and after the swap.
 *
 * @return int Returns 0 on success.
 */
int main () {

    int array[N];
    int *ptr = array; ///< Pointer to iterate through the array
    srand(time(0));

    /**
     * @brief Initialize the array with random values in the range [-10, 10]
     */
    for (int i = 0; i < N; i++, ptr++) {
        *ptr = rand() % 21 - 10;
    }

    ptr = array; ///< Reset pointer to the beginning of the array

    /**
     * @brief Print the array values (index-based loop)
     */
    for (int i = 0; i < N; i++, ptr++) {
        printf("%d\t", *ptr);
    }
    printf("\n");

    /**
     * @brief Find the first negative element in the array
     */
    int *first_negative = NULL; ///< Pointer to the first negative element
    ptr = array;
    for (int i = 0; i < N; i++, ptr++) {
        if (*ptr < 0) {
            first_negative = ptr;
            break;
        }
    }

    if (first_negative == NULL) {
        puts("There are no negative elements");
        return 0;
    }
    printf("First negative element: %d\n", *first_negative);

    /**
     * @brief Find the last positive element in the array
     */
    int *last_positive = NULL; ///< Pointer to the last positive element
    ptr = array + N - 1;
    for (int i = N - 1; i >= 0; i--, ptr--) {
        if (*ptr > 0) {
            last_positive = ptr;
            break;
        }
    }

    if (last_positive == NULL) {
        puts("There are no positive elements");
        return 0;
    }
    printf("Last positive element: %d\n", *last_positive);

    /**
     * @brief Swap the found elements
     */
    int temp = *first_negative;
    *first_negative = *last_positive;
    *last_positive = temp;

    /**
     * @brief Print the modified array
     */
    ptr = array;
    for (int i = 0; i < N; i++, ptr++) {
        printf("%d\t", *ptr);
    }
    printf("\n");

    return 0;
}
