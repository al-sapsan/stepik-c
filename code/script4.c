/**
 * @file main.c
 * @brief Сортировка символов строки с приоритетом цифр
 * @version 1.0
 * @date 2025-07-18
 * @author —
 */

#include <stdio.h>
#include <string.h>

/*** Comparison Function ***/

/**
 * @brief Match function for sorting
 * @param[in] a первый символ
 * @param[in] b второй символ
 * @return 1, если a < b с учетом приоритета цифр, иначе 0
 * @details Цифры всегда идут перед буквами; остальное — по алфавиту
 */
int match_ab(const char a, const char b)
{
    int a_is_digit = (a >= '0' && a <= '9');
    int b_is_digit = (b >= '0' && b <= '9');

    if (a_is_digit && !b_is_digit)
    {
        return 1;
    }
    if (!a_is_digit && b_is_digit)
    {
        return 0;
    }
    return (a < b);
}

/*** Sort Function ***/

/**
 * @brief Sorts string characters by criteria
 * @param[in,out] str Строка для сортировки
 * @param[in] max_len Максимальная длина строки
 * @param[in] cmp Функция сравнения
 * @details Сортирует только символы строки до '\0', не весь массив
 */
void sort_string(char *str, size_t max_len, int (*cmp)(const char, const char))
{
    size_t len = strnlen(str, max_len);

    for (size_t i = 0; i < len; ++i)
    {
        for (size_t j = i + 1; j < len; ++j)
        {
            if (cmp(str[j], str[i]))
            {
                char tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
}

/*** Main Function ***/

/**
 * @brief Точка входа в программу
 * @return 0 при успешном завершении
 * @details Считывает строку, удаляет символ новой строки, сортирует и выводит результат
 */
int main(void)
{
    char str[100] = {0};

    fgets(str, sizeof(str) - 1, stdin);

    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
    {
        *ptr_n = '\0';
    }

    sort_string(str, sizeof(str) - 1, match_ab);

    printf("%s\n", str);

    return 0;
}
