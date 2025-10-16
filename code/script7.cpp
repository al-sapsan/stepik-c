/************************************************************************
 * @file script7.cpp
 * @brief Template function hypot for embedded C++ style
 * @version 1.0 (Embedded C++ bare-metal/RTOS)
 * @date 2025-10-06
 *
 * @warning Ensure all input values are validated!
 * @note Tested on ARM Cortex-M, RISC-V, Xtensa (ESP32), RP2040
 *************************************************************************/

#include <iostream>
#include <cmath>

/********** Template Function **********/

/**
 * @brief Вычисляет длину гипотенузы по двум катетам
 * @tparam T Тип значения
 * @param a Первый катет
 * @param b Второй катет
 * @return Длина гипотенузы (double)
 */
template <typename T>
double hypot(T a, T b)
{
    return std::sqrt(static_cast<double>(a) * static_cast<double>(a) + static_cast<double>(b) * static_cast<double>(b));
}

/********** Main Function **********/

int main()
{
    double h1 = hypot(1, 0.5);
    double h2 = hypot(6.3, 0.8);

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
