#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 5
#define MIN -10
#define MAX 10
#define RANGE (MAX - MIN + 1)

int main() {
    int array2D[ROWS][COLS];
    int seed;

    // Get the seed from user
    scanf("%d", &seed);
    srand(seed);

    // Fill the array2D with random values using pointer
    int *p = &array2D[0][0];
    for (int i = 0; i < ROWS * COLS; i++, p++) {
        *p = rand() % RANGE + MIN;
    }

    // Print original array2D
    p = &array2D[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++, p++) {
            printf("%d\t", *p);
        }
        printf("\n");
    }

    printf("\n");

    // Replace even rows (0-based: 0, 2 — user sees them as 1st and 3rd) with zeros
    for (int i = 0; i < ROWS; i += 2) {
        int *row_ptr = &array2D[i][0];
        for (int j = 0; j < COLS; j++, row_ptr++) {
            *row_ptr = 0;
        }
    }

    // Print modified array2D
    p = &array2D[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++, p++) {
            printf("%d\t", *p);
        }
        printf("\n");
    }

    return 0;
}
