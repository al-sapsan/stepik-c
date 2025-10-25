/*******************************************************************************
 * @file script8.c
 * @brief Рекурсивное заполнение массива диапазоном чисел
 * @version 1.0
 * @date 2025-07-23
 ******************************************************************************/
#include <stdio.h>
#define MAX_LENGTH 20

/*** Function Prototype ***/
/**
 * @brief Fill array with range recursively
 * @param ptr_a Указатель на массив
 * @param max_len Максимальная длина массива
 * @param from Начальное значение диапазона
 * @param to Конечное значение диапазона
 * @param count Текущее количество записанных элементов
 * @return Количество записанных элементов
 * @details Рекурсивно заполняет массив числами от from до to включительно
 */
size_t range_to_ar(int *ptr_a, size_t max_len, int from, int to, size_t count);

/*** Main Function ***/
int main(void)
{
    int max_rec = 0;
    int ar[MAX_LENGTH] = {0};
    scanf("%d", &max_rec);

    size_t cnt = range_to_ar(ar, MAX_LENGTH, 1, max_rec, 0);

    for (size_t i = 0; i < cnt; ++i)
    {
        printf("%d%s", ar[i], (i + 1 < cnt) ? " " : "");
    }
    printf("\n");
    return 0;
}

/*** Function Implementation ***/
size_t range_to_ar(int *ptr_a, size_t max_len, int from, int to, size_t count)
{
    if (from > to || count >= max_len)
        return count;
    ptr_a[count] = from;
    return range_to_ar(ptr_a, max_len, from + 1, to, count + 1);
}
