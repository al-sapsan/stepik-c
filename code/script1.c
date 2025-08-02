/********************************************************************
 * @file    script1.c
 * @brief   Read and print positive doubles from stdin (Stepik 8.3.7)
 * @version 1.0
 * @date    2025-08-02
 *
 * @note    Embedded/robotics C style
 ********************************************************************/

/*** Core ***/
#include <stdio.h>

/*** Constants ***/
enum
{
    max_length_ar = 20
};

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Считывает не более 20 вещественных чисел из stdin,
 *         выводит только положительные значения с точностью до сотых
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    double temp_arr_f64[max_length_ar];
    FILE *ptr_stream_FILE = stdin; // имитация отрытого файлового потока
    int count_i32 = 0;
    // Считываем не более max_length_ar чисел
    while (count_i32 < max_length_ar && fscanf(ptr_stream_FILE, "%lf", &temp_arr_f64[count_i32]) == 1)
    {
        count_i32++;
    }
    int first_b = 1;
    for (int i = 0; i < count_i32; ++i)
    {
        if (temp_arr_f64[i] > 0.0)
        {
            if (!first_b)
            {
                (void)printf(" ");
            }
            else
            {
                first_b = 0;
            }
            (void)printf("%.2f", temp_arr_f64[i]);
        }
    }
    (void)printf("\n");
    // fclose(ptr_stream_FILE); закрывать стандартный поток не нужно
    return 0;
}
