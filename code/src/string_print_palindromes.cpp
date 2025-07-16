
/**
 * @file    print_palindromes.cpp
 * @brief   Выводит все слова-палиндромы из строки
 * @version 1.0
 * @date    2025-07-16
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

/*** Constants ***/
static const size_t MAX_STR_LEN = 129;

/*** Function Prototypes ***/

/**
 * @brief Проверяет, является ли слово палиндромом (регистр не учитывается)
 * @param[in] word Слово
 * @param[in] len Длина слова
 * @return 1 если палиндром, 0 иначе
 */
int is_palindrome(const char *word, size_t len);

/**
 * @brief Выводит все слова-палиндромы из строки
 * @param[in] str Входная строка
 */
void print_palindromes(const char *str);

/*** Main Function ***/
int main(void)
{
    char input[MAX_STR_LEN];
    fgets(input, MAX_STR_LEN, stdin);
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
        input[len - 1] = '\0';

    // Создать копию строки в нижнем регистре
    char lower[MAX_STR_LEN];
    for (size_t i = 0; i <= len; ++i)
        lower[i] = (char)tolower((unsigned char)input[i]);

    print_palindromes(lower);
    return 0;
}

/*** Function Definitions ***/
int is_palindrome(const char *word, size_t len)
{
    for (size_t i = 0, j = len ? len - 1 : 0; i < j; ++i, --j)
    {
        if (tolower((unsigned char)word[i]) != tolower((unsigned char)word[j]))
            return 0;
    }
    return 1;
}

void print_palindromes(const char *str)
{
    size_t i = 0, n = strlen(str);
    while (i < n)
    {
        // Пропустить пробелы
        while (i < n && str[i] == ' ')
            ++i;
        if (i == n)
            break;
        size_t start = i;
        while (i < n && str[i] != ' ')
            ++i;
        size_t end = i;
        if (end > start)
        {
            if (is_palindrome(str + start, end - start))
            {
                printf("%.*s\n", (int)(end - start), str + start);
            }
        }
    }
}
