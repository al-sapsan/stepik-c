#include <stdio.h>

/**
 * @brief Prints a frame of stars with given width and height.
 * 
 * @param l Width of the frame
 * @param h Height of the frame
 */
void frame(int l, int h) {
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < l; col++) {
            if (row == 0 || row == h - 1 || col == 0 || col == l - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n"); // переход на новую строку после каждой строки рамки
    }
}

int main() {
    int l, h;
    scanf("%d %d", &l, &h);
    if (l <= 0 || h <= 0) return 1;
    frame(l, h);
    return 0;
}