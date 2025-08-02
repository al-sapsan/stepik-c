/********************************************************************
 * @file    script3.c
 * @brief   Read lines from stdin and print (Stepik 8.4.3)
 * @version 1.0
 * @date    2025-08-02
 *
 * @note    Embedded/robotics C style
 ********************************************************************/

/*** Core ***/
#include <stdio.h>
#include <string.h>

/*** Constants ***/
enum
{
    max_lines = 10,
    max_string_len = 200
};

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Считывает строки из stdin, сохраняет в массиве, выводит без символа перевода строки
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    char text_arr_i8[max_lines][max_string_len];
    FILE *ptr_stream_FILE = stdin; // имитация отрытого файлового потока
    int line_count_i32 = 0;
    while (line_count_i32 < max_lines && fgets(text_arr_i8[line_count_i32], max_string_len, ptr_stream_FILE) != NULL)
    {
        size_t len = strlen(text_arr_i8[line_count_i32]);
        if (len > 0 && text_arr_i8[line_count_i32][len - 1] == '\n')
        {
            text_arr_i8[line_count_i32][len - 1] = '\0';
        }
        line_count_i32++;
    }
    for (int i = 0; i < line_count_i32; ++i)
    {
        (void)printf("%s\n", text_arr_i8[i]);
    }
    // fclose(ptr_stream_FILE); закрывать стандартный поток не нужно
    return 0;
}
