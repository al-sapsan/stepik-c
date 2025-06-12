#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 6

int main () {
    int array2D[ROWS][COLS];
    int user_input;

    // Read seed and initialize random generator
    scanf("%d", &user_input);
    srand(user_input);

    // Fill and print the original array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array2D[i][j] = rand() % 7 - 3; // -3 to 3 inclusive
            printf("%d\t", array2D[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Count zeros in each column and print in one line
    for (int j = 0; j < COLS; j++) {
        int zero_count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (array2D[i][j] == 0) {
                zero_count++;
            }
        }
        printf("%d\t", zero_count);
    }
    printf("\n");

    return 0;
}