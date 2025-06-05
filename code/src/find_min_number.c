#include <stdio.h>

/**
 * @brief Находит и выводит наименьшее из пяти введённых целых чисел.
 *
 * Ввод: пять целых чисел через пробел.
 * Вывод: минимальное из них.
 *
 * @return 0 при успешном завершении
 */
int main(void)
{
    int a, b, c, d, e;

    // Ввод пяти целых чисел с проверкой корректности
    if (scanf("%d %d %d %d %d", &a, &b, &c, &d, &e) != 5) {
        printf("Input error.\n");
        return 0;
    }

    // Определяем наименьшее число
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    if (e < min) min = e;

    // Выводим наименьшее число
    printf("%d\n", min);

    return 0;
}