/**********************************************************************
 * @file script4.cpp
 * @brief Структура tag_point, массив случайных точек, средние значения (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-27
 **********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @brief Структура точки на плоскости
 */
struct tag_point
{
    float x;
    float y;
};

enum
{
    total_points = 128
};

/*** Main Function ***/
int main(void)
{
    tag_point arr_ps[total_points];
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    double sum_x = 0.0, sum_y = 0.0;
    for (int i = 0; i < total_points; ++i)
    {
        arr_ps[i].x = -100.0f + 200.0f * (std::rand() / (float)RAND_MAX);
        arr_ps[i].y = -100.0f + 200.0f * (std::rand() / (float)RAND_MAX);
        sum_x += arr_ps[i].x;
        sum_y += arr_ps[i].y;
    }
    double mean_x = sum_x / total_points;
    double mean_y = sum_y / total_points;
    __ASSERT_TESTS__
    return 0;
}