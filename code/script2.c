/*******************************************************************************
 * @file    script2.c
 * @brief   Генерация циклической последовательности чисел с параметрами
 * @version 1.0
 * @date    2025-07-21
 ******************************************************************************/

/*** Includes ***/
#include <stdio.h>

/*** Function Prototypes ***/

/**
 * @brief Генерирует последовательность чисел от start до stop с шагом step (циклически)
 * @param[in] start Начальное значение последовательности
 * @param[in] stop  Конечное значение последовательности (включительно)
 * @param[in] step  Шаг последовательности
 * @return Следующее значение последовательности
 */
int range(int start, int stop, int step);

/*** Main Function ***/

/**
 * @brief Точка входа в программу
 * @return Код завершения
 */
int main(void)
{
    int start = 0, stop = 0, step = 0;
    scanf("%d %d %d", &start, &stop, &step);

    for (size_t i = 0; i < 20; ++i)
    {
        int val = range(start, stop, step);
        printf("%d", val);
        if (i != 19)
            printf(" ");
    }
    printf("\n");
    return 0;
}

/*** Function Definitions ***/

int range(int start, int stop, int step)
{
    static int s_start = 0, s_stop = 0, s_step = 0, s_cur = 0;
    static int s_first_call = 1;

    if (s_first_call)
    {
        s_start = start;
        s_stop = stop;
        s_step = step;
        s_cur = s_start;
        s_first_call = 0;
        return s_cur;
    }
    s_cur += s_step;
    if ((s_step > 0 && s_cur > s_stop) || (s_step < 0 && s_cur < s_stop))
    {
        s_cur = s_start;
    }
    return s_cur;
}