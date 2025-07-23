/*******************************************************************************
 * @file script1.c
 * @brief Рекурсивное преобразование таблицы массивов в один массив
 * @version 1.0
 * @date 2025-07-23
 ******************************************************************************/
#include <stdio.h>
#define MAX_LENGTH 20

/*** Function Prototype ***/
/**
 * @brief Flatten table of arrays into one array recursively
 * @param v Массив, в который заносятся значения
 * @param max_len_v Максимальная длина массива v
 * @param table Массив указателей на массивы
 * @param len Длина массива table
 * @param count_v Число записанных в массив v значений
 * @param indx_t Индекс по первой размерности (table)
 * @param indx Индекс по второй размерности (элементы массива)
 * @return Количество записанных значений
 * @details Рекурсивно заносит значения из table в v, не используя циклы
 */
size_t to_flat(short *v, size_t max_len_v, short *table[], size_t len, size_t count_v, size_t indx_t, size_t indx);

/*** Main Function ***/
int main(void)
{
    short ar_1[] = {-4, 2, 3, 7, 0};
    short ar_2[] = {11, 6, 10, 8, 13, 98, -5, 0};
    short ar_3[] = {-47, 0};
    short ar_4[] = {8, 11, 56, -3, -2, 0};

    short *table[] = {ar_1, ar_4, ar_3, ar_2};
    short flat[MAX_LENGTH] = {0};

    size_t cnt = to_flat(flat, MAX_LENGTH, table, sizeof(table) / sizeof(*table), 0, 0, 0);

    for (size_t i = 0; i < cnt; ++i)
        printf("%d ", flat[i]);
    printf("\n");
    return 0;
}

/*** Function Implementation ***/
size_t to_flat(short *v, size_t max_len_v, short *table[], size_t len, size_t count_v, size_t indx_t, size_t indx)
{
    if (count_v >= max_len_v || indx_t >= len)
        return count_v;
    if (table[indx_t][indx] == 0)
        return to_flat(v, max_len_v, table, len, count_v, indx_t + 1, 0);
    v[count_v] = table[indx_t][indx];
    return to_flat(v, max_len_v, table, len, count_v + 1, indx_t, indx + 1);
}
