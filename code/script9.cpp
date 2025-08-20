/**********************************************************************
 * @file script9.cpp
 * @brief Rectangle perimeter/area calculation (overloads, embedded C++ style)
 * @version 1.0
 * @date 2025-08-20
 **********************************************************************/

/*** Typedefs ***/
using calc_type = enum { calc_perimetr,
                         calc_square };

/*** Function Prototypes ***/
/**
 * @brief  Вычисляет периметр или площадь прямоугольника (int)
 * @param  width   Ширина прямоугольника
 * @param  length  Длина прямоугольника
 * @param  type    Тип вычисления (calc_perimetr/calc_square)
 * @return Периметр или площадь (int)
 */
int get_rect(int width, int length, calc_type type = calc_perimetr);

/**
 * @brief  Вычисляет периметр или площадь прямоугольника (double)
 * @param  width   Ширина прямоугольника
 * @param  length  Длина прямоугольника
 * @param  type    Тип вычисления (calc_perimetr/calc_square)
 * @return Периметр или площадь (double)
 */
double get_rect(double width, double length, calc_type type = calc_perimetr);

/*** Function Implementation ***/
int get_rect(int width, int length, calc_type type)
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

double get_rect(double width, double length, calc_type type)
{
    if (type == calc_perimetr)
    {
        return 2.0 * (width + length);
    }
    else
    {
        return width * length;
    }
}
