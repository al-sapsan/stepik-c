/**********************************************************************
 * @file script7.cpp
 * @brief Замена повторяющихся дефисов на один
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
    string url;
    std::getline(cin, url);
    string result;
    char prev = 0;
    for (char ch : url)
    {
        if (ch == '-' && prev == '-')
            continue;
        result += ch;
        prev = ch;
    }
    cout << result << endl;

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
