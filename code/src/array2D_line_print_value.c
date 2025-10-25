#include <stdio.h>

#define ROWS 3
#define COLS 3

int main(void) 
{
    char line_array[ROWS * COLS] = {1, 2, 3, 
                                    4, 5, 6, 
                                    7, 8, 9};

    // Доступ к элементу (1, 2) — строка 1, столбец 2
    char x = line_array[1 * COLS + 2]; // x = 6
    printf("Element (1,2) = %d\n", x);

    // Распечатка массива построчно (имитация 2D)
    printf("\nArray contents:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", line_array[i * COLS + j]);
        }
        printf("\n");
    }

    return 0;
}

/* Предполагается, что:
line_array — это одномерный массив (char line_array[M * N]), 
эмулирующий 2D-массив размера M×N
i — номер строки (от 0 до M-1)
j — номер столбца (от 0 до N-1)
* Как это работает
Формула i * N + j преобразует 2D-координаты (i,j) в линейный индекс:
i * N — смещение до начала нужной строки (каждая строка содержит N элементов)
+ j — смещение до нужного столбца в строке
*/