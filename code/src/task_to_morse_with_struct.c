/*******************************************************************************
 * @file script2.c
 * @brief Кодирование строки в азбуке Морзе
 * @version 1.0
 * @date 2025-07-23
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

/*** Morse Code Table ***/
typedef struct
{
    char ch;
    const char *code;
} morse_t;

static const morse_t g_morse_table[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {' ', "-...-"}};
static const size_t g_morse_table_size = sizeof(g_morse_table) / sizeof(g_morse_table[0]);

/*** Function Prototype ***/
/**
 * @brief Encode string to Morse code
 * @param dst_str Строка для результата
 * @param src_str Исходная строка
 * @param table Таблица азбуки Морзе
 * @param table_size Размер таблицы
 * @details Кодирует строку в азбуке Морзе, разделяя коды пробелами
 */
void encode_morse(char *dst_str, const char *src_str, const morse_t *table, size_t table_size);

/*** Main Function ***/
int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';

    char morse[500] = {0};
    encode_morse(morse, str, g_morse_table, g_morse_table_size);
    printf("%s\n", morse);
    return 0;
}

/*** Function Implementation ***/
void encode_morse(char *dst_str, const char *src_str, const morse_t *table, size_t table_size)
{
    size_t pos = 0;
    for (size_t i = 0; src_str[i] != '\0'; ++i)
    {
        char ch = src_str[i];
        if (ch >= 'a' && ch <= 'z')
            ch -= 32;
        const char *code = NULL;
        for (size_t j = 0; j < table_size; ++j)
        {
            if (table[j].ch == ch)
            {
                code = table[j].code;
                break;
            }
        }
        if (code)
        {
            size_t k = 0;
            while (code[k] != '\0')
                dst_str[pos++] = code[k++];
            // Add space if not last character
            if (src_str[i + 1] != '\0')
                dst_str[pos++] = ' ';
        }
    }
    dst_str[pos] = '\0';
}
