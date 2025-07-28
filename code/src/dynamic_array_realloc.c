/*******************************************************************************
 * @file    dyn_array_append_realloc.c
 * @brief   Динамическое добавление элементов в массив с realloc
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
typedef int8_t i8_t;
typedef int16_t s16_t;
typedef uint16_t u16_t;
typedef int32_t s32_t;
typedef uint32_t u32_t;
typedef float f32_t;
typedef double f64_t;
typedef uint8_t b_t;

/*** Function Prototypes ***/

/**
 * @brief  Добавляет элемент в динамический массив, используя realloc
 * @param[in,out] ptr_data     Указатель на массив
 * @param[in,out] ptr_length   Текущее количество элементов
 * @param[in,out] ptr_capacity Текущая вместимость массива
 * @param[in]     value        Добавляемое значение
 * @return Новый указатель на массив (возможно изменённый после realloc)
 */
static s16_t *append_s16(s16_t *ptr_data, size_t *ptr_length, size_t *ptr_capacity, s16_t value);

/*** Main Function ***/

/**
 * @brief Точка входа в программу. Демонстрирует добавление элементов в массив.
 * @return Код завершения (0 — успешно, 1 — ошибка)
 */
int main(void)
{
    size_t capacity = 10;
    size_t length = 0;

    s16_t *ptr_data = malloc(sizeof(s16_t) * capacity);
    if (ptr_data == NULL)
    {
        (void)printf("Ошибка: не удалось выделить память\n");
        return 1;
    }

    for (size_t i = 0; i < 11; ++i)
    {
        ptr_data = append_s16(ptr_data, &length, &capacity, (s16_t)(rand() % 40 - 20));
        if (ptr_data == NULL)
        {
            (void)printf("Ошибка: не удалось перераспределить память\n");
            return 1;
        }
    }

    (void)printf("length = %u, capacity = %u\n", (u32_t)length, (u32_t)capacity);

    for (size_t i = 0; i < length; ++i)
    {
        (void)printf("%d ", ptr_data[i]);
    }
    (void)printf("\n");

    free(ptr_data);
    return 0;
}

/*** Function Implementation ***/

static s16_t *append_s16(s16_t *ptr_data, size_t *ptr_length, size_t *ptr_capacity, s16_t value)
{
    if (*ptr_length >= *ptr_capacity)
    {
        size_t new_capacity = (*ptr_capacity) * 2;
        s16_t *ptr_new_data = realloc(ptr_data, sizeof(s16_t) * new_capacity);
        if (ptr_new_data == NULL)
        {
            return NULL;
        }

        ptr_data = ptr_new_data;
        *ptr_capacity = new_capacity;
    }

    ptr_data[*ptr_length] = value;
    (*ptr_length)++;

    return ptr_data;
}
