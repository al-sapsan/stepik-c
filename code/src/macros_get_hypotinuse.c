#include <stdio.h>
#include <math.h> // Для использования функции sqrt()

// Макро-функция для вычисления длины гипотенузы
#define GIPOT(X, Y) (sqrt((X) * (X) + (Y) * (Y)))

int main(void)
{
    int a, b;

    // Считываем значения a и b
    if (scanf("%d, %d", &a, &b) != 2) {
        printf("Input error\n");
        return 0;
    }

    // Вызываем макрос GIPOT для вычисления длины гипотенузы
    double length = GIPOT(a + 3, b - 2);

    // Выводим результат с точностью до сотых
    printf("%.2f\n", length);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}