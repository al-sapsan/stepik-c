#include <stdio.h>

/**
 * @brief Prints an inverted triangle of asterisks with the given width.
 *
 * The user enters the width n. The program prints rows of asterisks,
 * each row centered, with the number of asterisks decreasing by 2 each time.
 * No spaces are printed after the last asterisk in each row.
 *
 * @return 0 on successful completion
 */
int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 0; n - 2 * i > 0; i++) {
        // Print leading spaces
        for (int s = 0; s < i; s++) {
            printf(" ");
        }
        // Print stars
        for (int j = 0; j < n - 2 * i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}