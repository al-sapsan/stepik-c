/*******************************************************************************
 * @file script2.c
 * @brief Кодирование строки в азбуке Морзе
 * @version 1.0
 * @date 2025-07-23
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*** Morse Code Tables ***/
/** @brief Массив символов, поддерживаемых кодировкой */
static const char g_morse_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

/** @brief Массив кодов Морзе, соответствующих символам из g_morse_chars */
static const char *g_morse_codes[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
    "-...-"};

/** @brief Количество элементов в таблице кодов Морзе */
static const size_t g_morse_table_size = sizeof(g_morse_codes) / sizeof(g_morse_codes[0]);

/*** Function Prototype ***/
/**
 * @brief Кодирует строку в азбуке Морзе
 * @param dst_str Буфер для записи результата (кода Морзе)
 * @param src_str Исходная строка для кодирования
 * @details Преобразует каждый символ входной строки в соответствующий код Морзе,
 *          разделяя коды пробелами. Регистр символов не имеет значения.
 */
void encode_morse(char *dst_str, const char *src_str);

/*** Main Function ***/
int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';

    char morse[500] = {0};
    encode_morse(morse, str);
    printf("%s\n", morse);
    return 0;
}

/*** Function Implementation ***/
void encode_morse(char *dst_str, const char *src_str)
{
    size_t pos = 0; /**< Текущая позиция в буфере назначения */

    /* Обрабатываем каждый символ входной строки */
    for (size_t i = 0; src_str[i] != '\0'; ++i)
    {
        /* Приводим символ к верхнему регистру */
        char ch = toupper(src_str[i]);
        const char *code = NULL;

        /* Ищем символ в таблице соответствия */
        for (size_t j = 0; j < g_morse_table_size; ++j)
        {
            if (g_morse_chars[j] == ch)
            {
                code = g_morse_codes[j];
                break;
            }
        }

        /* Если символ найден в таблице, добавляем его код */
        if (code)
        {
            /* Копируем код Морзе в буфер назначения */
            strcpy(dst_str + pos, code);
            pos += strlen(code);

            /* Добавляем пробел, если это не последний символ */
            if (src_str[i + 1] != '\0')
                dst_str[pos++] = ' ';
        }
    }
    dst_str[pos] = '\0'; /**< Завершаем строку нуль-терминатором */
}