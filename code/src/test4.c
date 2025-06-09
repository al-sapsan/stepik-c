#include <stdio.h>

/**
 * @brief Finds and prints all perfect numbers from 1 to 10000.
 *
 * A perfect number is equal to the sum of its proper divisors (excluding itself).
 * Numbers are separated by spaces.
 *
 * @return 0 on successful completion
 */
int main(void) {
    for (int n = 1; n <= 10000; n++) {
        int sum = 0;
        for (int d = 1; d < n; d++) {
            if (n % d == 0)
                sum += d;
        }
        if (sum == n)
            printf("%d ", n);
    }
    return 0;
}