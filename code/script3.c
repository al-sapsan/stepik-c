
/*******************************************************************************
 * @file    script3.c
 * @brief   Генерация циклической последовательности с параметрами (start, stop, step)
 * @version 1.0
 * @date    2025-07-25
 ******************************************************************************/

/*** Includes ***/

#include <stdio.h>

/*** Function Prototypes ***/

/**
 * @brief Генерирует циклическую последовательность целых чисел
 *
 * При первом вызове инициализирует параметры последовательности (start, stop, step).
 * При последующих вызовах возвращает следующее значение последовательности.
 * После достижения stop возвращается к start.
 * Не использует глобальных переменных.
 *
 * @param[in] start Начальное значение (только при первом вызове)
 * @param[in] stop Конечное значение (включительно, только при первом вызове)
 * @param[in] step Шаг (только при первом вызове)
 * @return Следующее значение последовательности
 */
int range(int start, int stop, int step);

/*** Main Function ***/

/**
 * @brief Точка входа в программу
 * @return Код завершения (0)
 */
int main(void)
{
    int start_i32, stop_i32, step_i32;
    scanf("%d %d %d", &start_i32, &stop_i32, &step_i32);

    for (size_t i = 0; i < 20; ++i)
    {
        printf("%d ", range(start_i32, stop_i32, step_i32));
    }
    return 0;
}

/*** Function Implementation ***/

int range(int start, int stop, int step)
{
    static int s_start_i32 = 0;
    static int s_stop_i32 = 0;
    static int s_step_i32 = 0;
    static int s_current_i32 = 0;
    static int s_first_call_b = 1;

    if (s_first_call_b)
    {
        s_start_i32 = start;
        s_stop_i32 = stop;
        s_step_i32 = step;
        s_current_i32 = s_start_i32;
        s_first_call_b = 0;
        return s_current_i32;
    }

    s_current_i32 += s_step_i32;
    if ((s_step_i32 > 0 && s_current_i32 > s_stop_i32) || (s_step_i32 < 0 && s_current_i32 < s_stop_i32))
    {
        s_current_i32 = s_start_i32;
    }
    return s_current_i32;
}
