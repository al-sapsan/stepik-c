/**********************************************************************
 * @file script3.cpp
 * @brief Remove elements by filter (embedded C++ style)
 * @version 1.1
 * @date 2025-08-22
 **********************************************************************/

#include <iostream>

enum
{
    max_length_ar = 20
};
using filter_func = bool (*)(short);

/*** Function Prototypes ***/
/**
 * @brief  Удаляет элементы массива по фильтру
 * @param  ar     Массив short
 * @param  len    Ссылка на длину массива (обновляется)
 * @param  filter Функция-фильтр (true — удалить)
 */
void remove_elem(short *ar, int &len, filter_func filter);

/*** Main Function ***/
int main(void)
{
    short marks[max_length_ar] = {0};
    int count = 0;
    while (count < max_length_ar && std::cin >> marks[count])
        count++;

    remove_elem(marks, count, [](short v)
                { return v < 3; });
    for (int i = 0; i < count; ++i)
        std::cout << marks[i] << " ";
    std::cout << std::endl;

    return 0;
}

/*** Function Implementation ***/
void remove_elem(short *ar, int &len, filter_func filter)
{
    int j = 0;
    for (int i = 0; i < len; ++i)
    {
        if (!filter(ar[i]))
        {
            ar[j++] = ar[i];
        }
    }
    len = j;
}
