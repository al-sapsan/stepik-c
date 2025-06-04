#include <stdio.h>
#include <math.h>

/**
 * @brief Вычисляет значение функции y в зависимости от x:
 *        - если x >= 5: квадрат десятичного логарифма от 2*x
 *        - если x < -2: 2*x^2
 *        - иначе: sin(x)
 *
 * @return 0 при успешном завершении
 */
int main() {
    double x, y;
    if (scanf("%lf", &x) != 1) {
        printf("Input error.\n");
        return 0;
    }

    if (x >= 5) {
        y = pow(log10(2 * x), 2);
    } else if (x < -2) {
        y = 2 * x * x;
    } else {
        y = sin(x);
    }

    printf("%.2f\n", y);
    return 0;
}