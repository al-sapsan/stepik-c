#include <stdio.h>
#include <stdlib.h>

#define N 7

/**
 * @brief Fills a 7x7 matrix with random numbers from 0 to 100, prints it, and finds the maximum in the upper triangle between the diagonals.
 *
 * The user enters the seed for the random number generator.
 * The program prints the matrix (elements separated by tabs),
 * then prints the maximum value in the upper triangle between the main and secondary diagonals (inclusive).
 *
 * @return 0 on successful completion
 */
int main() {
    int matrix[N][N];
    int key;

    // Read the key for random number generation
    if (scanf("%d", &key) != 1) {
        printf("Input error.\n");
        return 1;
    }
    srand(key);

    // Fill and print the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 101; // 0 to 100 inclusive
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Find the maximum in the upper triangle between the diagonals (inclusive)
    int max = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N - i; j++) {
            if (matrix[i][j] > max)
                max = matrix[i][j];
        }
    }
    printf("%d\n", max);

    return 0;
}