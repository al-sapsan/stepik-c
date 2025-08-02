/********************************************************************
 * @file    script7.c
 * @brief   Format and print rectangle dimensions (Stepik 8.3.6)
 * @version 1.0
 * @date    2025-08-01
 *
 * @note    Embedded/robotics C style
 ********************************************************************/

/*** Core ***/
#include <stdio.h>

/*** Constants ***/
#define BUFF_SIZE 512

/*** Main Function ***/
int main(void)
{
    char buff_arr_i8[BUFF_SIZE];
    int w_i32, h_i32;
    FILE *ptr_stream_FILE = stdout; // имитация отрытого файлового потока
    if (scanf("%d %d", &w_i32, &h_i32) == 2)
    {
        (void)sprintf(buff_arr_i8, "rectangle: %d; %d", w_i32, h_i32);
        (void)fputs(buff_arr_i8, ptr_stream_FILE);
    }
    // fclose(ptr_stream_FILE); закрывать стандартный поток не нужно
    return 0;
}
