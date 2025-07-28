/*******************************************************************************
 * @file    dyn_array_append.c
 * @brief   Динамическое добавление элементов в массив с перераспределением
 * @version 1.0
 * @date    2025-07-24
 ******************************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

/*** Typedefs ***/
typedef uint8_t u8_t;
typedef int16_t i16_t;
typedef uint32_t u32_t;

/*** Function Prototypes ***/

/**
 * @brief  Добавляет элемент в динамический массив с возможным расширением
 * @param[in,out] ptr_data     Указатель на массив
 * @param[in,out] ptr_length   Текущее количество элементов
 * @param[in,out] ptr_capacity Текущая вместимость массива
 * @param[in]     value        Добавляемое значение
 * @return Новый указатель на массив (возможно изменённый после realloc)
 */
static i16_t *append_short(i16_t *ptr_data, size_t *ptr_length, size_t *ptr_capacity, i16_t value);

/*** Main Function ***/

/**
 * @brief  Точка входа в программу
 *         Генерирует массив из 11 случайных значений, добавляя их динамически
 * @return Код завершения (0 — успешно, 1 — ошибка памяти)
 */
int main(void)
{
    size_t capacity = 10;
    size_t length = 0;

    i16_t *ptr_data = malloc(sizeof(i16_t) * capacity);
    if (ptr_data == NULL)
    {
        (void)printf("Ошибка: не удалось выделить память\n");
        return 1;
    }

    for (size_t i = 0; i < 11; i++)
    {
        ptr_data = append_short(ptr_data, &length, &capacity, (i16_t)(rand() % 40 - 20));
        if (ptr_data == NULL)
        {
            (void)printf("Ошибка: не удалось расширить массив\n");
            return 1;
        }
    }

    (void)printf("length = %u, capacity = %u\n", (u32_t)length, (u32_t)capacity);

    for (size_t i = 0; i < length; i++)
    {
        (void)printf("%d ", ptr_data[i]);
    }
    (void)printf("\n");

    free(ptr_data);
    return 0;
}

/*** Function Implementation ***/

static i16_t *append_short(i16_t *ptr_data, size_t *ptr_length, size_t *ptr_capacity, i16_t value)
{
    if (*ptr_length >= *ptr_capacity)
    {
        size_t new_capacity = (*ptr_capacity) * 2;
        i16_t *ptr_new_data = malloc(sizeof(i16_t) * new_capacity);
        if (ptr_new_data == NULL)
        {
            return NULL;
        }

        for (size_t i = 0; i < *ptr_length; i++)
        {
            ptr_new_data[i] = ptr_data[i];
        }

        free(ptr_data);
        ptr_data = ptr_new_data;
        *ptr_capacity = new_capacity;
    }

    ptr_data[*ptr_length] = value;
    (*ptr_length)++;

    return ptr_data;
}
