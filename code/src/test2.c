#include <stdio.h>
#include <stdlib.h>

#define N 5

/**
 * @brief Fills a 5x5 matrix with random numbers from 0 to 10, prints it, and prints the sum of the minimum elements of each column.
 *
 * The user enters the seed for the random number generator.
 * The program prints the matrix (elements separated by tabs),
 * then prints the sum of the minimum elements of all columns.
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
            matrix[i][j] = rand() % 11; // 0 to 10 inclusive
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Find the sum of the minimum elements of each column
    int sum = 0;
    for (int j = 0; j < N; j++) {
        int min = matrix[0][j];
        for (int i = 1; i < N; i++) {
            if (matrix[i][j] < min)
                min = matrix[i][j];
        }
        sum += min;
    }
    printf("%d\n", sum);

    return 0;
}