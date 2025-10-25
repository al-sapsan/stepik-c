/*******************************************************************************
 * @file    script_divisors_recursive.c
 * @brief   Рекурсивный вывод делителей числа в порядке возрастания
 * @version 1.0
 * @date    2025-07-18
 ******************************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <math.h>

/*** Typedefs ***/
typedef unsigned int u32_t;
typedef double f64_t;

/*** Function Prototypes ***/

/**
 * @brief Рекурсивно выводит делители от 1 до sqrt(n)
 * @param[in] val_n Число
 * @param[in] idx_i Текущий индекс
 */
void print_divisors_forward(u32_t val_n, u32_t idx_i);

/**
 * @brief Рекурсивно выводит парные делители от sqrt(n) до 1
 * @param[in] val_n Число
 * @param[in] idx_i Текущий индекс
 */
void print_divisors_reverse(u32_t val_n, u32_t idx_i);

/*** Main Function ***/

/**
 * @brief Точка входа
 * @return Код завершения
 */
int main(void)
{
    u32_t val_n = 0U;
    scanf("%u", &val_n);

    f64_t root_f64 = sqrt((f64_t)val_n);
    u32_t root_u32 = (u32_t)root_f64;

    print_divisors_forward(val_n, 1U);
    print_divisors_reverse(val_n, root_u32);

    printf("\n");
    return 0;
}

/*** Function Implementation ***/

void print_divisors_forward(u32_t val_n, u32_t idx_i)
{
    f64_t root_f64 = sqrt((f64_t)val_n);
    u32_t root_u32 = (u32_t)root_f64;

    if (idx_i > root_u32)
    {
        return;
    }

    if (val_n % idx_i == 0U)
    {
        printf("%u ", idx_i);
    }

    print_divisors_forward(val_n, idx_i + 1U);
}

void print_divisors_reverse(u32_t val_n, u32_t idx_i)
{
    if (idx_i == 0U)
    {
        return;
    }

    u32_t pair = val_n / idx_i;

    if (val_n % idx_i == 0U && pair != idx_i)
    {
        printf("%u ", pair);
    }

    print_divisors_reverse(val_n, idx_i - 1U);
}
