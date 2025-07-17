/**
 * @file    string_longest_word.cpp
 * @brief   Печатает самое длинное слово из введённой строки (слова разделены пробелами)
 * @version 1.0
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

/*** Constants ***/
static const size_t MAX_STR_LEN = 129;

/*** Function Prototypes ***/

/**
 * @brief Печатает самое длинное слово из строки
 * @param[in] str Входная строка
 */
void print_longest_word(const char *str);

/*** Main Function ***/
int main(void)
{
    char input_str[MAX_STR_LEN];

    if (fgets(input_str, MAX_STR_LEN, stdin) == NULL)
    {
        return 1;
    }

    size_t len_u32 = strlen(input_str);
    if (len_u32 > 0 && input_str[len_u32 - 1] == '\n')
    {
        input_str[len_u32 - 1] = '\0';
    }

    print_longest_word(input_str);

    return 0;
}

/*** Function Definitions ***/
void print_longest_word(const char *str)
{
    size_t idx_u32 = 0;
    size_t len_u32 = strlen(str);
    size_t max_start_u32 = 0;
    size_t max_len_u32 = 0;

    while (idx_u32 < len_u32)
    {
        // Пропустить пробелы
        while (idx_u32 < len_u32 && str[idx_u32] == ' ')
        {
            ++idx_u32;
        }

        if (idx_u32 == len_u32)
        {
            break;
        }

        size_t start_u32 = idx_u32;

        // Пройти по текущему слову
        while (idx_u32 < len_u32 && str[idx_u32] != ' ')
        {
            ++idx_u32;
        }

        size_t word_len_u32 = idx_u32 - start_u32;

        if (word_len_u32 > max_len_u32)
        {
            max_len_u32 = word_len_u32;
            max_start_u32 = start_u32;
        }
    }

    if (max_len_u32 > 0)
    {
        printf("%.*s\n", (int)max_len_u32, str + max_start_u32);
    }
}
