/********************************************************************
 * @file    script3.c
 * @brief   Работа с битовым полем PERSON_DATA
 * @version 1.0
 * @date    2025-07-31
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>

/*** Typedefs ***/
typedef struct
{
    unsigned int old : 7;
    unsigned int salary : 20;
    unsigned int height : 8;
    unsigned int weight : 7;
} PERSON_DATA;

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Заполняет битовое поле и выводит его размер
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    PERSON_DATA pd;
    pd.old = 45;
    pd.salary = 876043;
    pd.height = 186;
    pd.weight = 83;
    (void)printf("%zu\n", sizeof(pd));
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
