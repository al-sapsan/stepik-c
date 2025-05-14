#include <stdio.h>

int main(void)
{
    int n, sum1 = 0, sum2 = 0;
    scanf("%d", &n);

    // Суммируем последние три и первые три цифры в одном цикле
    for (int i = 0; i < 6; i++) {
        int digit = n % 10;
        if (i < 3)
            sum1 += digit;      // последние три цифры
        else
            sum2 += digit;      // первые три цифры
        n /= 10;
    }

    printf("%s\n", (sum1 == sum2) ? "yes" : "no");
    return 0;
}