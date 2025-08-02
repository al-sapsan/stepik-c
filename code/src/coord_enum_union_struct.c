/********************************************************************
 * @file    script1.c
 * @brief   Работа с объединением и enum для координат
 * @version 1.0
 * @date    2025-07-31
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>

/*** Typedefs ***/
typedef enum
{
    coord_int = 1,
    coord_double = 2
} TYPE_COORD;

typedef union
{
    int coord_i;
    double coord_d;
} COORD;

typedef struct
{
    COORD x;
    COORD y;
    TYPE_COORD type;
} POINT2;

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Считывает тип и координаты, заполняет структуру POINT2
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    POINT2 pt;
    int type_val;
    if (scanf("%d", &type_val) == 1)
    {
        if (type_val == coord_int)
        {
            pt.type = coord_int;
            scanf("%d %d", &pt.x.coord_i, &pt.y.coord_i);
        }
        else
        {
            pt.type = coord_double;
            scanf("%lf %lf", &pt.x.coord_d, &pt.y.coord_d);
        }
    }
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
