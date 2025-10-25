/*******************************************************************************
 * @file    stack_example.c
 * @brief   Пример реализации стека с операциями push/pop
 * @version 1.0
 * @date    2025-07-29
 ******************************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <stdlib.h>

/*** Typedefs ***/
/**
 * @brief Структура узла стека
 */
typedef struct obj_tag
{
    int data_i32;             /**< Значение узла */
    struct obj_tag *next_ptr; /**< Указатель на следующий элемент */
} obj_t;

/*** Function Prototypes ***/
/**
 * @brief Добавляет элемент в стек
 * @param[in] top_ptr Текущий верхний элемент
 * @param[in] data_i32 Значение для нового узла
 * @return Новый указатель на вершину стека
 */
obj_t *push(obj_t *top_ptr, int data_i32);

/**
 * @brief Удаляет элемент с вершины стека
 * @param[in] top_ptr Текущий верхний элемент
 * @return Новый указатель на вершину стека
 */
obj_t *pop(obj_t *top_ptr);

/**
 * @brief Показывает все элементы стека
 * @param[in] top_ptr Указатель на вершину стека
 */
void show_stack(const obj_t *top_ptr);

/*** Main Function ***/
/**
 * @brief Точка входа в программу. Демонстрация операций со стеком.
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    obj_t *top_ptr = NULL;

    top_ptr = push(top_ptr, 1);
    top_ptr = push(top_ptr, 2);
    top_ptr = push(top_ptr, 3);
    top_ptr = push(top_ptr, 4);

    show_stack(top_ptr);

    while (top_ptr != NULL)
    {
        top_ptr = pop(top_ptr);
    }

    return 0;
}

/*** Function Implementation ***/
obj_t *push(obj_t *top_ptr, int data_i32)
{
    obj_t *new_ptr = malloc(sizeof(obj_t));
    if (new_ptr == NULL)
    {
        (void)printf("Ошибка: нехватка памяти\n");
        return top_ptr;
    }

    new_ptr->data_i32 = data_i32;
    new_ptr->next_ptr = top_ptr;

    return new_ptr;
}

obj_t *pop(obj_t *top_ptr)
{
    if (top_ptr == NULL)
    {
        return NULL;
    }

    (void)printf("Удалено: %d\n", top_ptr->data_i32);

    obj_t *next_ptr = top_ptr->next_ptr;
    free(top_ptr);

    return next_ptr;
}

void show_stack(const obj_t *top_ptr)
{
    const obj_t *cur_ptr = top_ptr;
    while (cur_ptr != NULL)
    {
        (void)printf("%d\n", cur_ptr->data_i32);
        cur_ptr = cur_ptr->next_ptr;
    }
}
