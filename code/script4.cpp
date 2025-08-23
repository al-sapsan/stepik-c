/**********************************************************************
 * @file script4.cpp
 * @brief Sum elements by filter (embedded C++ style)
 * @version 1.1
 * @date 2025-08-23
 **********************************************************************/

#include <iostream>

enum
{
    max_length_ar = 20
};
using filter_func = bool (*)(int);

/*** Function Prototypes ***/
/**
 * @brief  Суммирует элементы массива по фильтру
 * @param  ar     Массив int
 * @param  len    Длина массива
 * @param  filter Функция-фильтр (true — включить в сумму)
 * @return Сумма элементов, удовлетворяющих фильтру
 */
int sum_elem(const int *ar, size_t len, filter_func filter);

/*** Main Function ***/
int main(void)
{
    int marks[max_length_ar] = {0};
    int count = 0;
    while (count < max_length_ar && std::cin >> marks[count])
        count++;

    int result = sum_elem(marks, count, [](int v)
                          { return v % 2 == 0 && v % 3 == 0; });
    std::cout << result << std::endl;

    return 0;
}

/*** Function Implementation ***/
int sum_elem(const int *ar, size_t len, filter_func filter)
{
    int sum = 0;
    for (size_t i = 0; i < len; ++i)
    {
        if (filter(ar[i]))
        {
            sum += ar[i];
        }
    }
    return sum;
}
