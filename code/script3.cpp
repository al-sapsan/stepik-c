
/**
 * @file    remove_second_word.cpp
 * @brief   Удаляет второе слово из строки, все пробелы сохраняются
 * @version 1.0
 * @date    2025-07-16
 */

#include <iostream>
#include <string>

/*** Constants ***/
static const size_t MAX_STR_LEN = 256;

/*** Function Prototypes ***/

/**
 * @brief Удаляет второе слово из строки, все пробелы сохраняются
 * @param[in] str Входная строка
 * @return std::string Преобразованная строка
 */
std::string remove_second_word(const std::string &str);

/*** Main Function ***/
int main(void)
{
    std::string input;
    std::getline(std::cin, input);
    std::cout << remove_second_word(input) << std::endl;
    return 0;
}

/*** Function Definitions ***/
std::string remove_second_word(const std::string &str)
{
    size_t i = 0, n = str.size();
    size_t word_count = 0;
    size_t start2 = std::string::npos, end2 = std::string::npos;
    while (i < n)
    {
        // Пропустить пробелы
        while (i < n && str[i] == ' ')
            ++i;
        if (i == n)
            break;
        ++word_count;
        if (word_count == 2)
            start2 = i;
        // Пройти по слову
        while (i < n && str[i] != ' ')
            ++i;
        if (word_count == 2)
        {
            end2 = i;
            break;
        }
    }
    if (start2 != std::string::npos && end2 != std::string::npos)
    {
        std::string res = str;
        res.erase(start2, end2 - start2);
        return res;
    }
    return str;
}
