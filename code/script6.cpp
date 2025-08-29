/**********************************************************************
 * @file script6.cpp
 * @brief Dynamic array of complex, initialization and cleanup
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-29
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Typedefs ***/
typedef double f64_t;

/*** Struct Definition ***/
struct complex
{
    f64_t re;
    f64_t im;
};

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @details Выделение памяти под массив complex, инициализация, освобождение
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    complex *vc = new complex[7];
    for (int i = 0; i < 7; ++i)
    {
        vc[i].re = 0.0;
        vc[i].im = 0.0;
    }
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        delete[] vc;
    return 0;
}
