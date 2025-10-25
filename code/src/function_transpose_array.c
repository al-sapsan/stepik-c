#include <stdio.h>

#define SIZE    4

void transpose(short arr[SIZE][SIZE]); // прототип

int main(void)
{
    // Объявление и инициализация матрицы нулями
    short matrix[SIZE][SIZE] = {0};

    // Заполнение матрицы числами с клавиатуры
    short* ptr = &matrix[0][0];
    int count = 0;
    while(count < SIZE * SIZE && scanf("%hd", ptr) == 1) {
        ptr++;
        count++;
    }

    // Транспонирование матрицы
    transpose(matrix);

    // Вывод результата
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%hd", matrix[i][j]);
            if (j < SIZE - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}

void transpose(short arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = i + 1; j < SIZE; ++j) {
            short tmp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = tmp;
        }
    }
}