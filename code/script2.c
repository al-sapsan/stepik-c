/********************************************************************
 * @file    script2.c
 * @brief   Read BOX struct and print formatted output (Stepik 8.3.8)
 * @version 1.0
 * @date    2025-08-02
 *
 * @note    Embedded/robotics C style
 ********************************************************************/

/*** Core ***/
#include <stdio.h>

/*** Typedefs ***/
typedef struct
{
    unsigned int id_u32;
    unsigned int width_u32;
    unsigned int height_u32;
    unsigned int depth_u32;
    double weight_f64;
} BOX_t;

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Считывает структуру BOX из stdin, выводит форматированные габариты
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    BOX_t box_st;
    FILE *ptr_stream_FILE = stdout; // имитация отрытого файлового потока
    // Чтение данных через ;
    if (scanf("%u; %u; %u; %u; %lf", &box_st.id_u32, &box_st.width_u32, &box_st.height_u32, &box_st.depth_u32, &box_st.weight_f64) == 5)
    {
        (void)fprintf(ptr_stream_FILE, "box %u: %u x %u x %u\n", box_st.id_u32, box_st.width_u32, box_st.height_u32, box_st.depth_u32);
    }
    // fclose(ptr_stream_FILE); закрывать стандартный поток не нужно
    return 0;
}
