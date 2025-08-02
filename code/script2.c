/********************************************************************
 * @file    script2.c
 * @brief   Суммирование массива объединений DATA с типом TYPE_PARAM
 * @version 1.0
 * @date    2025-07-31
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <stddef.h>

/*** Typedefs ***/
typedef enum
{
    param_int,
    param_double
} TYPE_PARAM;

typedef union
{
    int data_i;
    double data_d;
} DATA;

/*** Function Prototypes ***/
/**
 * @brief  Суммирует значения массива DATA по типу TYPE_PARAM
 * @param[in] arr Массив DATA
 * @param[in] len Количество элементов
 * @param[in] type Тип данных
 * @return DATA с суммой в соответствующем поле
 */
DATA sum_ar(const DATA arr[], size_t len, TYPE_PARAM type);

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Демонстрирует суммирование int и double массивов DATA
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    DATA res_1 = sum_ar((DATA[]){{1}, {2}, {3}, {4}, {5}}, 5, param_int);
    DATA res_2 = sum_ar((DATA[]){{.data_d = 1.1}, {.data_d = 2.2}, {.data_d = 3.3}, {.data_d = 4.4}, {.data_d = 5.5}}, 5, param_double);
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}

/*** Function Implementation ***/
DATA sum_ar(const DATA arr[], size_t len, TYPE_PARAM type)
{
    DATA result;
    if (type == param_int)
    {
        int sum = 0;
        for (size_t i = 0; i < len; i++)
        {
            sum += arr[i].data_i;
        }
        result.data_i = sum;
    }
    else
    {
        double sum = 0.0;
        for (size_t i = 0; i < len; i++)
        {
            sum += arr[i].data_d;
        }
        result.data_d = sum;
    }
    return result;
}
