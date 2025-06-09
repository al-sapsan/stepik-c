#include <stdio.h>

/**
 * @brief Prints an 8x8 chessboard with given cell size.
 *
 * White cells are printed as '-', black cells as '*'.
 *
 * @return 0 on successful completion
 */
int main(void) {
    int size;
    scanf("%d", &size);

    for (int row = 0; row < 8 * size; row++) {
        for (int col = 0; col < 8 * size; col++) {
            // Determine the color of the cell
            if (((row / size) + (col / size)) % 2 == 0)
                printf("-");
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}