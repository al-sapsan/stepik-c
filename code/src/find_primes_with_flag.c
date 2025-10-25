#include <stdio.h>

/**
 * @brief Prints all prime numbers from 2 to n (inclusive).
 *
 * The user enters n (n >= 2). The program prints all primes in the range [2, n].
 *
 * @return 0 on successful completion
 */
int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Input error\n");
        return 0;
    }

    for (int num = 2; num <= n; num++) {
        int is_prime = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime)
            printf("%d ", num);
    }
    return 0;
}