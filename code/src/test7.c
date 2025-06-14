#include <stdio.h>

#define N 4

int main() {
    int matrix[N][N];
    // Input matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Find the first row with no positive elements
    int found = 0;
    for (int i = 0; i < N; i++) {
        int has_positive = 0;
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > 0) {
                has_positive = 1;
                break;
            }
        }
        if (!has_positive) {
            printf("%d\n", i + 1); // User numbering starts from 1
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("NO\n");
    }
    return 0;
}