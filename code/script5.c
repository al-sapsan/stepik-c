/********************************************************************
 * @file    script5.c
 * @brief   Копирование структуры tag_price и вывод полей
 * @version 1.0
 * @date    2025-07-28
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>

/*
struct tag_price
{
    char name[100];
    unsigned int rubs;
    unsigned short kops;
    unsigned int foreign_key;
};
*/

/*** Main Function ***/
int main(void)
{
    // Объявляем переменную pr и копируем данные из price_100
    struct tag_price pr = price_100;

    // Выводим поля структуры в нужном порядке
    printf("%s %u %hu %u\n", pr.name, pr.rubs, pr.kops, pr.foreign_key);

    __ASSERT_TESTS__ // макроопределение для тебирования (не убирать)
        return 0;
}