
/********************************************************************
 * @file    enum_switch_base.c
 * @brief   Обработка выбора пункта меню с использованием enum и switch
 * @version 1.0
 * @date    2025-07-28
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>

/*** Typedefs ***/
typedef enum
{
    item_exit = 1,
    item_c = 2,
    item_python = 3,
    item_java = 4
} menu_item;

/*** Main Function ***/
int main(void)
{
    int val_i32 = 0;
    scanf("%d", &val_i32);

    switch (val_i32)
    {
    case item_exit:
        printf("Выход\n");
        break;
    case item_c:
        printf("Язык Си\n");
        break;
    case item_python:
        printf("Язык Python\n");
        break;
    case item_java:
        printf("Язык Java\n");
        break;
    default:
        printf("Не верный пункт меню\n");
        break;
    }
    return 0;
}
