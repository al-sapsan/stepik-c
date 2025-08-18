/**********************************************************************
 * @file script2.cpp
 * @brief Формирование строки ФИО из имени и фамилии
 * @version 1.0
 * @date 2025-08-18
 **********************************************************************/

#include <iostream>
#include <string>

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
    string fname;
    string lname;
    cin >> fname >> lname;
    const string fio = fname + ", " + lname;
    cout << fio << endl;

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
