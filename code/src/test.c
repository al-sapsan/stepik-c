#include <stdio.h>

/**
 * @brief Выводит все общие делители двух целых чисел, больших 1.
 *
 * Пользователь вводит два числа. Программа выводит их общие делители через пробел.
 *
 * @return 0 при успешном завершении
 */
int main(void)
{
    int num_1, num_2, min;

    if (scanf("%d %d", &num_1, &num_2) != 2 || num_1 <= 1 || num_2 <= 1) {
        printf("Input error\n");
        return 0;
    }

    min = (num_1 < num_2) ? num_1 : num_2;

    for (int i = 1; i <= min; i++) {
        if (num_1 % i == 0 && num_2 % i == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}