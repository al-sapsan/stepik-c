#include <stdio.h>

int main(void)
{
    int arr[10];
    int count = 0;
    // Считываем не более 10 чисел
    while (count < 10 && scanf("%d", &arr[count]) == 1)
        ++count;

    // Проверяем: все ли числа неотрицательны и нечетны
    int res = 1;
    for (int i = 0; i < count; ++i)
        res *= (arr[i] >= 0) * (arr[i] % 2);

    printf("%d\n", res);
    return 0;
}