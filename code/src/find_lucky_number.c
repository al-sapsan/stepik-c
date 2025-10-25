#include <stdio.h>
/**
 * @brief Проверяет, является ли шестизначное число "счастливым".
 *
 * Если число не шестизначное, выводится "ERROR".
 *
 * @return 0 при успешном завершении
 */
int main() {
    int n;
    if (scanf("%d", &n) != 1 || n < 100000 || n > 999999) {
        printf("ERROR\n");
        return 0;
    }
    int sum1 = n/100000 + (n/10000)%10 + (n/1000)%10;
    int sum2 = (n/100)%10 + (n/10)%10 + n%10;
    printf("%s\n", (sum1 == sum2) ? "YES" : "NO");
    return 0;
}

/*
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
    */
