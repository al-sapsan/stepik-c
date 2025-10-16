/************************************************************************
 * @file script8.cpp
 * @brief Template function ar_sum_positive for embedded C++ style
 * @version 1.0 (Embedded C++ bare-metal/RTOS)
 * @date 2025-10-06
 *
 * @warning Ensure all input values are validated!
 * @note Tested on ARM Cortex-M, RISC-V, Xtensa (ESP32), RP2040
 *************************************************************************/

#include <iostream>

/********** Template Function **********/

/**
 * @brief Вычисляет сумму положительных элементов массива
 * @tparam AR Тип массива
 * @param arr Массив
 * @param len Длина массива
 * @return Сумма положительных элементов
 */
template <typename AR>
AR ar_sum_positive(const AR *arr, size_t len)
{
    AR sum = 0;
    for (size_t i = 0; i < len; ++i)
    {
        if (arr[i] > 0)
            sum += arr[i];
    }
    return sum;
}

/********** Main Function **********/

int main()
{
    float d1[] = {0.1f, 2.4f, 1.5f, -0.3f, 1.0f, -11.5f};
    double d2[] = {-4.3, 0.8, 15.3, -0.01, -1.2, -6.5};
    int d3[] = {6, 4, -1, -3, 0, 10, 8, -1, 2};

    float s1 = ar_sum_positive(d1, sizeof(d1) / sizeof(d1[0]));
    double s2 = ar_sum_positive(d2, sizeof(d2) / sizeof(d2[0]));
    int s3 = ar_sum_positive(d3, sizeof(d3) / sizeof(d3[0]));

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
