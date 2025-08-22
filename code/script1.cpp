/**********************************************************************
 * @file script1.cpp
 * @brief Array sort with change count (embedded C++ style)
 * @version 1.0
 * @date 2025-08-20
 **********************************************************************/

#include <cstddef>

/*** Typedefs ***/
using type_sort = enum { sort_asc,
                         sort_desc };

/*** Function Prototypes ***/
/**
 * @brief  Сортирует массив short по возрастанию/убыванию
 * @param  ar    Массив для сортировки
 * @param  len   Количество элементов
 * @param  type  Тип сортировки (sort_asc/sort_desc)
 * @return Количество элементов, которые поменяли свое значение
 */
int sort(short *ar, size_t len, type_sort type = sort_asc);

/*** Function Implementation ***/
int sort(short *ar, size_t len, type_sort type)
{
    if (len == 0 || ar == nullptr)
        return 0;
    int changed = 0;
    // Сохраняем исходные значения
    short original[256];
    size_t max_len = (len > 256) ? 256 : len;
    for (size_t i = 0; i < max_len; ++i)
    {
        original[i] = ar[i];
    }
    // Bubble sort
    for (size_t i = 0; i < len; ++i)
    {
        for (size_t j = 0; j < len - 1; ++j)
        {
            bool swap = false;
            if (type == sort_asc && ar[j] > ar[j + 1])
                swap = true;
            if (type == sort_desc && ar[j] < ar[j + 1])
                swap = true;
            if (swap)
            {
                short tmp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = tmp;
            }
        }
    }
    // Считаем измененные элементы
    for (size_t i = 0; i < max_len; ++i)
    {
        if (ar[i] != original[i])
            ++changed;
    }
    return changed;
}
