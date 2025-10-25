/*******************************************************************************
 * @file script9.c
 * @brief Рекурсивная сумма элементов массива short
 * @version 1.0
 * @date 2025-07-23
 ******************************************************************************/
#include <stdio.h>
#define MAX_LENGTH 20

/*** Function Prototype ***/
/**
 * @brief Recursive sum of array
 * @param ar Указатель на массив short
 * @param len Количество элементов
 * @param indx Текущий индекс
 * @return Сумма элементов
 * @details Рекурсивно вычисляет сумму элементов массива
 */
int sum_ar(const short *ar, size_t len, size_t indx);

/*** Main Function ***/
int main(void)
{
    short ar[MAX_LENGTH] = {0};
    size_t count = 0;
    while (count < MAX_LENGTH && scanf("%hd", &ar[count]) == 1)
        count++;

    int result = sum_ar(ar, count, 0);
    printf("%d\n", result);
    return 0;
}

/*** Function Implementation ***/
int sum_ar(const short *ar, size_t len, size_t indx)
{
    if (indx >= len)
        return 0;
    return ar[indx] + sum_ar(ar, len, indx + 1);
}
