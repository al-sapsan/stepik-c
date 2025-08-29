/**********************************************************************
 * @file script3.cpp
 * @brief Dynamic array allocation and initialization (short)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-29
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Typedefs ***/
typedef short i16_t;

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @details Выделение памяти под массив, инициализация, запись значения
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    i16_t *ptr_ar = new i16_t[15];
    for (int i = 0; i < 15; ++i)
    {
        ptr_ar[i] = -1;
    }
    ptr_ar[4] = 100; // 5-й элемент (индексация с 0)

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
