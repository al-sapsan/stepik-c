/********************************************************************
 * @file    script7.c
 * @brief   Реализация стека для хранения истории URL-адресов
 * @version 1.0
 * @date    2025-07-29
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*** Typedefs ***/
typedef struct tag_obj
{
    struct tag_obj *next;
    char url[1024];
} OBJ;

/*** Function Prototypes ***/
/**
 * @brief  Добавляет новый элемент в стек
 * @param[in] top Текущий верхний элемент стека
 * @param[in] url URL-адрес для добавления
 * @return Новый верхний элемент стека
 */
OBJ *push(OBJ *top, const char *url);

/**
 * @brief  Удаляет верхний элемент стека
 * @param[in] top Текущий верхний элемент стека
 * @return Новый верхний элемент стека
 */
OBJ *pop(OBJ *top);

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Формирует стек URL-адресов и освобождает память
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    OBJ *top = NULL;
    top = push(top, "https://proproprogs.ru/c_base/c_base/c_etapy-translyacii-programmy-v-mashinnyy-kod-standarty");
    top = push(top, "https://proproprogs.ru/c_base/c_struktura-i-ponimanie-raboty-programmy-hello-world");
    top = push(top, "https://proproprogs.ru/c_base/c_dvoichnaya-shestnadcaterichnaya-i-vosmerichnaya-sistemy-schisleniya");
    top = push(top, "https://proproprogs.ru/c_base/c_lokalnye-i-globalnye-peremennye");
    top = push(top, "https://proproprogs.ru/c_base/c_perechisleniya-enum-direktiva-typedef");

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать)

        // Освобождение памяти стека
        while (top != NULL)
    {
        top = pop(top);
    }
    return 0;
}

/*** Function Implementation ***/

OBJ *push(OBJ *top, const char *url)
{
    OBJ *node = (OBJ *)malloc(sizeof(OBJ));
    if (node == NULL)
    {
        return top;
    }
    strncpy(node->url, url, sizeof(node->url) - 1);
    node->url[sizeof(node->url) - 1] = '\0';
    node->next = top;
    return node;
}

OBJ *pop(OBJ *top)
{
    if (top == NULL)
    {
        return NULL;
    }
    OBJ *next = top->next;
    free(top);
    return next;
}
