/**********************************************************************
 * @file script5.cpp
 * @brief Mean value for arrays (embedded C++ style)
 * @version 1.0
 * @date 2025-08-20
 **********************************************************************/

#include "emb_style_cpp_en.h"
#include <iostream>
#include <iomanip>

/*** Function Prototypes ***/
/**
 * @brief  Вычисляет среднее арифметическое массива short
 * @param  d    Указатель на массив
 * @param  len  Количество элементов
 * @return Среднее арифметическое
 */
double get_mean(const short *d, const size_t len);

/**
 * @brief  Вычисляет среднее арифметическое массива int
 * @param  d    Указатель на массив
 * @param  len  Количество элементов
 * @return Среднее арифметическое
 */
double get_mean(const int *d, const size_t len);

/**
 * @brief  Вычисляет среднее арифметическое массива double
 * @param  d    Указатель на массив
 * @param  len  Количество элементов
 * @return Среднее арифметическое
 */
double get_mean(const double *d, const size_t len);

/*** Main Function ***/
int main(void)
{
    short arr[100] = {0};
    size_t count = 0;
    int value = 0;
    while (std::cin >> value)
    {
        if (count < 100)
        {
            arr[count++] = static_cast<short>(value);
        }
    }
    double result = get_mean(arr, count);
    std::cout << std::fixed << std::setprecision(2) << result << std::endl;
    return 0;
}

/*** Function Implementation ***/
double get_mean(const short *d, const size_t len)
{
    if (len == 0)
        return 0.0;
    double sum = 0.0;
    for (size_t i = 0; i < len; ++i)
    {
        sum += d[i];
    }
    return sum / len;
}

double get_mean(const int *d, const size_t len)
{
    if (len == 0)
        return 0.0;
    double sum = 0.0;
    for (size_t i = 0; i < len; ++i)
    {
        sum += d[i];
    }
    return sum / len;
}

double get_mean(const double *d, const size_t len)
{
    if (len == 0)
        return 0.0;
    double sum = 0.0;
    for (size_t i = 0; i < len; ++i)
    {
        sum += d[i];
    }
    return sum / len;
}
