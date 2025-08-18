/**********************************************************************
 * @file script5.cpp
 * @brief Вывод последних трех символов строки в обратном порядке
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
    size_t len = msg.size();
    for (size_t i = 0; i < 3; ++i)
    {
        std::putchar(msg[len - 1 - i]);
    }

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
