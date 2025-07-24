/*******************************************************************************
 * @file    script4.c
 * @brief   Вывод неотрицательных чисел из потока ввода
 * @version 1.0
 * @date    2025-07-21
 ******************************************************************************/

/*** Includes ***/
#include <stdio.h>

/*** Function Prototypes ***/

/**
 * @brief Проверяет, является ли число неотрицательным
 * @param[in] value Проверяемое целое число
 * @return 1 если число неотрицательное, иначе 0
 */
int is_positive(int value);

/*** Main Function ***/

/**
 * @brief Точка входа в программу
 * @return Код завершения
 */
int main(void)
{
    int x;
    int first = 1;
    while (scanf("%d", &x) == 1)
    {
        if (is_positive(x))
        {
            if (!first)
                printf(" ");
            printf("%d", x);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}

/*** Function Definitions ***/

/**
 * @brief Проверяет, является ли число неотрицательным
 * @param[in] value Проверяемое целое число
 * @return 1 если число неотрицательное, иначе 0
 */
int is_positive(int value)
{
    return value >= 0 ? 1 : 0;
}