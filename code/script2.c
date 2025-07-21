/**
 * @file sum_even.c
 * @brief Сумма четных чисел в массиве с использованием функции-фильтра
 * @version 1.0
 */

#include <stdio.h>
#include <stddef.h>

/*** Function Prototypes ***/

/**
 * @brief Проверка на чётность
 * @param[in] x Число
 * @return 1, если чётное, иначе 0
 */
int is_even(int x);

/**
 * @brief Суммирует элементы массива, удовлетворяющие фильтру
 * @param[in] ar Указатель на массив
 * @param[in] len_ar Длина массива
 * @param[in] filter Указатель на функцию-фильтр
 * @return Сумма подходящих элементов
 */
int sum_ar(const int *ar, size_t len_ar, int (*filter)(int));

/*** Main Function ***/

/**
 * @brief Точка входа
 * @return Код завершения программы
 */
int main(void)
{
    int marks[20] = {0};
    int x = 0;
    size_t count = 0;

    while (scanf("%d", &x) == 1)
    {
        if (count < 20)
        {
            marks[count++] = x;
        }
    }

    int result = sum_ar(marks, count, is_even);
    printf("%d\n", result);

    return 0;
}

/*** Function Definitions ***/

int is_even(int x)
{
    return (x % 2 == 0);
}

int sum_ar(const int *ar, size_t len_ar, int (*filter)(int))
{
    int sum = 0;

    for (size_t i = 0; i < len_ar; ++i)
    {
        if (filter(ar[i]))
        {
            sum += ar[i];
        }
    }

    return sum;
}
