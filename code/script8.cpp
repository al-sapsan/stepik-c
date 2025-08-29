/**********************************************************************
 * @file script8.cpp
 * @brief Dynamic array of long, initialization and cleanup
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-29
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Typedefs ***/
typedef long i64_t;

/*** Main Function ***/
int main(void)
{
    i64_t *ar_long = new i64_t[1000];
    for (int i = 0; i < 1000; ++i)
    {
        ar_long[i] = 0;
    }
    ar_long[4] = -7; // 5-й элемент (индексация с 0)
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        delete[] ar_long;
    return 0;
}
