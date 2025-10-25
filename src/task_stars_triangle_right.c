#include <stdio.h>

/**
 * @brief Prints a right-aligned triangle of asterisks of given height.
 *
 * The user enters the height n. The program prints n rows,
 * each row containing an increasing number of asterisks from 1 to n,
 * right-aligned by preceding spaces.
 *
 * @return 0 on successful completion
 */
int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {         // Outer loop for rows
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print asterisks
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");                      // Newline after each row
    }

    return 0;
}