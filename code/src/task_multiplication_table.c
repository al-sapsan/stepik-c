#include <stdio.h>

/**
 * @brief Prints the multiplication table from 1 to k (k < 10).
 *
 * The user enters k. The program prints a k x k multiplication table.
 *
 * @return 0 on successful completion
 */
int main(void) {
    int k;
    if (scanf("%d", &k) != 1 || k < 1 || k >= 10) {
        printf("Input error\n");
        return 0;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            printf("%d ", i * j);
        }
        printf("\n");
    }
    return 0;
}