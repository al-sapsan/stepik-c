/**
 * @file merge_arrays.cpp
 * @brief Merges two sorted arrays into one sorted array using pointer arithmetic
 */

#include <iostream>

#define SIZE_A 10      ///< Size of the first array
#define SIZE_B 5       ///< Size of the second array
#define SIZE_C (SIZE_A + SIZE_B)  ///< Size of the resulting merged array

/**
 * @brief Main function that merges two sorted arrays
 * 
 * The program:
 * 1. Initializes two sorted arrays (array_a and array_b)
 * 2. Merges them into array_c while maintaining sorted order
 * 3. Prints the resulting merged array
 * 
 * @return 0 on successful execution
 */
int main() {
    // Initialize sorted arrays
    int array_a[SIZE_A] = { -8, -4, 3, 4, 7, 15, 21, 25, 31, 42 };  ///< First sorted array
    int array_b[SIZE_B] = { -5, 0, 1, 9, 10 };                        ///< Second sorted array
    int array_c[SIZE_C];                                               ///< Result array for merged elements

    // Initialize pointers to array beginnings
    int *ptrA = array_a;  ///< Pointer to current position in array_a
    int *ptrB = array_b;  ///< Pointer to current position in array_b
    int *ptrC = array_c;  ///< Pointer to current position in array_c

    /**
     * @brief Merge while both arrays have elements
     * 
     * Compares elements from both arrays and copies the smaller one to array_c
     */
    while (ptrA < array_a + SIZE_A && ptrB < array_b + SIZE_B) {
        if (*ptrA < *ptrB) {
            *ptrC = *ptrA;  // Copy from array_a
            ptrA++;
        }
        else {
            *ptrC = *ptrB;  // Copy from array_b
            ptrB++;
        }
        ptrC++;  // Move to next position in array_c
    }

    /**
     * @brief Copy remaining elements from array_a
     * 
     * If array_a has remaining elements after array_b is exhausted
     */
    while (ptrA < array_a + SIZE_A) {
        *ptrC = *ptrA; 
        ptrA++;
        ptrC++;
    }

    /**
     * @brief Copy remaining elements from array_b
     * 
     * If array_b has remaining elements after array_a is exhausted
     */
    while (ptrB < array_b + SIZE_B) {
        *ptrC = *ptrB;
        ptrB++;
        ptrC++;
    }

    // Print the merged array
    int *ptr = array_c;  ///< Pointer for printing the result
    printf("Merged array:\n");
    for (int i = 0; i < SIZE_C; i++, ptr++) {
        printf("%d\t", *ptr);
    }
    printf("\n");

    return 0;
}