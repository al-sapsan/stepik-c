#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 4

int main() {
    int array2D[ROWS][COLS];
    int user_input;

    // Read seed and initialize random generator
    scanf("%d", &user_input);
    srand(user_input);

    // Fill and print the original array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array2D[i][j] = rand() % 29 + 2; // 2 to 30 inclusive
            printf("%d\t", array2D[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Swap first and last rows
    for (int j = 0; j < COLS; j++) {
        int temp = array2D[0][j];
        array2D[0][j] = array2D[ROWS - 1][j];
        array2D[ROWS - 1][j] = temp;
    }

    // Print the modified array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", array2D[i][j]);
        }
        printf("\n");
    }

    return 0;
}