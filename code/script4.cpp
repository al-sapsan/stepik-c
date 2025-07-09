/**
 * @file    count_digits_letters.c
 * @brief   Подсчёт цифр и букв в строке
 * @version 1.0
 * @date    2025-07-08
 */

/* === Core === */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* === Константы === */
#define MAXLEN 1000

/* === Прототипы функций === */
/**
 * @brief Подсчитывает количество цифр и букв в строке
 * @param[in]  buf_str  Входная строка
 * @param[out] p_cnt_digits  Указатель на счётчик цифр
 * @param[out] p_cnt_letters Указатель на счётчик букв
 */
void count_digits_and_letters(const char *buf_str, int *p_cnt_digits, int *p_cnt_letters);

/* === Функция main === */
int main(void)
{
    char buf_str[MAXLEN];
    int l_cnt_digits = 0;
    int l_cnt_letters = 0;

    /* Ввод строки с пробелами */
    fgets(buf_str, MAXLEN, stdin);

    /* Удаляем символ новой строки, если он есть */
    size_t l_len = strlen(buf_str);
    if (l_len > 0 && buf_str[l_len - 1] == '\n')
    {
        buf_str[l_len - 1] = '\0';
    }

    /* Подсчёт цифр и букв */
    count_digits_and_letters(buf_str, &l_cnt_digits, &l_cnt_letters);

    /* Вывод результата */
    char buf_out[32];
    sprintf(buf_out, "%d %d", l_cnt_digits, l_cnt_letters);
    puts(buf_out);

    return 0;
}

/* === Определения функций === */
void count_digits_and_letters(const char *buf_str, int *p_cnt_digits, int *p_cnt_letters)
{
    int l_idx = 0;
    *p_cnt_digits = 0;
    *p_cnt_letters = 0;

    while (buf_str[l_idx] != '\0')
    {
        if (isdigit((unsigned char)buf_str[l_idx]))
        {
            (*p_cnt_digits)++;
        }
        else if (isalpha((unsigned char)buf_str[l_idx]))
        {
            (*p_cnt_letters)++;
        }
        l_idx++;
    }
}
