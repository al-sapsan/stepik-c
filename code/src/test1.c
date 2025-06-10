#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 6

/**
 * @brief Fills a 3x6 array with random numbers from 0 to 5, prints it, and prints the index of the first zero in each row (or "no").
 *
 * The user enters the seed for the random number generator.
 * The program prints the array (elements separated by tabs, including after the last element in each row),
 * then for each row prints the index of the first zero (or "no" if there is none).
 *
 * @return 0 on successful completion
 */
int main() {
    int array[ROWS][COLS];
    int key;

    // Read the key for random number generation
    if (scanf("%d", &key) != 1) {
        printf("Input error.\n");
        return 1;
    }
    srand(key);

    // Fill and print the array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = rand() % 6; // 0 to 5 inclusive
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    // Print index of first zero in each row or "no"
    for (int i = 0; i < ROWS; i++) {
        int found = 0;
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] == 0) {
                printf("%d\n", j);
                found = 1;
                break;
            }
        }
        if (!found)
            printf("no\n");
    }

    return 0;
}