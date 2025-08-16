/**********************************************************************
 * @file script5.cpp
 * @brief Проверка принадлежности точки четырехугольнику по площади
 * @version 1.0
 * @date 2025-08-15
 **********************************************************************/

/*** Libraries ***/
#include "emb_style_cpp_en.h"
#include <iostream>
#include <cmath>

/*** Typedefs ***/
typedef struct
{
    int x;
    int y;
} point_t;

/*** Constants ***/
constexpr size_t CORNERS = 4;

/*** Function Prototypes ***/
/**
 * @brief Вычисляет расстояние между двумя точками
 * @param a Первая точка
 * @param b Вторая точка
 * @return double Расстояние
 */
double distance(const point_t &a, const point_t &b);

/**
 * @brief Вычисляет площадь треугольника по трем точкам
 * @param a Первая точка
 * @param b Вторая точка
 * @param c Третья точка
 * @return double Площадь
 */
double triangle_area(const point_t &a, const point_t &b, const point_t &c);

/**
 * @brief Проверяет принадлежность точки четырехугольнику
 * @param quad Массив вершин четырехугольника
 * @param pt Проверяемая точка
 * @return bool true, если принадлежит
 */
bool is_point_in_quad(const point_t quad[CORNERS], const point_t &pt);

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    point_t arr_quad_point[CORNERS];
    point_t pt;
    int count = 0;
    while (count < CORNERS && scanf("%d; %d", &arr_quad_point[count].x, &arr_quad_point[count].y) == 2)
        count++;
    if (count != CORNERS)
    {
        puts("Неверное количество или формат входных данных.");
        return 1;
    }
    if (scanf("%d; %d", &pt.x, &pt.y) != 2)
    {
        puts("Неверное количество или формат входных данных.");
        return 2;
    }
    bool res_b = is_point_in_quad(arr_quad_point, pt);
    std::cout << (res_b ? "yes" : "no") << std::endl;
    return 0;
}

/*** Function Implementation ***/
double distance(const point_t &a, const point_t &b)
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double triangle_area(const point_t &a, const point_t &b, const point_t &c)
{
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ca = distance(c, a);
    double p = (ab + bc + ca) / 2.0;
    return std::sqrt(p * (p - ab) * (p - bc) * (p - ca));
}

bool is_point_in_quad(const point_t quad[CORNERS], const point_t &pt)
{
    // Площадь четырехугольника: сумма двух треугольников
    double quad_area = triangle_area(quad[0], quad[1], quad[2]) + triangle_area(quad[0], quad[2], quad[3]);
    // Сумма площадей четырех треугольников с точкой
    double sum_area = triangle_area(pt, quad[0], quad[1]) +
                      triangle_area(pt, quad[1], quad[2]) +
                      triangle_area(pt, quad[2], quad[3]) +
                      triangle_area(pt, quad[3], quad[0]);
    // Сравниваем с учетом погрешности
    return std::abs(sum_area - quad_area) < 1e-6;
}
