#include <stdio.h>

int main(void)
{
    int n, m;

    // Считываем два целых числа
    if (scanf("%d %d", &n, &m) != 2 || n >= m) {
        printf("Input error\n");
        return 0;
    }

    // Находим первое четное число в диапазоне [n; m]
    if (n % 2 != 0) {
        n++;
    }

    // Выводим все четные числа в диапазоне [n; m]
    for (int i = n; i <= m; i += 2) {
        printf("%d ", i);
    }

    printf("\n");
    return 0;
}