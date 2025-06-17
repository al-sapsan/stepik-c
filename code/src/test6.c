#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 5
#define MIN -10
#define MAX 10
#define RANGE (MAX - MIN + 1)

int main() {
    int array2D[ROWS][COLS];
    int *row_ptrs[ROWS];
    int seed;

    // Get seed for random number generator
    scanf("%d", &seed);
    srand(seed);

    // Fill array2D with random numbers and initialize row pointers
    for (int i = 0; i < ROWS; i++) {
        row_ptrs[i] = array2D[i];
        for (int j = 0; j < COLS; j++) {
            array2D[i][j] = rand() % RANGE + MIN;
        }
    }

    // Print original array2D
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", row_ptrs[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Sort row pointers by first element of each row
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = i + 1; j < ROWS; j++) {
            if (row_ptrs[i][0] > row_ptrs[j][0]) {
                int *temp = row_ptrs[i];
                row_ptrs[i] = row_ptrs[j];
                row_ptrs[j] = temp;
            }
        }
    }

    // Print array2D rows using sorted pointers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", row_ptrs[i][j]);
        }
        printf("\n");
    }

    return 0;
}
