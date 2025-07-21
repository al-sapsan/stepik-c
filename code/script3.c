/**
 * @file    sum_criteria.c
 * @brief   Суммирует элементы массива по заданному критерию
 * @version 1.1
 */

#include <stdio.h>
#include <stddef.h>

/*** Typedefs ***/

typedef int (*filter_func_t)(int);

/*** Function Prototypes ***/

/**
 * @brief Odd criteria
 * @details Возвращает 1 для нечётных значений, иначе 0
 */
int is_odd(int x);

/**
 * @brief Positive criteria
 * @details Возвращает 1 для неотрицательных значений, иначе 0
 */
int is_positive(int x);

/**
 * @brief Negative criteria
 * @details Возвращает 1 для отрицательных значений, иначе 0
 */
int is_negative(int x);

/**
 * @brief Default criteria
 * @details Возвращает 1 для всех значений
 */
int deflt(int x);

/**
 * @brief Sum by criteria
 * @param[in] ar Указатель на массив
 * @param[in] len_ar Количество элементов
 * @param[in] filter Функция-фильтр
 * @return Сумма подходящих элементов
 */
int sum_ar(const int *ar, size_t len_ar, filter_func_t filter);

/*** Main Function ***/

/**
 * @brief Точка входа в программу
 * @details Считывает число, определяющее критерий фильтрации:
 * - 1 — сумма нечётных
 * - 2 — сумма неотрицательных
 * - 3 — сумма отрицательных
 * - любое другое — сумма всех
 *
 * Далее считываются значения массива, и выводится результат суммирования
 * по выбранному критерию.
 *
 * @return 0 при успешном завершении
 */
int main(void)
{
    filter_func_t funcs[4] =
        {
            is_odd,
            is_positive,
            is_negative,
            deflt};

    int marks[20] = {0};
    int item = 0;
    size_t count = 0;
    int x = 0;

    scanf("%d", &item); // выбор критерия

    while (scanf("%d", &x) == 1)
    {
        if (count < 20)
        {
            marks[count++] = x;
        }
    }

    int sum = 0;

    switch (item)
    {
    case 1:
        sum = sum_ar(marks, count, funcs[0]);
        break;
    case 2:
        sum = sum_ar(marks, count, funcs[1]);
        break;
    case 3:
        sum = sum_ar(marks, count, funcs[2]);
        break;
    default:
        sum = sum_ar(marks, count, funcs[3]);
        break;
    }

    printf("%d\n", sum);

    return 0;
}

/*** Criteria Functions ***/

int is_odd(int x)
{
    return (x % 2 != 0);
}

int is_positive(int x)
{
    return (x >= 0);
}

int is_negative(int x)
{
    return (x < 0);
}

int deflt(int x)
{
    (void)x;
    return 1;
}

/*** Sum Function ***/

int sum_ar(const int *ar, size_t len_ar, filter_func_t filter)
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
