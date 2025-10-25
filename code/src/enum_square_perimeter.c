
/********************************************************************
 * @file    enum_square_perimeter.c
 * @brief   Вычисление площади или периметра прямоугольника через enum и функцию
 * @version 1.0
 * @date    2025-07-28
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>

/*** Typedefs ***/
typedef enum
{
    _perimetr = 1,
    _square = 2
} calc_types;

/*** Function Prototypes ***/
/**
 * @brief Вычисляет площадь или периметр прямоугольника
 *
 * @param[in] width  Ширина прямоугольника
 * @param[in] height Высота прямоугольника
 * @param[in] type   Тип вычисления (периметр или площадь)
 * @return double    Результат вычисления
 */
double calc_rect(double width, double height, calc_types type);

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0)
 */
int main(void)
{
    int type_i32 = 0;
    double width_f64 = 0.0, height_f64 = 0.0;
    scanf("%d %lf %lf", &type_i32, &width_f64, &height_f64);

    double result_f64 = calc_rect(width_f64, height_f64, (calc_types)type_i32);
    printf("%.1f\n", result_f64);
    return 0;
}

/*** Function Implementation ***/
double calc_rect(double width, double height, calc_types type)
{
    if (type == _square)
        return width * height;
    else if (type == _perimetr)
        return 2.0 * (width + height);
    return 0.0;
}
