/**********************************************************************
 * @file script4.cpp
 * @brief Вывод первых четырех символов строки
 * @version 1.0
 * @date 2025-08-18
 **********************************************************************/

/*** Libraries ***/
#include <iostream>
#include <string>

/*** Usings ***/
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main()
{
    string msg;
    std::getline(cin, msg);
    for (size_t i = 0; i < 4; ++i)
    {
        std::putchar(msg[i]);
    }

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
