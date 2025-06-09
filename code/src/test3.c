#include <stdio.h>

/**
 * @brief Finds the number with the maximum sum of digits in a sequence.
 *
 * The user enters a sequence of natural numbers ending with 0.
 * The program outputs the number with the largest sum of digits and the sum itself.
 * If there are several such numbers, the first one is chosen.
 *
 * @return 0 on successful completion
 */
int main() {
    int num, max_num = 0, max_sum = -1;

    while (scanf("%d", &num) == 1 && num != 0) {
        int temp = num, sum = 0;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum > max_sum) {
            max_sum = sum;
            max_num = num;
        }
    }
    printf("%d %d\n", max_num, max_sum);
    return 0;
}