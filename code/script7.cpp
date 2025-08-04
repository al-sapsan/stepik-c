/**********************************************************************
 * @file script7.cpp
 * @brief Вычисление площади треугольника по формуле Герона
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-04
 **********************************************************************/

#include "emb_style_cpp_en.h"
#include <iostream>
#include <iomanip>
#include <cmath>

/*** Typedefs ***/
typedef short i16_t;

/*** Function Prototypes ***/
/**
 * @brief Вычисляет площадь треугольника по формуле Герона
 * @param[in] a_i16 Сторона a
 * @param[in] b_i16 Сторона b
 * @param[in] c_i16 Сторона c
 * @return Площадь треугольника (double)
 */
double triangle_sq(i16_t a_i16, i16_t b_i16, i16_t c_i16);

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    i16_t a_i16 = 0;
    i16_t b_i16 = 0;
    i16_t c_i16 = 0;
    std::cin >> a_i16 >> b_i16 >> c_i16;
    double sq_f64 = triangle_sq(a_i16, b_i16, c_i16);
    std::cout << std::fixed << std::setprecision(2) << sq_f64 << std::endl;
    return 0;
}

/*** Function Implementation ***/
double triangle_sq(i16_t a_i16, i16_t b_i16, i16_t c_i16)
{
    double p_f64 = (a_i16 + b_i16 + c_i16) / 2.0;
    double s_f64 = std::sqrt(p_f64 * (p_f64 - a_i16) * (p_f64 - b_i16) * (p_f64 - c_i16));
    return s_f64;
}
