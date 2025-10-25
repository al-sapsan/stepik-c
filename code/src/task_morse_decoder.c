/**
 * @file morse_decoder.c
 * @brief Декодирование строки из азбуки Морзе
 * @version 1.0
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*** Morse Code Table ***/
/**
 * @brief Таблица кодов Морзе
 * @details Содержит коды для цифр (0-9), букв (A-Z) и пробела
 */
const char *morse[] = {
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", // 0-9
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",             // A-K
    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",              // L-V
    ".--", "-..-", "-.--", "--..", "-...-"                                                    // W-Z + space
};

/*** Function Prototypes ***/
/**
 * @brief Находит индекс кода Морзе в таблице
 * @param code Код Морзе для поиска
 * @return Индекс в таблице или -1 если не найден
 */
int find_morse_index(const char *code);

/**
 * @brief Декодирует строку из азбуки Морзе
 * @param output Буфер для результата
 * @param input Входная строка в коде Морзе
 * @details Преобразует коды Морзе в символы, разделенные пробелами
 */
void decode_morse(char *output, const char *input);

/*** Main Function ***/
int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';

    char result[100] = {0};
    decode_morse(result, str);
    printf("%s\n", result);

    return 0;
}

/*** Function Implementations ***/
int find_morse_index(const char *code)
{
    /** Поиск кода в таблице */
    for (int i = 0; i < 37; i++)
    {
        if (strcmp(code, morse[i]) == 0)
        {
            return i;
        }
    }
    return -1; /**< Код не найден */
}

void decode_morse(char *output, const char *input)
{
    char token[10] = {0}; /**< Буфер для текущего кода Морзе */
    int token_pos = 0;    /**< Позиция в буфере токена */
    int output_pos = 0;   /**< Позиция в выходном буфере */

    /** Обработка каждого символа входной строки */
    for (size_t i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ' || input[i + 1] == '\0')
        {
            /** Обработка конца токена */
            if (input[i + 1] == '\0' && input[i] != ' ')
            {
                token[token_pos++] = input[i];
            }

            /** Поиск кода в таблице */
            int index = find_morse_index(token);
            if (index >= 0)
            {
                /** Преобразование индекса в символ */
                if (index < 10)
                {
                    output[output_pos++] = '0' + index; /**< Цифры */
                }
                else if (index < 36)
                {
                    output[output_pos++] = 'A' + (index - 10); /**< Буквы */
                }
                else
                {
                    output[output_pos++] = ' '; /**< Пробел */
                }
            }

            /** Сброс буфера токена */
            memset(token, 0, sizeof(token));
            token_pos = 0;
        }
        else
        {
            /** Накопление символов токена */
            token[token_pos++] = input[i];
        }
    }
    output[output_pos] = '\0'; /**< Завершение строки */
}