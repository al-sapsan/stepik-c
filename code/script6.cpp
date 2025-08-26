/**********************************************************************
 * @file script6.cpp
 * @brief Структура tag_point_3d, массив points, ввод и вывод (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-26
 **********************************************************************/

#include <iostream>

/**
 * @brief Структура точки в 3D пространстве
 */
struct tag_point_3d
{
    int x;
    int y;
    int z;
};

enum
{
    total_points = 100
};

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 * @return Код завершения (0 — успешно, 1 — ошибка памяти)
 */
int main(void)
{
    tag_point_3d arr_points[total_points];
    int total = 0;
    int val;
    int buf[3];
    int idx = 0;
    while (std::cin >> val)
    {
        buf[idx++] = val;
        if (idx == 3)
        {
            arr_points[total].x = buf[0];
            arr_points[total].y = buf[1];
            arr_points[total].z = buf[2];
            ++total;
            idx = 0;
            if (total == total_points)
                break;
        }
    }
    if (total > 0)
        std::cout << arr_points[0].x << " " << arr_points[0].y << " " << arr_points[0].z << std::endl;
    __ASSERT_TESTS__
    return 0;
}
