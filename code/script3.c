
/********************************************************************
 * @file    script3.c
 * @brief   Подсчет слов, содержащих фрагмент "ra" без учета регистра
 * @version 1.0
 * @date    2025-07-28
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*** Typedefs ***/
typedef int (*FUNC_CORRECT)(const char *str);

/*** Function Prototypes ***/
/**
 * @brief Проверяет, содержит ли строка фрагмент "ra" без учета регистра
 *
 * @param[in] str Входная строка
 * @return 1 — если содержит "ra", 0 — иначе
 */
int is_correct(const char *str);

/**
 * @brief Подсчитывает количество корректных слов по фильтру
 *
 * @param[in] words Массив слов
 * @param[in] count_words Количество слов
 * @param[in] filter Функция-фильтр
 * @return Количество корректных слов
 */
int get_correct_words(const char (*words)[50], int count_words, FUNC_CORRECT filter);

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0)
 */
int main(void)
{
    char words[20][50] = {{0}};
    int count_words = 0;
    while (count_words < 20 && scanf("%49s", words[count_words]) == 1)
        ++count_words;

    int result = get_correct_words(words, count_words, is_correct);
    printf("%d\n", result);
    return 0;
}

/*** Function Implementation ***/
int is_correct(const char *str)
{
    size_t len = strlen(str);
    for (size_t i = 0; i + 1 < len; ++i)
    {
        char c1 = tolower((unsigned char)str[i]);
        char c2 = tolower((unsigned char)str[i + 1]);
        if (c1 == 'r' && c2 == 'a')
            return 1;
    }
    return 0;
}

int get_correct_words(const char (*words)[50], int count_words, FUNC_CORRECT filter)
{
    int count = 0;
    for (int i = 0; i < count_words; ++i)
    {
        if (filter(words[i]))
            ++count;
    }
    return count;
}
