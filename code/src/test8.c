#include <stdio.h>
#include <stdlib.h>

#define N 5

int main() {
    int matrix[N][N];
    int seed;
    scanf("%d", &seed);
    srand(seed);

    // Fill and print the matrixay
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 21; // 0 to 20 inclusive
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Find the max element (prefer the one closer to the end)
    int max = matrix[0][0];
    int max_i = 0, max_j = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] >= max) {
                max = matrix[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    // Calculate the average of the row with the max element
    int sum = 0;
    for (int j = 0; j < N; j++) {
        sum += matrix[max_i][j];
    }
    double avg = sum / (double)N;

    printf("%d %.1f\n", max, avg);

    return 0;
}