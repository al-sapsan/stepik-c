/**********************************************************************
 * @file script4.cpp
 * @brief Mean value calculation (C/C++ compatible, embedded style)
 * @version 1.0
 * @date 2025-08-20
 **********************************************************************/

#ifdef __cplusplus
#include "emb_style_cpp_en.h"
#include <iostream>
#include <iomanip>
#else
#include "emb_style_cpp_en.h"
#include <stdio.h>
#endif

/*** Function Prototypes ***/
#ifdef __cplusplus
extern "C"
{
#endif
    /**
     * @brief  Вычисляет среднее арифметическое двух целых чисел
     * @param  a  Первое число
     * @param  b  Второе число
     * @return Среднее арифметическое
     */
    double mean_2(int a, int b);
#ifdef __cplusplus
}
#endif

/*** Main Function ***/
int main(void)
{
    int a = 0;
    int b = 0;
#ifdef __cplusplus
    std::cin >> a >> b;
    double result = mean_2(a, b);
    std::cout << std::fixed << std::setprecision(1) << result << std::endl;
#else
    scanf("%d %d", &a, &b);
    double result = mean_2(a, b);
    printf("%.1f\n", result);
#endif
    return 0;
}

/*** Function Implementation ***/
double mean_2(int a, int b)
{
    return (a + b) / 2.0;
}
