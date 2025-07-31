/********************************************************************
 * @file    script1.c
 * @brief   Работа со структурой tag_geom и указателем
 * @version 1.0
 * @date    2025-07-29
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>

/*** Typedefs ***/
typedef struct tag_geom
{
    char type;
    int x0;
    int y0;
    int x1;
    int y1;
} tag_geom;

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Заполняет структуру tag_geom и выводит поля через указатель
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    tag_geom geom;
    geom.type = 1;
    geom.x0 = 10;
    geom.y0 = 20;
    geom.x1 = 50;
    geom.y1 = 30;

    tag_geom *ptr_geom = &geom;
    printf("%d %d %d %d %d\n", ptr_geom->type, ptr_geom->x0, ptr_geom->y0, ptr_geom->x1, ptr_geom->y1);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать)
        return 0;
}
