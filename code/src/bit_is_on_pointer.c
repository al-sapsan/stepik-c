#include <stdio.h>

int main(void)
{
    int count;
    scanf("%d", &count);

    // Маска для включения 3-го и 0-го битов в каждом байте: 0b00001001 = 9
    unsigned char mask = (1 << 3) | (1 << 0);

    // Обрабатываем каждый байт переменной count
    unsigned char *ptr = (unsigned char *)&count;
    for (int i = 0; i < sizeof(count); i++) {
        ptr[i] |= mask;
    }

    printf("%d\n", count);
    return 0;
}