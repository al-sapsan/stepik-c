/**
 * @file    word_filter.c
 * @brief   Print words from input string that start with a given character
 * @version 1.0
 * @date    2025-07-16
 * @note    Console input; case-sensitive match
 */

#include <stdio.h>  /* Core: printf, fgets, getchar */
#include <string.h> /* Core: strlen */
#include <ctype.h>  /* Core: isspace */

/*** Constants ***/
static const size_t MAX_STR_LEN = 129;

/*** Function Prototypes ***/

/**
 * @brief Выводит слова, начинающиеся с заданного символа
 *
 * @param[in] p_str   Указатель на входную строку (нуль-терминированная)
 * @param[in] ch_cmp  Символ, с которого должно начинаться слово
 *
 * @return Нет возвращаемого значения
 */
void print_words_starting_with(const char *p_str, char ch_cmp);

/*** Main Function ***/

int main(void)
{
    char input_str[MAX_STR_LEN];
    char target_ch;
    size_t len_u32 = 0U;

    /* Считать входную строку из стандартного ввода */
    if (fgets(input_str, MAX_STR_LEN, stdin) != NULL)
    {
        len_u32 = strlen(input_str);

        /* Удалить завершающий символ новой строки, если он есть */
        if ((len_u32 > 0U) && (input_str[len_u32 - 1] == '\n'))
        {
            input_str[len_u32 - 1] = '\0';
        }

        /* Считать символ для сравнения */
        target_ch = getchar();

        /* Пропустить символ новой строки после ввода символа, если он есть */
        if (target_ch == '\n')
        {
            target_ch = getchar();
        }

        /* Вызвать функцию для вывода слов */
        print_words_starting_with(input_str, target_ch);
    }

    return 0;
}

/*** Function Definitions ***/

void print_words_starting_with(const char *p_str, char ch_cmp)
{
    int idx = 0;
    int start = 0;
    int str_len = (int)strlen(p_str);

    while (idx < str_len)
    {
        /* Пропустить ведущие пробелы */
        while ((idx < str_len) && isspace((unsigned char)p_str[idx]))
        {
            idx++;
        }

        if (idx >= str_len)
        {
            break;
        }

        /* Проверить, начинается ли слово с нужного символа */
        if (p_str[idx] == ch_cmp)
        {
            start = idx;

            while ((idx < str_len) && !isspace((unsigned char)p_str[idx]))
            {
                idx++;
            }

            printf("%.*s\n", idx - start, &p_str[start]);
        }
        else
        {
            /* Пропустить слово, которое не соответствует */
            while ((idx < str_len) && !isspace((unsigned char)p_str[idx]))
            {
                idx++;
            }
        }
    }
}
