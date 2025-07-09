/**
 * @file semicolon_replace.cpp
 * @brief Replaces all semicolons in a string with `.` and inserts `,` after each
 * @version 1.1
 * @date 2025-07-08
 */

#include <iostream>
#include <cstring>
#include <cstdio>

/*** Прототипы функций ***/

/**
 * @brief Вставляет символ в строку по указанной позиции
 * @param[in,out] str Строка, в которую вставляется символ
 * @param[in] c Символ, который нужно вставить
 * @param[in] ptr Указатель на позицию вставки
 */
void insert(char *str, char c, char *ptr);

/*** Главная функция ***/

int main()
{
    constexpr int MAXLEN = 101; // 100 символов + '\0'
    char mystring[MAXLEN];

    std::fgets(mystring, MAXLEN, stdin); // Ввод строки с пробелами

    // Удаляем символ новой строки, если он есть
    std::size_t len = std::strlen(mystring);
    if (len > 0 && mystring[len - 1] == '\n')
    {
        mystring[len - 1] = '\0';
    }

    char *ptr = mystring; // Указатель на начало строки

    while (*ptr != '\0')
    {
        if (*ptr == ';')
        {
            *ptr = '.';                     // Заменяем ';' на '.'
            insert(mystring, ',', ptr + 1); // Вставляем ',' после '.'
            ptr++;                          // Пропускаем вставленную запятую
        }
        ptr++; // Следующий символ
    }

    puts(mystring);
    return 0;
}

/*** Реализация функций ***/

void insert(char *str, char c, char *ptr)
{
    char *q = str + std::strlen(str); // Указатель на '\0'

    while (q >= ptr)
    {
        *(q + 1) = *q; // Сдвигаем символы вправо
        q--;
    }

    *ptr = c; // Вставляем символ
}
