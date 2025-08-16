/**********************************************************************
 * @file script9.cpp
 * @brief Вычисление площади треугольника по координатам
 * @version 1.0
 * @date 2025-08-16
 **********************************************************************/

/*** Libraries ***/
#include <iostream>
#include <iomanip>
#include <cmath>

/*** Typedefs ***/
struct point
{
    int x, y;
};

/*** Function Prototypes ***/
/**
 * @brief Вычисляет площадь треугольника по трем точкам
 * @param pt1 Первая точка
 * @param pt2 Вторая точка
 * @param pt3 Третья точка
 * @return double Площадь
 */
double sq_tr(const point &pt1, const point &pt2, const point &pt3);

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    point pt1, pt2, pt3;
    std::cin >> pt1.x >> pt1.y >> pt2.x >> pt2.y >> pt3.x >> pt3.y;
    double area = sq_tr(pt1, pt2, pt3);
    std::cout << std::fixed << std::setprecision(2) << area << std::endl;
    return 0;
}

/*** Function Implementation ***/
double sq_tr(const point &pt1, const point &pt2, const point &pt3)
{
    double a = std::sqrt((pt1.x - pt2.x) * (pt1.x - pt2.x) + (pt1.y - pt2.y) * (pt1.y - pt2.y));
    double b = std::sqrt((pt2.x - pt3.x) * (pt2.x - pt3.x) + (pt2.y - pt3.y) * (pt2.y - pt3.y));
    double c = std::sqrt((pt3.x - pt1.x) * (pt3.x - pt1.x) + (pt3.y - pt1.y) * (pt3.y - pt1.y));
    double p = (a + b + c) / 2.0;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}
