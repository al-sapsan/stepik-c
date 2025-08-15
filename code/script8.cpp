/**********************************************************************
 * @file script8.cpp
 * @brief Выбор предметов для рюкзака по весу (структура THING)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-15
 **********************************************************************/

#include <iostream>
#include <cstring>

/*** Typedefs ***/
using u32_t = unsigned int;
using THING = struct
{
    char name_str[51];
    u32_t weight_u32_g;
};

/*** Constants ***/
constexpr size_t NUM_THINGS = 14;

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    THING things[NUM_THINGS] = {
        {"карандаш", 20}, {"зеркальце", 100}, {"зонт", 500}, {"рубашка", 300}, {"брюки", 1000}, {"бумага", 200}, {"молоток", 600}, {"пила", 400}, {"удочка", 1200}, {"расческа", 40}, {"котелок", 820}, {"палатка", 5240}, {"брезент", 2130}, {"спички", 10}};
    u32_t max_weight_u32_g = 0;
    std::cin >> max_weight_u32_g;
    max_weight_u32_g *= 1000;
    // Сортировка по убыванию веса
    for (size_t i = 0; i + 1 < NUM_THINGS; ++i)
    {
        for (size_t j = i + 1; j < NUM_THINGS; ++j)
        {
            if (things[i].weight_u32_g < things[j].weight_u32_g)
            {
                THING tmp = things[i];
                things[i] = things[j];
                things[j] = tmp;
            }
        }
    }
    u32_t sum_weight_u32_g = 0;
    bool first = true;
    for (size_t i = 0; i < NUM_THINGS; ++i)
    {
        if (sum_weight_u32_g + things[i].weight_u32_g <= max_weight_u32_g)
        {
            sum_weight_u32_g += things[i].weight_u32_g;
            if (!first)
                std::cout << " ";
            std::cout << things[i].name_str;
            first = false;
        }
    }
    std::cout << std::endl;
    return 0;
}
