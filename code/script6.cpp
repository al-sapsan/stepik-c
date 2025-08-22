/**********************************************************************
 * @file script6.cpp
 * @brief Inline range generator (embedded C++ style)
 * @version 1.1
 * @date 2025-08-22
 **********************************************************************/

#include <cstddef>

/*** Function Prototypes ***/
/**
 * @brief  Заполняет массив арифметической прогрессией
 * @param  arr      Массив int для заполнения
 * @param  max_len  Максимальная длина массива
 * @param  start    Начальное значение
 * @param  stop     Конечное значение (не включается)
 * @param  step     Шаг прогрессии
 */
inline void range(int *arr, size_t max_len, int start, int stop, int step);

/*** Function Implementation ***/
inline void range(int *arr, size_t max_len, int start, int stop, int step)
{
    size_t i = 0;
    int value = start;
    while (i < max_len && ((step > 0 && value < stop) || (step < 0 && value > stop)))
    {
        arr[i++] = value;
        value += step;
    }
}
