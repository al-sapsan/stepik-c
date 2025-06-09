#include <stdio.h>
#include <math.h>
/**
 * @brief Sums the numbers in the sequence whose positions are prime numbers.
 *
 * The user enters a sequence of integers ending with 0.
 * The program sums only those numbers whose positions (starting from 1) are prime.
 *
 * @return 0 on successful completion
 */
int main() {
    int num, pos = 1, sum = 0;

    while (scanf("%d", &num) == 1 && num != 0) {
        // Check if pos is a prime number
        int is_prime = 1;
        if (pos == 1) is_prime = 0;
        if (pos == 2) is_prime = 1;
        if (pos % 2 == 0 && pos > 2) is_prime = 0;
        // Check for factors from 3 to sqrt(pos)
        for (int i = 3; i <= sqrt(pos); i+= 2) {
            if (pos % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime)
            sum += num;
        pos++;
    }
    printf("%d\n", sum);
    return 0;
}