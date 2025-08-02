/********************************************************************
 * @file    script6.c
 * @brief   Count words in a line from stdin (Stepik 8.3.5)
 * @version 1.0
 * @date    2025-08-01
 *
 * @note    Embedded/robotics C style
 ********************************************************************/

/*** Core ***/
#include <stdio.h>
#include <string.h>

/*** Constants ***/
#define BUFF_SIZE 512

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Считывает строку из stdin, считает количество слов
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    char buff_arr_i8[BUFF_SIZE];
    FILE *ptr_stream_FILE = stdin; // имитация отрытого файлового входного потока
    int word_count_i32 = 0;
    int in_word_b = 0;
    if (fgets(buff_arr_i8, BUFF_SIZE, ptr_stream_FILE) != NULL)
    {
        for (char *ptr_i8 = buff_arr_i8; *ptr_i8 != '\0'; ++ptr_i8)
        {
            if (*ptr_i8 != ' ' && *ptr_i8 != '\t' && *ptr_i8 != '\n')
            {
                if (!in_word_b)
                {
                    in_word_b = 1;
                    word_count_i32++;
                }
            }
            else
            {
                in_word_b = 0;
            }
        }
    }
    (void)printf("%d\n", word_count_i32);
    // fclose(ptr_stream_FILE); закрывать стандартный поток не нужно
    return 0;
}
