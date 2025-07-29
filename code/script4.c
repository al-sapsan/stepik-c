
/********************************************************************
 * @file    script4.c
 * @brief   Заполнение структуры vector значениями из ввода
 * @version 1.0
 * @date    2025-07-28
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>

/*** Typedefs ***/
typedef struct tag_vector
{
    short x;
    short y;
    short z;
} tag_vector;

/*** Main Function ***/
int main(void)
{
    tag_vector vector;
    scanf("%hd %hd %hd", &vector.x, &vector.y, &vector.z);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
