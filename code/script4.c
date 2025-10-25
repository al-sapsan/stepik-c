#include <stdio.h>

/**
 * @brief Для целого числа возвращает количество цифр и процент чётных цифр.
 * 
 * @param n Входное число
 * @param digits Указатель для записи количества цифр
 * @param percent_even Указатель для записи процента чётных цифр (целое число)
 */
void digit_stats(int n, int *digits, int *percent_even) {
    int count = 0, even = 0, x = n < 0 ? -n : n;
    if (x == 0) {
        *digits = 1;
        *percent_even = 100;
        return;
    }
    while (x != 0) {
        int d = x % 10;
        if (d % 2 == 0) even++;
        count++;
        x /= 10;
    }
    *digits = count;
    *percent_even = (even * 100 + count / 2) / count; // округление до целого
}

int main() {
    int n, digits, percent;
    scanf("%d", &n);
    digit_stats(n, &digits, &percent);
    printf("%d %d%%\n", digits, percent);
    return 0;
}