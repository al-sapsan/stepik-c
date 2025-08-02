/********************************************************************
 * @file    script4.c
 * @brief   Write short array to binary stream (Stepik 8.4.4)
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
 *         Записывает массив short в бинарный поток stdout
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    short data_arr_i16[] = {79 + 256 * 80, 81 + 256 * 82, 83 + 256 * 84, 85 + 256 * 86};
    FILE *ptr_stream_FILE = stdout; // имитация выходного потока
    (void)fwrite(data_arr_i16, sizeof(short), sizeof(data_arr_i16) / sizeof(short), ptr_stream_FILE);
    // fclose(ptr_stream_FILE);
    return 0;
}
