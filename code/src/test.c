/**
 * @file test.c
 * @brief Вычисление суммы степеней i^j для i=1..4, j=1..2
 *
 * Внутренний цикл считает сумму i^j для j=1..2 при каждом i=1..4.
 * Фактически, суммируются все i^1 и i^2 для i от 1 до 4.
 */

#include <stdio.h>
#include <math.h>

/**
 * @brief Основная функция
 * @return 0 при успешном выполнении
 */
int main() {
    int sum = 0;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 2; ++j) {
            sum += pow(i, j);
        }
    }
    printf("%d\n", sum);
    return 0;
}