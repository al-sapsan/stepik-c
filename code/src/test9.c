#include <stdio.h>

/**
 * @brief Находит максимум из последовательности целых чисел, введённых с клавиатуры.
 *
 * Сначала вводится количество чисел, затем сами числа через пробел.
 * Программа выводит максимальное из введённых чисел.
 *
 * @return 0 при успешном завершении
 */
int main() {
    int n, num, max;
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Input error.\n");
        return 0;
    }
    // Ввод первого числа и инициализация максимума
    if (scanf("%d", &max) != 1) {
        printf("Input error.\n");
        return 0;
    }
    for (int i = 1; i < n; i++) {
        if (scanf("%d", &num) != 1) {
            printf("Input error.\n");
            return 0;
        }
        if (num > max)
            max = num;
    }
    printf("%d\n", max);
    return 0;
}