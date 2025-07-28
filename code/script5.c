
/*******************************************************************************
 * @file    script5.c
 * @brief   Динамическое выделение памяти и инициализация массива short
 * @version 1.0
 * @date    2025-07-26
 ******************************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <stdlib.h>

/*** Typedefs ***/
typedef short i16_t;

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0)
 */
int main(void)
{
    /*** Variables ***/
    double digits[20];
    int count = 0;
    double *ptr_d = NULL;

    // Чтение не более 20 чисел
    while (count < 20 && scanf("%lf", &digits[count]) == 1)
    {
        ++count;
    }

    // Выделение памяти ровно под count элементов
    if (count > 0)
    {
        ptr_d = (double *)malloc(count * sizeof(double));
        if (ptr_d != NULL)
        {
            for (int i = 0; i < count; ++i)
            {
                ptr_d[i] = digits[i];
            }
        }
    }

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

        // Освобождение памяти
        free(ptr_d);
    return 0;
}
