/**
 * @file    string_remove_substring.cpp
 * @brief   Удаляет все появления контрольного слова из строки, сохраняя пробелы
 * @version 1.0
 * @date    2025-07-17
 */

#include <iostream>
#include <string>

/*** Constants ***/
static const size_t MAX_STR_LEN = 256;

/*** Function Prototypes ***/
/**
 * @brief Удаляет все появления слова sub из строки str, сохраняя пробелы
 * @param[in,out] str Строка для обработки
 * @param[in] sub Контрольное слово
 */
void remove_substring(std::string &str, const std::string &sub);

/*** Main Function ***/
int main()
{
    std::string str, sub;
    std::getline(std::cin, str);
    std::getline(std::cin, sub);
    remove_substring(str, sub);
    std::cout << str << std::endl;
    return 0;
}

/*** Function Definitions ***/
void remove_substring(std::string &str, const std::string &sub)
{
    size_t pos = 0;
    size_t sub_len = sub.length();
    if (sub_len == 0)
        return;
    while ((pos = str.find(sub, pos)) != std::string::npos)
    {
        for (size_t i = 0; i < sub_len; ++i)
            str[pos + i] = ' ';
        pos += sub_len;
    }
}
