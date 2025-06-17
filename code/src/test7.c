#include <stdio.h>

/**
 * @brief Заменяет значения обеих переменных на большее из них.
 * 
 * @param x Указатель на первую переменную
 * @param y Указатель на вторую переменную
 */
void largerOf(double *x, double *y) {
    double max = (*x > *y) ? *x : *y;
    *x = max;
    *y = max;
}

int main() {
    double x, y;
    scanf("%lf %lf", &x, &y);
    largerOf(&x, &y);
    printf("%.2lf %.2lf\n", x, y);
    return 0;
}