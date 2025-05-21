#include <stdio.h>

#define ROWS 3
#define COLS 3
#define TOTAL_ELEMENTS (ROWS * COLS)
#define AR2D(i, j) ar_linear[(i) * COLS + (j)] // Для обратного преобразования (имитация двумерного доступа)
// Пример использования:
// int val = AR2D(1, 2); // Эквивалент ar_2D[1][2]

int main(void)
{
    int ar_linear[TOTAL_ELEMENTS]; // Линейный массив вместо двумерного

    // Считываем 9 целых чисел в линейный массив
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // Вычисляем линейный индекс
            int index = i * COLS + j;
            scanf("%d", &ar_linear[index]);
        }
    }

    // Пример доступа к элементу [1][2] в линейном массиве:
    // int element = ar_linear[1 * COLS + 2];

    return 0;
}