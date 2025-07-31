/********************************************************************
 * @file    script5.c
 * @brief   Вычисление средних координат массива структур POINT
 * @version 1.0
 * @date    2025-07-29
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <stdlib.h>

/*** Typedefs ***/
typedef struct
{
    int x;
    int y;
} POINT;

typedef struct
{
    double mean_x;
    double mean_y;
} DATA;

/*** Function Prototypes ***/
/**
 * @brief  Вычисляет средние значения координат массива POINT
 * @param[in] arr Массив структур POINT
 * @param[in] len Количество элементов массива
 * @return Структура DATA с результатами
 */
DATA get_means(const POINT arr[], size_t len);

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Считывает точки, вычисляет средние координаты
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    POINT points[20];
    size_t count = 0;
    int x, y;
    while (count < 20 && scanf("%d %d", &x, &y) == 2)
    {
        points[count].x = x;
        points[count].y = y;
        count++;
    }
    if (count > 0)
    {
        DATA res = get_means(points, count);
        (void)printf("%.2f %.2f\n", res.mean_x, res.mean_y);
    }
    return 0;
}

/*** Function Implementation ***/
DATA get_means(const POINT arr[], size_t len)
{
    double sum_x = 0.0, sum_y = 0.0;
    for (size_t i = 0; i < len; i++)
    {
        sum_x += arr[i].x;
        sum_y += arr[i].y;
    }
    DATA result;
    result.mean_x = sum_x / len;
    result.mean_y = sum_y / len;
    return result;
}
