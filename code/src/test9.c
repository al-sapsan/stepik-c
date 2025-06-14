#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int main () {
    int array2D[ROWS][COLS];
    int user_rand, user_value;

    // Read seed and value to search
    scanf("%d %d", &user_rand, &user_value);
    srand(user_rand);

    // Fill and print the array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array2D[i][j] = rand() % 6; // 0 to 5 inclusive
            printf("%d\t", array2D[i][j]);
        }
        printf("\n");
    }

    // Find and print all indices of elements equal to user_value
    int found = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array2D[i][j] == user_value) {
                printf("(%d,%d) ", i, j);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("NO");
    }
    printf("\n");
    return 0;
}