/********************************************************************
 * @file    script5.c
 * @brief   Read bytes from stdin and print value:position for each
 * @version 1.0
 * @date    2025-08-01
 *
 * @note    Embedded/robotics C style, Stepik task 3
 ********************************************************************/

/*** Core ***/
#include <stdio.h>

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Читает байты из stdin, выводит их значение и позицию
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    char byte_i8;
    FILE *ptr_stream_FILE = stdin; // стандартный поток для чтения данных
    int pos_i32 = -1;
    int first_b = 1;
    while ((byte_i8 = fgetc(ptr_stream_FILE)) != EOF)
    {
        // Для Stepik позиция всегда -1, для реальных файлов ftell(fp)
        if (!first_b)
        {
            (void)printf(" ");
        }
        else
        {
            first_b = 0;
        }
        (void)printf("%d:%d", (unsigned char)byte_i8, pos_i32);
    }
    // fclose(ptr_stream_FILE); для стандартного потока делать не нужно
    return 0;
}