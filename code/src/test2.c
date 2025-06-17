#include <stdio.h>
#include <stdlib.h>

#define SIZE 15       ///< Size of the array
#define MAX_VALUE 10   ///< Maximum random value
#define MIN_VALUE -10  ///< Minimum random value
#define RANGE (MAX_VALUE - MIN_VALUE + 1)  ///< Range of random values

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

    int sum = 0;
    int *first_neg = NULL;
    int *last_max = array;
    int max_val = *array;

    // Find first negative and last maximum element
    for (ptr = array; ptr < end_ptr; ptr++) {
        if (*ptr < 0 && first_neg == NULL) {
            first_neg = ptr;
        }
        if (*ptr >= max_val) {
            max_val = *ptr;
            last_max = ptr;
        }
    }

    if (first_neg == NULL) {
        printf("ERROR\n");
        exit(0);
    }

    // Calculate sum and count between first_neg and last_max (inclusive)
    int count = 0;
    int *start = first_neg;
    int *finish = last_max;
    if (first_neg > last_max) {
        start = last_max;
        finish = first_neg;
    }
    for (ptr = start; ptr <= finish; ptr++) {
        sum += *ptr;
        count++;
    }
    printf("%.2f\n", (double)sum / count);

    return 0;
}