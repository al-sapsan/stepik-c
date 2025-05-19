#include <stdio.h>

int main(void)
{
    short var_1;
    int var_2;
    long long var_3;

    // Считываем значения через запятую
    scanf("%hd, %d, %lld", &var_1, &var_2, &var_3);

    // Массив для хранения всех байтов (2 + 4 + 8 = 14)
    unsigned char arr[14];

    // Копируем байты var_1
    unsigned char *p1 = (unsigned char *)&var_1;
    for (int i = 0; i < sizeof(var_1); ++i)
        arr[i] = p1[i];

    // Копируем байты var_2
    unsigned char *p2 = (unsigned char *)&var_2;
    for (int i = 0; i < sizeof(var_2); ++i)
        arr[sizeof(var_1) + i] = p2[i];

    // Копируем байты var_3
    unsigned char *p3 = (unsigned char *)&var_3;
    for (int i = 0; i < sizeof(var_3); ++i)
        arr[sizeof(var_1) + sizeof(var_2) + i] = p3[i];

    // Выводим значения массива
    for (int i = 0; i < 14; ++i)
        printf("%u ", arr[i]);

    return 0;
}