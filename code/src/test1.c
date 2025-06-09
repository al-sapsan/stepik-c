#include <stdio.h>

/**
 * @brief Finds the minimum value and its position in a sequence of integers.
 *
 * The user enters integers, ending the sequence with -1000.
 * The program outputs the minimum value and its position (starting from 1), separated by a space.
 *
 * @return 0 on successful completion
 */
int main() {
    int num, min, pos = 1, min_pos = 1;
    scanf("%d", &num);
    min = num;

    for(;;) {
        scanf("%d", &num);
        if (num == -1000)
            break;
        pos++;
        if (num < min) {
            min = num;
            min_pos = pos;
        }
    }
    printf("%d %d\n", min, min_pos);
    return 0;
}