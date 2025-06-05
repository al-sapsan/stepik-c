#include <stdio.h>

/**
 * @brief Находит произведение всех целых нечетных чисел в заданном диапазоне.
 *
 * @return 0 при успешном завершении
 */
int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Input error.\n");
        return 0;
    }

    // Если оба числа одинаковые и четные — ответ 0
    if (a == b && a % 2 == 0) {
        printf("0\n");
        return 0;
    }

    // Если оба числа одинаковые и нечетные — ответ это число
    if (a == b && a % 2 != 0) {
        printf("%d\n", a);
        return 0;
    }

    // Определяем границы диапазона
    int from = (a < b) ? a : b;
    int to = (a > b) ? a : b;

    double prod = 1;
    int i = from;
    while (i <= to) {
        if (i % 2 != 0) {
            prod *= i;
        }
        i++;
    }

    printf("%g\n", prod);
    return 0;
}