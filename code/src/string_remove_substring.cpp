/**
 * @file string_remove_substring.cpp
 * @brief Удаление всех вхождений подстроки из строки
 * @version 1.0
 * @date 2025-07-17
 * @author —
 *
 * @warning Не удаляет перекрывающиеся подстроки
 */

#include <iostream>
#include <string>

/*** Function Prototypes ***/

/**
 * @brief Удаляет все вхождения подстроки из строки
 *
 * @param[in,out] str Строка, из которой нужно удалить подстроку
 * @param[in] sub Подстрока, которую требуется удалить
 */
void remove_substring(std::string &str, const std::string &sub);

/*** Main Function ***/

int main()
{
    std::string input;
    std::string pattern;

    std::getline(std::cin, input);
    std::getline(std::cin, pattern);

    remove_substring(input, pattern);

    std::cout << input << "\n";
    return 0;
}

/*** Function Definitions ***/

void remove_substring(std::string &str, const std::string &sub)
{
    std::size_t pos = 0;
    std::size_t sub_len = sub.length();

    if (sub_len == 0)
        return;

    while ((pos = str.find(sub, pos)) != std::string::npos)
    {
        str.erase(pos, sub_len);
        // Повторный поиск начинается с того же места, т.к. строка сместилась
    }
}
