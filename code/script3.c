/*******************************************************************************
 * @file    script_csv_parser.c
 * @brief   Извлечение чисел из строки формата CSV с префиксом
 * @version 1.0
 * @date    2025-07-18
 ******************************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*** Function Prototypes ***/

/**
 * @brief Извлекает числа из строки формата "csv: a; b; c"
 * @param[out] ptr_array_f64  Указатель на массив для записи чисел
 * @param[in]  max_count      Максимальное количество чисел
 * @param[in]  ptr_str        Входная строка
 * @return Количество успешно извлечённых чисел
 */
int get_data_csv(double *ptr_array_f64, int max_count, const char *ptr_str);

/*** Main Function ***/

/**
 * @brief Точка входа в программу
 * @return Код завершения
 */
int main(void)
{
    char str_input[100] = {0};
    fgets(str_input, sizeof(str_input) - 1, stdin);

    // Удаляем символ новой строки, если есть
    char *ptr_newline = strrchr(str_input, '\n');
    if (ptr_newline != NULL)
    {
        *ptr_newline = '\0';
    }

    double values_f64[20] = {0.0};
    int count_values = get_data_csv(values_f64, 20, str_input);

    for (int idx = 0; idx < count_values; ++idx)
    {
        printf("%.2f", values_f64[idx]);
        if (idx < count_values - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

/*** Function Implementation ***/

int get_data_csv(double *ptr_array_f64, int max_count, const char *ptr_str)
{
    int count = 0;
    const char *ptr_prefix = "csv: ";
    const char *ptr_current = ptr_str;

    // Проверка префикса
    if (strncmp(ptr_current, ptr_prefix, strlen(ptr_prefix)) != 0)
    {
        return 0;
    }

    ptr_current += strlen(ptr_prefix);

    // Пропуск пробелов
    while (*ptr_current == ' ')
    {
        ++ptr_current;
    }

    // Разбор чисел
    char *ptr_end = NULL;
    while (*ptr_current != '\0' && count < max_count)
    {
        double value = strtod(ptr_current, &ptr_end);
        if (ptr_current == ptr_end)
        {
            break; // Не удалось считать число
        }

        ptr_array_f64[count++] = value;
        ptr_current = ptr_end;

        while (*ptr_current == ' ')
        {
            ++ptr_current;
        }

        if (*ptr_current == ';')
        {
            ++ptr_current;
            while (*ptr_current == ' ')
            {
                ++ptr_current;
            }
        }
        else
        {
            break; // Нет разделителя — конец
        }
    }

    return count;
}
