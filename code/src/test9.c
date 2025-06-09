#include <stdio.h>

/**
 * @brief Checks if the entered number is prime.
 *
 * The user enters a natural number. If it is prime, the program prints "YES", otherwise "NO".
 * A prime number is a number greater than 1 that is divisible only by 1 and itself.
 *
 * @return 0 on successful completion
 */
int main() {
    int digit, is_prime = 1;
    if (scanf("%d", &digit) != 1 || digit < 1) {
        printf("Invalid input\n");
        return 0;
    }
    if (digit == 1) {
        printf("NO\n");
        return 0;
    }
    /**
     * @brief Checks divisors from 2 up to sqrt(n).
     *
     * The loop continues while the square of the divisor does not exceed the number itself.
     * This is an optimization: if a number has a divisor greater than its square root,
     * it must also have a smaller one.
     */
    for (int i = 2; i * i <= digit; i++) {
        if (digit % i == 0) {
            is_prime = 0;
            break;
        }
    }
    printf("%s\n", is_prime ? "YES" : "NO");
    return 0;
}