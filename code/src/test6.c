#include <stdio.h>
#define SIZE 7

/**
 * @brief Reads an array of SIZE integers, replaces the first minimum element with zero, and prints the array.
 *
 * @return 0 on successful completion
 */
int main() {
    int digits[SIZE];
    int min, imin = 0;

    // Read array and find the first minimum
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &digits[i]);
        if (i == 0 || digits[i] < min) {
            min = digits[i];
            imin = i;
        }
    }

    // Replace the first minimum with zero
    digits[imin] = 0;

    // Print the modified array
    for (int i = 0; i < SIZE; i++) {
        printf("%d", digits[i]);
        if (i < SIZE - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}