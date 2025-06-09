#include <stdio.h>

/**
 * @brief Counts how many elements in the sequence are equal to its maximum.
 *
 * The user enters non-negative integers, ending the sequence with 0.
 * If the first entered number is 0, the answer is 0.
 *
 * @return 0 on successful completion
 */
int main() {
    int num, max = 0, count = 0;

    for (;;) {
        scanf("%d", &num);
        if (num == 0)
            break;
        if (num > max) {
            max = num;
            count = 1;
        } else if (num == max) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}