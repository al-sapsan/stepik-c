/**********************************************************************
 * @file script6.cpp
 * @brief Rectangle value calculation (embedded C++ style)
 * @version 1.0
 * @date 2025-08-20
 **********************************************************************/

#include "emb_style_cpp_en.h"
#include <iostream>

/*** Typedefs ***/
using calc_type = enum { calc_perimetr,
                         calc_square };

/*** Function Prototypes ***/
/**
 * @brief  Вычисляет периметр или площадь прямоугольника
 * @param  width   Ширина прямоугольника
 * @param  length  Длина прямоугольника
 * @param  type    Тип вычисления (calc_perimetr/calc_square)
 * @return Периметр или площадь
 */
int get_rect_value(int width, int length, calc_type type = calc_perimetr);

/*** Main Function ***/
int main(void)
{
    int width = 0;
    int length = 0;
    std::cin >> width >> length;
    int result = get_rect_value(width, length);
    std::cout << result << std::endl;
    return 0;
}

/*** Function Implementation ***/
int get_rect_value(int width, int length, calc_type type)
{
    if (type == calc_perimetr)
    {
        return 2 * (width + length);
    }
    else
    {
        return width * length;
    }
}
