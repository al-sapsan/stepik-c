/**********************************************************************
 * @file script4.cpp
 * @brief Чтение и вывод слова (импорт cin, cout, endl)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-15
 **********************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    char word_str[51] = {0}; // 50 + 1 для '\0'
    cin >> word_str;
    cout << word_str << endl;
    return 0;
}
