/********************************************************************
 * @file    script7.c
 * @brief   Сложение времени в структурах tag_time
 * @version 1.0
 * @date    2025-07-28
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>

/*** Typedefs ***/
typedef struct
{
    unsigned char hours;
    unsigned char minutes;
    unsigned char seconds;
} tag_time;

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Складывает два времени и выводит результат
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    tag_time tm1, tm2, tm_sum;
    unsigned int h1, m1, s1, h2, m2, s2;
    scanf("%u %u %u %u %u %u", &h1, &m1, &s1, &h2, &m2, &s2);
    tm1.hours = (unsigned char)h1;
    tm1.minutes = (unsigned char)m1;
    tm1.seconds = (unsigned char)s1;
    tm2.hours = (unsigned char)h2;
    tm2.minutes = (unsigned char)m2;
    tm2.seconds = (unsigned char)s2;

    unsigned int sum_sec = tm1.seconds + tm2.seconds;
    tm_sum.seconds = (unsigned char)(sum_sec % 60);
    unsigned int carry_min = sum_sec / 60;

    unsigned int sum_min = tm1.minutes + tm2.minutes + carry_min;
    tm_sum.minutes = (unsigned char)(sum_min % 60);
    unsigned int carry_hour = sum_min / 60;

    tm_sum.hours = (unsigned char)(tm1.hours + tm2.hours + carry_hour);

    printf("%02u:%02u:%02u\n", tm_sum.hours, tm_sum.minutes, tm_sum.seconds);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
