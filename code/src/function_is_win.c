#include <stdio.h>

#define SIZE    3

int is_win(char arr[SIZE][SIZE]); // прототип

int main(void)
{
    char pole[SIZE][SIZE] = {0};
    char* ptr_p = &pole[0][0];
    int count = 0;
    while(count < SIZE * SIZE && scanf("%d", ptr_p) == 1) {
        *ptr_p = (*ptr_p == 1) ? 'x' : (*ptr_p == 2) ? 'o': 0;
        ptr_p++;
        count++;
    }

    int status = is_win(pole);
    printf("%d\n", status);

    return 0;
}

int is_win(char arr[SIZE][SIZE]) {
    // Проверка строк и столбцов
    for (int i = 0; i < SIZE; ++i) {
        // Строка
        if (arr[i][0] && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
            if (arr[i][0] == 'x') return 1;
            if (arr[i][0] == 'o') return 2;
        }
        // Столбец
        if (arr[0][i] && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {
            if (arr[0][i] == 'x') return 1;
            if (arr[0][i] == 'o') return 2;
        }
    }
    // Диагонали
    if (arr[0][0] && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
        if (arr[0][0] == 'x') return 1;
        if (arr[0][0] == 'o') return 2;
    }
    if (arr[0][2] && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
        if (arr[0][2] == 'x') return 1;
        if (arr[0][2] == 'o') return 2;
    }
    // Проверка на незаполненные клетки
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (arr[i][j] == 0)
                return 0; // игра не окончена

    return 3; // ничья
} 
/*
Продолжите программу. Объявите функцию с именем is_win, которой передается 
двумерный массив типа char размером SIZE x SIZE элементов. Функция is_win 
должна проверять и возвращать статус переданного игрового поля игры 
"Крестики-нолики" в виде целого числа:
0 - игра не окончена;
1 - выиграли "крестики";
2 - выиграли "нолики";
3 - ничья.
Каждый элемент переданного двумерного массива хранит либо символ 'x', либо 
символ 'o', либо целое число 0, если клетка свободна.
В функции main вызовите функцию is_win для массива pole. Выведите в консоль 
вычисленный статус игрового поля в виде целого числа.

Sample Input:
1 0 0
0 1 2
2 0 1
Sample Output:
1
*/