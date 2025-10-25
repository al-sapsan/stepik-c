#include <stdio.h>

/**
 * @brief Prints a rectangle frame of asterisks with given width and height.
 *
 * If width or height is 1, the frame degenerates into a line of asterisks.
 *
 * @return 0 on successful completion
 */
int main(void) {
    int width, height;
    if (scanf("%d %d", &width, &height) != 2 || width < 1 || height < 1) {
        printf("Input error\n");
        return 0;
    }

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            /**
             * Conditional (if statement):
             * For each position (row, col), the code checks if it is on the border of the rectangle:
             *   row == 0: Is this the first row?
             *   row == height - 1: Is this the last row?
             *   col == 0: Is this the first column?
             *   col == width - 1: Is this the last column?
             * If any of these conditions are true, the position is on the border, so it prints *.
             * Otherwise, it prints a space ( ).
             */
            if (row == 0 || row == height - 1 || col == 0 || col == width - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}