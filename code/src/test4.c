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