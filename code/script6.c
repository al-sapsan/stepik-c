/********************************************************************
 * @file    script6.c
 * @brief   Print symmetric star pyramid (Stepik 8.4.7)
 * @version 1.0
 * @date    2025-08-02
 *
 * @note    Embedded/robotics C style
 ********************************************************************/

/*** Core ***/
#include <stdio.h>

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Выводит симметричную фигуру из звездочек по числу строк n
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    int n_i32;
    if (scanf("%d", &n_i32) == 1 && n_i32 > 0)
    {
        for (int row = 0; row < n_i32; ++row)
        {
            for (int space = 0; space < n_i32 - row - 1; ++space)
            {
                (void)printf(" ");
            }
            for (int star = 0; star < 2 * row + 1; ++star)
            {
                (void)printf("*");
            }
            (void)printf("\n");
        }
    }
    return 0;
}
