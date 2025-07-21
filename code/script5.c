/**
 * @file script5.c
 * @brief Сумма двух наибольших из четырёх чисел
 * @version 1.0
 * @date 2025-07-21
 */

#include <stdio.h>
#include <stddef.h>

/*** Function Prototypes ***/

/**
 * @brief Суммирует два наибольших числа
 * @param[in] a Первое число
 * @param[in] b Второе число
 * @param[in] c Третье число
 * @param[in] d Четвёртое число
 * @return Сумма двух наибольших чисел
 * @details Функция сортирует 4 числа и возвращает сумму двух последних
 */
int sum_big2(int a, int b, int c, int d);

/*** Main Function ***/

/**
 * @brief Точка входа
 * @return 0 при успешном завершении
 * @details Считывает 4 числа, выводит сумму двух наибольших
 */
int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    int result = sum_big2(a, b, c, d);

    printf("%d\n", result);

    return 0;
}

/*** Function Implementation ***/

int sum_big2(int a, int b, int c, int d)
{
    int arr[4] = {a, b, c, d};

    for (size_t i = 0; i < 3; ++i)
    {
        for (size_t j = 0; j < 3 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    return arr[2] + arr[3];
}
