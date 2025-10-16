/************************************************************************
 * @file script6.cpp
 * @brief Template function min_3 for embedded C++ style
 * @version 1.0 (Embedded C++ bare-metal/RTOS)
 * @date 2025-10-06
 *
 * @warning Ensure all input values are validated!
 * @note Tested on ARM Cortex-M, RISC-V, Xtensa (ESP32), RP2040
 *************************************************************************/

#include <iostream>

/********** Template Function **********/

/**
 * @brief Вычисляет минимальное из трех значений
 * @tparam T Тип значения
 * @param a Первое значение
 * @param b Второе значение
 * @param c Третье значение
 * @return Минимальное значение
 */
template <typename T>
T min_3(T a, T b, T c)
{
    T min_val = a;
    if (b < min_val)
        min_val = b;
    if (c < min_val)
        min_val = c;
    return min_val;
}

/********** Main Function **********/

int main()
{
    int res_1 = min_3(1, -6, 10);
    double res_2 = min_3(0.5, 0.3, 0.1);
    char res_3 = min_3('a', 'b', '0');

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
