/**********************************************************************
 * @file script7.cpp
 * @brief Обработка массива оценок: обнуление значений < 3
 * @version 1.0
 * @date 2025-08-16
 **********************************************************************/

/*** Libraries ***/
#include "emb_style_cpp_en.h"
#include <iostream>

/*** Typedefs ***/
using i16_t = short;

/*** Constants ***/
constexpr size_t TOTAL_MARKS = 23;

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    i16_t arr_marks_i16[TOTAL_MARKS] = {0};
    size_t count = 0;
    i16_t val_i16;
    while (count < TOTAL_MARKS && std::cin >> val_i16)
    {
        arr_marks_i16[count++] = val_i16;
    }
    for (i16_t &mark : arr_marks_i16)
    {
        if (mark < 3)
            mark = 0;
    }
    for (size_t i = 0; i < TOTAL_MARKS; ++i)
    {
        std::cout << arr_marks_i16[i];
        if (i + 1 < count)
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}
