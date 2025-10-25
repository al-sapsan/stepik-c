/*******************************************************************************
 * @file    script_divisors_no_array.c
 * @brief   Вывод делителей числа в порядке возрастания без массива
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
 * @brief Выводит все делители числа в порядке возрастания
 * @param[in] val_n Входное число
 */
void print_divisors(u32_t val_n);

/*** Main Function ***/

/**
 * @brief Точка входа в программу
 * @return Код завершения (0)
 */
int main(void)
{
    u32_t val_n = 0U;
    scanf("%u", &val_n);

    print_divisors(val_n);

    return 0;
}

/*** Function Implementation ***/

void print_divisors(u32_t val_n)
{
    f64_t root_f64 = sqrt((f64_t)val_n);
    u32_t root_u32 = (u32_t)root_f64;

    // Первая часть — делители от 1 до sqrt(n)
    for (size_t i = 1U; i <= root_u32; ++i)
    {
        if (val_n % i == 0U)
        {
            printf("%u ", i);
        }
    }

    // Вторая часть — парные делители от n/sqrt(n) до n/1, исключая дубли
    for (size_t i = root_u32; i >= 1U; --i)
    {
        if (val_n % i == 0U)
        {
            u32_t pair = val_n / i;

            if (pair != i) // исключаем корень при квадрате
            {
                printf("%u ", pair);
            }
        }

        if (i == 1U) // избегаем переполнения при unsigned
        {
            break;
        }
    }

    printf("\n");
}
