/**********************************************************************
 * @file script7.cpp
 * @brief Sum array with predicate (embedded C++ style)
 * @version 1.1
 * @date 2025-08-22
 **********************************************************************/

#include "emb_style_cpp_en.h"
#include <iostream>

enum
{
    max_size = 20
};

/*** Function Prototypes ***/
/**
 * @brief  Вычисляет сумму элементов массива по предикату
 * @param  ar      Массив целых чисел
 * @param  len_ar  Количество элементов
 * @param  pred    Указатель на функцию-предикат (bool(int))
 * @return Сумма элементов, удовлетворяющих предикату
 */
int sum_ar(const int *ar, size_t len_ar, bool (*pred)(int));

/*** Main Function ***/
int main(void)
{
    int marks[max_size] = {0};
    int x = 0;
    size_t count = 0;
    while (std::cin >> x)
    {
        if (count < max_size)
        {
            marks[count++] = x;
        }
    }
    auto is_even = [](int v) -> bool
    { return v % 2 == 0; };
    int result = sum_ar(marks, count, is_even);
    std::cout << result << std::endl;
    return 0;
}

/*** Function Implementation ***/
int sum_ar(const int *ar, size_t len_ar, bool (*pred)(int))
{
    int sum = 0;
    for (size_t i = 0; i < len_ar; ++i)
    {
        if (pred(ar[i]))
        {
            sum += ar[i];
        }
    }
    return sum;
}
