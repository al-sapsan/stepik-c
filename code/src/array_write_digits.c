#include <stdio.h>

int main(void)
{
    short ar_rnd[64] = {0}; // Объявляем и инициализируем массив нулями

    // Считываем 5 целых чисел и записываем их в первые 5 элементов массива
    for (int i = 0; i < 5; ++i)
        scanf("%hd", &ar_rnd[i]);

    return 0;
}