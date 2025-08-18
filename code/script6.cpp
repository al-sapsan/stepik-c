/**********************************************************************
 * @file script6.cpp
 * @brief Формирование строки из городов с длиной имени > 5
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

/*** Constants ***/
enum
{
    max_cities = 10
};

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main()
{
    string cities[max_cities];
    size_t count = 0;
    while (count < max_cities && cin >> cities[count])
        ++count;
    string res;
    for (size_t i = 0; i < count; ++i)
    {
        if (cities[i].size() > 5)
        {
            if (!res.empty())
                res += " ";
            res += cities[i];
        }
    }
    cout << res << endl;

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
