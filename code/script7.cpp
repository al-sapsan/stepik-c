/**********************************************************************
 * @file script7.cpp
 * @brief Массив структур THING, сортировка по весу
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-15
 **********************************************************************/

#include <iostream>
#include <cstring>

/*** Typedefs ***/
using THING = struct
{
    char name_str[51];
    double weight_f64;
};

enum : size_t
{
    max_things = 20
};

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    THING th[max_things] = {0};
    size_t count_sz = 0;
    while (count_sz < max_things && std::cin >> th[count_sz].name_str >> th[count_sz].weight_f64)
    {
        ++count_sz;
    }
    // Сортировка по весу (возрастание)
    for (size_t i = 0; i + 1 < count_sz; ++i)
    {
        for (size_t j = i + 1; j < count_sz; ++j)
        {
            if (th[i].weight_f64 > th[j].weight_f64)
            {
                THING tmp = th[i];
                th[i] = th[j];
                th[j] = tmp;
            }
        }
    }
    for (size_t i = 0; i < count_sz; ++i)
    {
        std::cout << th[i].name_str;
        if (i + 1 < count_sz)
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}
