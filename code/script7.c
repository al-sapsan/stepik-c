
/********************************************************************
 * @file    script7.c
 * @brief   Динамическое расширение массива short и заполнение значением
 * @version 1.0
 * @date    2025-07-28
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <stdlib.h>

#define TOTAL 10

/*** Function Implementation ***/
void *expand_array(short *ptr, size_t *len, short fill)
{
    if (ptr == NULL || len == NULL || *len == 0)
        return NULL;
    size_t new_len = (*len) * 2;
    short *ptr_new = (short *)malloc(new_len * sizeof(short));
    if (ptr_new == NULL)
        return ptr;
    for (size_t i = 0; i < *len; ++i)
        ptr_new[i] = ptr[i];
    for (size_t i = *len; i < new_len; ++i)
        ptr_new[i] = fill;
    free(ptr);
    *len = new_len;
    return ptr_new;
}

/*** Main Function ***/
int main(void)
{
    short *ptr_d = calloc(TOTAL, sizeof(short));
    size_t len = TOTAL;
    if (ptr_d == NULL)
        return 0;

    int count = 0;
    while (count < TOTAL && scanf("%hd", &ptr_d[count]) == 1)
        count++;

    // Расширение массива и заполнение значением -1
    ptr_d = expand_array(ptr_d, &len, -1);

    // Вывод всех len элементов
    for (size_t i = 0; i < len; ++i)
        printf("%hd ", ptr_d[i]);
    printf("\n");

    free(ptr_d);
    return 0;
}
