/********************************************************************
 * @file    script3.c
 * @brief   Сложение комплексных чисел через функцию complex_sum
 * @version 1.0
 * @date    2025-07-29
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>

/*** Typedefs ***/
typedef struct
{
    double re; // действительная часть
    double im; // мнимая часть
} COMPLEX;

/*** Function Prototypes ***/
COMPLEX complex_sum(COMPLEX a, COMPLEX b);

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Складывает два комплексных числа через функцию complex_sum
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    COMPLEX cmp_1, cmp_2, res;
    scanf("%lf, %lf, %lf, %lf", &cmp_1.re, &cmp_1.im, &cmp_2.re, &cmp_2.im);
    res = complex_sum(cmp_1, cmp_2);
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать)
        return 0;
}

/*** Function Implementation ***/
/**
 * @brief  Складывает два комплексных числа
 * @param[in] a Первое комплексное число
 * @param[in] b Второе комплексное число
 * @return Сумма комплексных чисел
 */
COMPLEX complex_sum(COMPLEX a, COMPLEX b)
{
    COMPLEX result;
    result.re = a.re + b.re;
    result.im = a.im + b.im;
    return result;
}
