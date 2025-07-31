/********************************************************************
 * @file    script4.c
 * @brief   Вычисление площади прямоугольника по двум точкам
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

/*** Function Prototypes ***/
int rect_square(const POINT *p0, const POINT *p1);

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Вычисляет площадь прямоугольника по двум точкам
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    POINT pt0, pt1;
    scanf("%d %d %d %d", &pt0.x, &pt0.y, &pt1.x, &pt1.y);
    int square = rect_square(&pt0, &pt1);
    (void)printf("%d\n", square);
    return 0;
}

/*** Function Implementation ***/
/**
 * @brief  Вычисляет площадь прямоугольника по двум точкам
 * @param[in] p0 Указатель на первую точку (верхний левый угол)
 * @param[in] p1 Указатель на вторую точку (нижний правый угол)
 * @return Площадь прямоугольника
 */
int rect_square(const POINT *p0, const POINT *p1)
{
    int width = abs(p1->x - p0->x);
    int height = abs(p1->y - p0->y);
    return width * height;
}
