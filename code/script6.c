/*******************************************************************************
 * @file script6.c
 * @brief Переворот массива типа short
 * @version 1.0
 * @date 2025-07-21
 ******************************************************************************/
#include <stdio.h>
#define MAX_SIZE 20

/*** Function Prototype ***/
/**
 * @brief Reverse array
 * @param ptr_arr_digs Указатель на массив short
 * @param count Количество элементов
 * @details Переворачивает массив: значения идут от последнего к первому
 */
void reverse(short *ptr_arr_digs, size_t count);

/*** Main Function ***/
int main(void)
{
    short digs[MAX_SIZE];
    size_t count = 0;
    while (count < MAX_SIZE && scanf("%hd", &digs[count]) == 1)
        count++;

    reverse(digs, count);

    for (size_t i = 0; i < count; ++i)
    {
        printf("%hd%s", digs[i], (i + 1 < count) ? " " : "");
    }
    printf("\n");
    return 0;
}

/*** Function Implementation ***/
void reverse(short *ptr_arr_digs, size_t count)
{
    for (size_t i = 0; i < count / 2; ++i)
    {
        short tmp = ptr_arr_digs[i];
        ptr_arr_digs[i] = ptr_arr_digs[count - 1 - i];
        ptr_arr_digs[count - 1 - i] = tmp;
    }
}
