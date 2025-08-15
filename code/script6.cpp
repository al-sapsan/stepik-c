/**********************************************************************
 * @file script6.cpp
 * @brief Структура FIO с использованием FIO_STR, чтение из потока
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-15
 **********************************************************************/

#include <iostream>
#include <cstring>

/*** Typedefs ***/
using FIO_STR = char[51];
using FIO = struct
{
    FIO_STR first;
    FIO_STR otch;
    FIO_STR last;
};

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    FIO fio = {0};
    std::cin >> fio.first >> fio.otch >> fio.last;
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
