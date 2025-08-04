/**********************************************************************
 * @file script8.cpp
 * @brief Вычисление периметров треугольника и прямоугольника (namespaces)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-04
 **********************************************************************/

#include "emb_style_cpp_en.h"
#include <iostream>

/*** Typedefs ***/
typedef short i16_t;

/*** Function Prototypes ***/
namespace triangle
{
    /**
     * @brief Вычисляет периметр треугольника
     * @param[in] a_i16 Сторона a
     * @param[in] b_i16 Сторона b
     * @param[in] c_i16 Сторона c
     * @return Периметр треугольника (i16_t)
     */
    i16_t perimetr(i16_t a_i16, i16_t b_i16, i16_t c_i16);
}

namespace rectangle
{
    /**
     * @brief Вычисляет периметр прямоугольника
     * @param[in] width_i16 Ширина
     * @param[in] height_i16 Высота
     * @return Периметр прямоугольника (i16_t)
     */
    i16_t perimetr(i16_t width_i16, i16_t height_i16);
}

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    i16_t a0_i16 = 0;
    i16_t a1_i16 = 0;
    i16_t a2_i16 = 0;
    std::cin >> a0_i16 >> a1_i16 >> a2_i16;
    i16_t tri_perim_i16 = triangle::perimetr(a0_i16, a1_i16, a2_i16);
    i16_t rect_perim_i16 = rectangle::perimetr(a0_i16, a1_i16);
    std::cout << tri_perim_i16 << " " << rect_perim_i16 << std::endl;
    return 0;
}

/*** Function Implementation ***/
i16_t triangle::perimetr(i16_t a_i16, i16_t b_i16, i16_t c_i16)
{
    return a_i16 + b_i16 + c_i16;
}
i16_t rectangle::perimetr(i16_t width_i16, i16_t height_i16)
{
    return 2 * (width_i16 + height_i16);
}
