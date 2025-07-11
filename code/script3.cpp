/**
 * @file    extract_codeword.cpp
 * @brief   Извлекает части кодового слова из строк по разделителям
 * @version 1.0
 */

#include <cstdio>
#include <cstring>

/** @brief Извлекает подстроку между двумя символами ';' и добавляет в результат
 *  @param[in]  str     Входная строка
 *  @param[out] result  Буфер для результата (накопительный)
 */
void extract_part(const char *str, char *result);

// === main ===

int main()
{
    constexpr int MAXLEN = 256;
    char l_str1[MAXLEN] = {};
    char l_str2[MAXLEN] = {};
    char l_str3[MAXLEN] = {};
    char l_code_word[MAXLEN] = {}; // Пустая строка

    // Ввод трёх строк
    fgets(l_str1, MAXLEN, stdin);
    fgets(l_str2, MAXLEN, stdin);
    fgets(l_str3, MAXLEN, stdin);

    // Удаление символов новой строки
    l_str1[strcspn(l_str1, "\n")] = '\0';
    l_str2[strcspn(l_str2, "\n")] = '\0';
    l_str3[strcspn(l_str3, "\n")] = '\0';

    // Извлечение частей кодового слова
    extract_part(l_str1, l_code_word);
    extract_part(l_str2, l_code_word);
    extract_part(l_str3, l_code_word);

    // Вывод результата
    puts(l_code_word);

    return 0;
}

// === Function Definitions ===

void extract_part(const char *s_str, char *s_result)
{
    const char *l_start = strchr(s_str, ';');

    if (l_start != nullptr)
    {
        const char *l_end = strchr(l_start + 1, ';');
        if (l_end != nullptr)
        {
            strncat(s_result, l_start + 1, l_end - l_start - 1);
        }
    }
}
