#include <stdio.h>

// Внешний массив pows объявлен вне main (например: float pows[] = {...};)
extern float pows[];
extern int pows_size; // Внешняя переменная с размером массива

int main(void)
{
    // Перебираем элементы массива pows в обратном порядке
    for (int i = pows_size - 1; i >= 0; --i) {
        printf("%.1f ", pows[i]); // Выводим элемент с точностью до десятых
    }

    return 0;
}