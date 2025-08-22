/**********************************************************************
 * @file script5.cpp
 * @brief Inline sum of int array (embedded C++ style)
 * @version 1.1
 * @date 2025-08-22
 **********************************************************************/

#include <iostream>

/*** Function Prototypes ***/
/**
 * @brief  Вычисляет сумму элементов массива int
 * @param  arr  Массив целых чисел
 * @param  len  Количество элементов
 * @return Сумма элементов массива
 */
inline int sum_ar_int(const int *arr, size_t len);

/*** Main Function ***/
int main(void)
{
    int arr[10] = {0};
    for (size_t i = 0; i < 10; ++i)
    {
        std::cin >> arr[i];
    }
    int result = sum_ar_int(arr, 10);
    std::cout << result << std::endl;
    return 0;
}

/*** Function Implementation ***/
inline int sum_ar_int(const int *arr, size_t len)
{
    int sum = 0;
    for (size_t i = 0; i < len; ++i)
    {
        sum += arr[i];
    }
    return sum;
}
