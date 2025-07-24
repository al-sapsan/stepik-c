/*******************************************************************************
 * @file    script4.c
 * @brief   Среднее арифметическое по фильтру
 * @version 1.0
 * @date    2025-07-24
 ******************************************************************************/
#include <stdio.h>

/*** Function Prototypes ***/
/**
 * @brief Фильтр: истина для чисел от 1 до 5 включительно
 * @param[in] x Проверяемое число
 * @return 1 если x в диапазоне, иначе 0
 */
int is_1_5(int x);

/**
 * @brief Среднее арифметическое по фильтру
 * @param ar Массив
 * @param len_ar Длина массива
 * @param filter Функция-фильтр
 * @return Среднее арифметическое
 */
double mean_ar(const int *ar, size_t len_ar, int (*filter)(int));

/*** Main Function ***/
int main(void)
{
    int marks[20] = {0};
    int x = 0;
    size_t count = 0;
    while (scanf("%d", &x) == 1)
    {
        if (count < 20)
            marks[count++] = x;
    }
    double result = mean_ar(marks, count, is_1_5);
    printf("%.1f\n", result);
    return 0;
}

/*** Function Implementations ***/
int is_1_5(int x)
{
    return (x >= 1 && x <= 5) ? 1 : 0;
}

double mean_ar(const int *ar, size_t len_ar, int (*filter)(int))
{
    int sum = 0;
    size_t cnt = 0;
    for (size_t i = 0; i < len_ar; ++i)
    {
        if (filter(ar[i]))
        {
            sum += ar[i];
            ++cnt;
        }
    }
    if (cnt == 0)
        return 0.0;
    return (double)sum / cnt;
}
