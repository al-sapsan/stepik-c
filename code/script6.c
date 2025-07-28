
/********************************************************************
 * @file    script6.c
 * @brief   Динамическое выделение памяти, копирование и вывод массива int
 * @version 1.0
 * @date    2025-07-28
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0)
 */
int main(void)
{
    int lengths[20];
    int count = 0;
    int *ptr_lens = NULL;

    // Чтение не более 20 чисел
    while (count < 20 && scanf("%d", &lengths[count]) == 1)
    {
        ++count;
    }

    // Выделение памяти под 20 int с инициализацией нулями
    ptr_lens = (int *)calloc(20, sizeof(int));
    if (ptr_lens != NULL && count > 0)
    {
        memcpy(ptr_lens, lengths, count * sizeof(int));
    }

    // Вывод всех 20 чисел
    for (size_t i = 0; i < 20; ++i)
    {
        (void)printf("%d ", ptr_lens != NULL ? ptr_lens[i] : 0);
    }
    (void)printf("\n");

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

        // Освобождение памяти
        free(ptr_lens);
    return 0;
}
