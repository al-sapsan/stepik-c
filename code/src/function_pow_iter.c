#include <stdio.h>

int pow_n(int n, int m); // прототип функции pow_n

int main(void)
{
    printf("%d\n", pow_n(2, 4)); // 2^4 = 16
    return 0;
}

// Функция pow_n принимает два целых числа n и m и возвращает n в степени m
int pow_n(int n, int m) // функция pow_n
{
    int result = 1; // начальное значение результата
    for (int i = 0; i < m; i++) // цикл от 0 до m-1
    {
        result *= n; // умножаем результат на n
    }
    return result; // возвращаем результат
}