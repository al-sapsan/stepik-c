/**
 * @file    word_filter.cpp
 * @brief   Печать слов, начинающихся с заданного символа
 * @version 1.0
 * @date    2025-07-16
 * @note    Реализация на C++ без использования STL
 */

#include <iostream> // Core: std::cin, std::cout
#include <cstring>  // Core: std::strlen
#include <cctype>   // Core: std::isspace

/*** Constants ***/
constexpr int MAX_STR_LEN = 1000;

/*** Main Function ***/

int main()
{
    char input_str[MAX_STR_LEN] = {};
    char target_ch = '\0';
    int idx_i32 = 0;
    int word_start_i32 = 0;

    /* Считать строку целиком */
    std::cin.getline(input_str, MAX_STR_LEN);

    /* Считать символ */
    std::cin >> target_ch;

    /* Пропустить ведущие пробелы */
    while ((input_str[idx_i32] != '\0') && std::isspace(static_cast<unsigned char>(input_str[idx_i32])))
    {
        idx_i32++;
    }

    while (input_str[idx_i32] != '\0')
    {
        word_start_i32 = idx_i32;

        /* Найти конец слова */
        while ((input_str[idx_i32] != '\0') && !std::isspace(static_cast<unsigned char>(input_str[idx_i32])))
        {
            idx_i32++;
        }

        if (input_str[word_start_i32] == target_ch)
        {
            std::cout.write(&input_str[word_start_i32], idx_i32 - word_start_i32);
            std::cout << "\n";
        }

        /* Пропустить пробелы после слова */
        while ((input_str[idx_i32] != '\0') && std::isspace(static_cast<unsigned char>(input_str[idx_i32])))
        {
            idx_i32++;
        }
    }

    return 0;
}
