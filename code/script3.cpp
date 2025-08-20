/**********************************************************************
 * @file script3.cpp
 * @brief Minimal value selection (embedded C++ style)
 * @version 1.0
 * @date 2025-08-20
 **********************************************************************/

#include "emb_style_cpp_en.h"
#include <iostream>
#include <iomanip>

/*** Typedefs ***/

//*** Function Prototypes ***/
/**
 * @brief  Возвращает минимальное из двух целых чисел
 * @param  a  Первое число
 * @param  b  Второе число
 * @return Минимальное целое число
 */
int min2(int a, int b);

/**
 * @brief  Возвращает минимальное из двух вещественных чисел
 * @param  a  Первое число
 * @param  b  Второе число
 * @return Минимальное вещественное число
 */
double min2(double a, double b);

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 * @return Код завершения (0 — успешно, 1 — ошибка)
 */
int main(void)
{
    int val_int = 0;
    double val_double = 0.0;
    std::cin >> val_int >> val_double;
    double result = min2(static_cast<double>(val_int), val_double);
    std::cout << std::fixed << std::setprecision(1) << result << std::endl;
    return 0;
}

/*** Function Implementation ***/
int min2(int a, int b)
{
    return (a < b) ? a : b;
}

double min2(double a, double b)
{
    return (a < b) ? a : b;
}
