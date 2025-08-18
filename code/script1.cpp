/**********************************************************************
 * @file script1.cpp
 * @brief Подсчет целых точек внутри четырехугольника
 * @version 1.0
 * @date 2025-08-16
 **********************************************************************/

/*** Libraries ***/
#include <iostream>
#include <cmath>

/*** Typedefs ***/
struct point
{
    int x, y;
};

/*** Constants ***/
constexpr size_t CORNERS = 4;

/*** Function Prototypes ***/
/**
 * @brief Вычисляет расстояние между двумя точками
 * @param a Первая точка
 * @param b Вторая точка
 * @return double Расстояние
 */
double get_distance(const point &a, const point &b);

/**
 * @brief Вычисляет площадь треугольника по трем точкам
 * @param a Первая точка
 * @param b Вторая точка
 * @param c Третья точка
 * @return double Площадь
 */
double get_triangle_area(const point &a, const point &b, const point &c);

/**
 * @brief Проверяет принадлежность точки четырехугольнику
 * @param quad Массив вершин четырехугольника
 * @param pt Проверяемая точка
 * @return bool true, если принадлежит
 */
bool is_point_in_quad(const point (&quad)[CORNERS], const point &pt);

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    point arr_quad_point[CORNERS];
    int count = 0;
    while (count < CORNERS && scanf("%d; %d", &arr_quad_point[count].x, &arr_quad_point[count].y) == 2)
        count++;
    if (count != CORNERS)
    {
        puts("Неверное количество или формат входных данных.");
        return 1;
    }
    // Найти границы поиска
    int min_x = arr_quad_point[0].x, max_x = arr_quad_point[0].x;
    int min_y = arr_quad_point[0].y, max_y = arr_quad_point[0].y;
    for (size_t i = 1; i < CORNERS; ++i)
    {
        if (arr_quad_point[i].x < min_x)
            min_x = arr_quad_point[i].x;
        if (arr_quad_point[i].x > max_x)
            max_x = arr_quad_point[i].x;
        if (arr_quad_point[i].y < min_y)
            min_y = arr_quad_point[i].y;
        if (arr_quad_point[i].y > max_y)
            max_y = arr_quad_point[i].y;
    }
    int total_points = 0;
    for (int x = min_x; x <= max_x; ++x)
    {
        for (int y = min_y; y <= max_y; ++y)
        {
            point pt = {x, y};
            if (is_point_in_quad(arr_quad_point, pt))
            {
                ++total_points;
            }
        }
    }
    std::cout << total_points << std::endl;
    return 0;
}

/*** Function Implementation ***/
double get_distance(const point &a, const point &b)
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double get_triangle_area(const point &a, const point &b, const point &c)
{
    double ab = get_distance(a, b);
    double bc = get_distance(b, c);
    double ca = get_distance(c, a);
    double p = (ab + bc + ca) / 2.0;
    return std::sqrt(p * (p - ab) * (p - bc) * (p - ca));
}

bool is_point_in_quad(const point (&quad)[CORNERS], const point &pt)
{
    double quad_area = get_triangle_area(quad[0], quad[1], quad[2]) + get_triangle_area(quad[0], quad[2], quad[3]);
    double sum_area = get_triangle_area(pt, quad[0], quad[1]) +
                      get_triangle_area(pt, quad[1], quad[2]) +
                      get_triangle_area(pt, quad[2], quad[3]) +
                      get_triangle_area(pt, quad[3], quad[0]);
    return std::abs(sum_area - quad_area) < 1e-6;
}
