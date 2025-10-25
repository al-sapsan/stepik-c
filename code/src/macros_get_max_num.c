#include <stdio.h>

// Макро-функция для нахождения максимального из двух чисел
#define GET_MAX(X, Y)    ((X) > (Y) ? (X) : (Y))

int main(void)
{
    double val_1, val_2;

    // Считываем два числа, разделённые точкой с запятой
    if (scanf("%lf; %lf", &val_1, &val_2) != 2) {
        printf("Input error\n");
        return 0;
    }

    // Вызываем макрос GET_MAX для вычисления максимального значения
    double res = GET_MAX(val_1 + 1, val_2 - 1) / (val_1 + val_2);

    // Выводим результат с точностью до сотых
    printf("%.2f\n", res);

    return 0;
}