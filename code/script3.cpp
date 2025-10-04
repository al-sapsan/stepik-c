/**********************************************************************
 * @file script3.cpp
 * @brief sum_ar function implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-03
 **********************************************************************/

#include <iostream>
#include <stdexcept>

/********** Function Definition **********/
/**
 * @brief Суммирует значения элементов массива ar длиной size
 * @param ar Указатель на массив
 * @param size Размер массива
 * @return int Сумма элементов
 * @throws std::runtime_error если size == 0
 */
int sum_ar(short *ar, size_t size)
{
    if (size == 0)
        throw std::runtime_error("Array length is zero.");
    int sum = 0;
    for (size_t i = 0; i < size; ++i)
        sum += ar[i];
    return sum;
}

/********** Main Function **********/

int main(void)
{
    short arr[] = {-1, 0, 10, 5, 3, 2};
    int sm = 0;
    try
    {
        sm = sum_ar(arr, sizeof(arr) / sizeof(arr[0]));
        std::cout << sm << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    __ASSERT_TESTS__

    return 0;
}