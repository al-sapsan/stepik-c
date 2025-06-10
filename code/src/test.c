#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

/**
 * @brief Initializes a 2D array with random values, sets the second row to zero, and prints the array.
 *
 * The program fills a 3x4 array with random integers from 10 to 30, prints it,
 * then sets the second row to zero and prints the modified array.
 *
 * @return 0 on successful completion
 */
int main() {

    int array2D[ROWS][COLS];
    int key;

    // Read the key for random number generation
    if(scanf("%d", &key) != 1) {
        printf("Input error.\n");
        return 1; // Exit if input is invalid
    }
    srand(key); // Seed the random number generator with the provided key

    // Initialize the 2D array with random values and print it
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array2D[i][j] = rand() % 21 + 10; // Random values between 10 and 30
            printf("%d\t", array2D[i][j]);
        }
        printf("\n");
    }

    // Initialise second row with 0
    for (int j = 0; j < COLS; j++) {
        array2D[1][j] = 0;
    }

    // Print the 2D array after modification
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", array2D[i][j]);
        }
        printf("\n");
    }
    return 0;
}