/*******************************************************************************
 * @file    emb_generator.c
 * @brief   Генерация последовательности 5, 8, 11, ...
 * @version 1.0
 * @date    2025-07-24
 ******************************************************************************/
#include <stdio.h>

/*** Function Prototype ***/
/**
 * @brief Генерирует последовательность 5, 8, 11, ...
 * @return Следующее число последовательности
 */
int range(void);

/*** Main Function ***/
int main(void)
{
    for (size_t i = 0; i < 7; ++i)
    {
        if (i > 0)
            (void)printf(" ");
        (void)printf("%d", range());
    }
    (void)printf("\n");
    return 0;
}

/*** Function Implementation ***/
int range(void)
{
    static int s_value_i32 = 5;
    int result_i32 = s_value_i32;
    s_value_i32 += 3;
    return result_i32;
}
