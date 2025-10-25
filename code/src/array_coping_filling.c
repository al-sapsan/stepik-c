#include <stdio.h>

#define TOTAL   5

int main(void)
{
    // В соответствии с ТЗ.
    // Объявляем массивы нужной длины
    int ar_1[TOTAL];
    int ar_2[TOTAL * 2];

    // Считываем 5 целых чисел в ar_1
    for (int i = 0; i < TOTAL; ++i)
        scanf("%d", &ar_1[i]);

    // Копируем значения из ar_1 в ar_2
    for (int i = 0; i < TOTAL; ++i)
        ar_2[i] = ar_1[i];

    // Оставшиеся элементы ar_2 заполняем -1
    for (int i = TOTAL; i < TOTAL * 2; ++i)
        ar_2[i] = -1;
    /* Фривольный вариант
    // Считываем 5 целых чисел в ar_1 и сразу копируем в ar_2
    for (int i = 0; i < TOTAL; ++i) {
        scanf("%d", &ar_1[i]);
        ar_2[i] = ar_1[i];
    }

    // Оставшиеся элементы ar_2 заполняем -1
    for (int i = TOTAL; i < TOTAL * 2; ++i)
        ar_2[i] = -1;
    */

    return 0;
}