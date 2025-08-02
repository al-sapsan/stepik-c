/********************************************************************
 * @file    script5.c
 * @brief   Read binary short array from stdin and print (Stepik 8.4.5)
 * @version 1.0
 * @date    2025-08-02
 *
 * @note    Embedded/robotics C style
 ********************************************************************/

/*** Core ***/
#include <stdio.h>

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Считывает массив short из бинарного потока stdin, выводит значения
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    short data_arr_i16[10] = {0};
    FILE *ptr_stream_FILE = stdin; // имитация входного потока
    size_t read_count = fread(data_arr_i16, sizeof(short), 10, ptr_stream_FILE);
    for (size_t i = 0; i < read_count; ++i)
    {
        if (i > 0)
        {
            (void)printf(" ");
        }
        (void)printf("%d", data_arr_i16[i]);
    }
    (void)putchar("\n");
    // fclose(ptr_stream_FILE);
    return 0;
}
