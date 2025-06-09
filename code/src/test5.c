#include <stdio.h>
#define SIZE 6

/**
 * @brief Reads an array of SIZE integers, swaps the first minimum and last maximum elements, and prints the array.
 *
 * The user enters SIZE integers. The program finds the first minimum and last maximum,
 * swaps them, and prints the modified array with elements separated by spaces.
 *
 * @return 0 on successful completion
 */
int main() {
    int digits[SIZE];
    int min, max, imin = 0, imax = 0;

    // Read array and find the first minimum and last maximum
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &digits[i]);
        if (i == 0 || digits[i] < min) {
            min = digits[i];
            imin = i;
        }
        if (i == 0 || digits[i] >= max) {
            max = digits[i];
            imax = i;
        }
    }

    // Swap the first minimum and last maximum
    int temp = digits[imin];
    digits[imin] = digits[imax];
    digits[imax] = temp;

    // Print the modified array
    for (int i = 0; i < SIZE; i++) {
        printf("%d", digits[i]);
        if (i < SIZE - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}