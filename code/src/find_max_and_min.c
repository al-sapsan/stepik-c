#include <stdio.h>

/**
 * @brief Вычисляет значение выражения m = max(x, y, z) / min(x, y) + 5.
 *
 * Пользователь вводит три вещественных числа x, y, z.
 * Программа находит максимум среди x, y, z и минимум среди x и y,
 * затем вычисляет m и выводит результат с точностью до двух знаков после запятой.
 *
 * @return 0 при успешном завершении
 */
int main() {
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);

    // Поиск максимума среди x, y, z
    double max = x;
    if (y > max) max = y;
    if (z > max) max = z;

    // Поиск минимума среди x и y
    double min = (x < y) ? x : y;

    double m = max / min + 5;
    printf("%.2f\n", m);

    return 0;
}