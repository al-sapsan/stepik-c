/*******************************************************************************
 * @file script9.c
 * @brief Arithmetic mean of int arguments
 * @version 1.0
 * @date 2025-07-21
 ******************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

/*** Function Prototypes ***/

/**
 * @brief Среднее арифметическое набора целых аргументов
 * @param[in] total Общее количество аргументов
 * @param[in] ... Список аргументов типа int
 * @return Среднее значение типа double
 * @details Использует переменное количество аргументов для расчёта среднего значения
 */
double mean(int total, ...);

/*** Main Function ***/

/**
 * @brief Точка входа в программу
 * @return 0 при успешном завершении
 */
int main(void)
{
    double res_f64 = mean(7, 5, -10, 11, 0, 12, 4, 2);
    printf("%.2f\n", res_f64);
    return 0;
}

/*** Function Implementations ***/

double mean(int total, ...)
{
    double sum_f64 = 0.0;
    va_list args;
    va_start(args, total);

    for (size_t i = 0; i < (size_t)total; ++i)
    {
        sum_f64 += (double)va_arg(args, int);
    }

    va_end(args);
    return sum_f64 / total;
}
