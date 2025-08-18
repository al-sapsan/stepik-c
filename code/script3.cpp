/**********************************************************************
 * @file script3.cpp
 * @brief Формирование строки с параметрами width и height
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
using std::to_string;

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main()
{
    int width = 0;
    int height = 0;
    cin >> width >> height;
    const string data_str = "Переменная width = " + to_string(width) + ", переменная height = " + to_string(height);
    cout << data_str << endl;

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}