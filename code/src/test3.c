#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 3

int main() {
    int array2D[ROWS][COLS];
    int key;

    if (scanf("%d", &key) != 1) {
        printf("Error reading key\n");
        return 0;
    }
    srand(key);

    // Fill and print the array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array2D[i][j] = rand() % 11 - 5; // Random numbers between -5 and 5
            printf("%d\t", array2D[i][j]);
        }
        printf("\n");
    }

    // Count rows without any zero element
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        int has_zero = 0;
        for (int j = 0; j < COLS; j++) {
            if (array2D[i][j] == 0) {
                has_zero = 1;
                break;
            }
        }
        if (!has_zero)
            count++;
    }
    printf("%d\n", count);

    return 0;
}