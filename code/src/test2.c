#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 5

/**
 * @brief Fills an array with random numbers from -10 to 10, prints it, swaps the first negative and last positive elements, and prints the result.
 *
 * The user enters the seed for the random number generator.
 * The program prints the array (with a space after each element, including the last),
 * then swaps the first negative and last positive elements and prints the modified array.
 * If there is no negative or no positive element, prints ERROR.
 *
 * @return 0 on successful completion
 */
int main() {
    int irand;
    int array[SIZE];
    int first_neg = -1, last_pos = -1;

    if (scanf("%d", &irand) != 1) {
        printf("Error reading input.\n");
        return 0;
    }

    srand(irand);

    // Fill and print array, find first negative and last positive
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 21 - 10; // from -10 to 10 inclusive
        printf("%d ", array[i]);
        if (array[i] < 0 && first_neg == -1)
            first_neg = i;
        if (array[i] > 0)
            last_pos = i;
    }
    printf("\n");

    if (first_neg == -1 || last_pos == -1) {
        printf("ERROR\n");
        return 0;
    }

    // Swap first negative and last positive
    int temp = array[first_neg];
    array[first_neg] = array[last_pos];
    array[last_pos] = temp;

    // Print modified array
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}