/**
 * @file   string_processor.c
 * @brief  Обработка строки: удаление лишних пробелов и нормализация пробелов между словами
 * @version 1.0
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 256

/**
 * @brief Главная функция программы
 *
 * Считывает строку с входа, удаляет ведущие, конечные и лишние внутренние пробелы,
 * выводит результат в формате: |строка|
 *
 * @return int Код возврата (0 — успешное завершение)
 */
int main(void)
{
    char str[MAXLEN];
    char result[MAXLEN];
    char *word = NULL;

    result[0] = '\0';

    if (fgets(str, sizeof(str), stdin) == NULL)
    {
        return 1;
    }

    // Удаление символа новой строки
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }

    // Получение первого слова
    word = strtok(str, " ");
    if (word == NULL)
    {
        printf("||\n");
        return 0;
    }

    // Копирование первого слова в результат
    strcpy(result, word);

    // Обработка остальных слов
    while ((word = strtok(NULL, " ")) != NULL)
    {
        strcat(result, " ");
        strcat(result, word);
    }

    // Вывод результата
    printf("|%s|\n", result);

    return 0;
}
