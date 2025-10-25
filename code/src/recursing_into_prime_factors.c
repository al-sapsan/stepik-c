/*******************************************************************************
 * @file    recursing_into_prime_factors.c
 * @brief   Разложение числа на простые множители (рекурсивно)
 * @version 1.1
 * @date    2025-07-24
 ******************************************************************************/

/*** Includes ***/
#include <stdio.h>

/*** Typedefs ***/
typedef unsigned int u32_t;

/*** Function Prototypes ***/

/**
 * @brief Рекурсивно выводит простые множители числа
 * @param[in] val_n Число, которое нужно разложить
 * @param[in] is_first Признак первого вывода (1 — да, 0 — нет)
 */
void print_prime_factors_rec(u32_t val_n, u32_t is_first);

/*** Main Function ***/

/**
 * @brief Точка входа в программу
 * @return Код завершения
 */
int main(void)
{
    u32_t val_n = 0U;
    scanf("%u", &val_n);

    print_prime_factors_rec(val_n, 1U);

    printf("\n");
    return 0;
}

/*** Function Implementation ***/

void print_prime_factors_rec(u32_t val_n, u32_t is_first)
{
    for (u32_t val_d = 2U; val_d <= val_n; ++val_d)
    {
        if ((val_n % val_d) == 0U)
        {
            if (!is_first)
            {
                printf(" ");
            }

            printf("%u", val_d);
            print_prime_factors_rec(val_n / val_d, 0U);
            return;
        }
    }
}
