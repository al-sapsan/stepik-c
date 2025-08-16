/**********************************************************************
 * @file script8.cpp
 * @brief Вычисление расстояния между двумя точками
 * @version 1.0
 * @date 2025-08-16
 **********************************************************************/

/*** Libraries ***/
#include <iostream>
#include <iomanip>
#include <cmath>

/*** Typedefs ***/
using POINT = struct
{
    double x;
    double y;
};

/*** Function Prototypes ***/
/**
 * @brief Вычисляет евклидово расстояние между двумя точками
 * @param pt1 Первая точка
 * @param pt2 Вторая точка
 * @return double Расстояние
 */
double get_length(const POINT &pt1, const POINT &pt2);

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    POINT pt1 = {-2.5, 7.8};
    POINT pt2 = {11.4, 43.2};
    double len = get_length(pt1, pt2);
    std::cout << std::fixed << std::setprecision(2) << len << std::endl;
    return 0;
}

/*** Function Implementation ***/
double get_length(const POINT &pt1, const POINT &pt2)
{
    double dx = pt1.x - pt2.x;
    double dy = pt1.y - pt2.y;
    return std::sqrt(dx * dx + dy * dy);
}
