/********************************************************************
 * @file    script8.c
 * @brief   Чтение точек в массив структур tag_point_3d
 * @version 1.0
 * @date    2025-07-28
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>

/*** Typedefs ***/
typedef struct tag_point_3d
{
    int x;
    int y;
    int z;
} tag_point_3d;

enum
{
    total_points = 100
};

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Читает координаты точек и выводит последнюю корректную
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    tag_point_3d points[total_points];
    int total = 0;
    int x, y, z;
    while (total < total_points && scanf("%d %d %d", &x, &y, &z) == 3)
    {
        points[total].x = x;
        points[total].y = y;
        points[total].z = z;
        total++;
    }
    if (total > 0)
    {
        printf("%d %d %d\n", points[total - 1].x, points[total - 1].y, points[total - 1].z);
    }
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
