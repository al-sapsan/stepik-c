#include <stdio.h>

int main(void)
{
    int n;

    // Считываем натуральное число
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input error\n");
        return 0;
    }

    // Находим и выводим все делители числа n
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}