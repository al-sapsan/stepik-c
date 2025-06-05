#include <stdio.h>

/**
 * @brief Подсчитывает количество нечетных чисел среди шести введённых пользователем.
 *
 * @return 0 при успешном завершении
 */
int main() {
    int count = 0, i = 0, num;
    while (i < 6) {
        if (scanf("%d", &num) != 1) {
            printf("Input error.\n");
            return 0;
        }
        if (num % 2 != 0)
            count++;
        i++;
    }
    printf("%d\n", count);
    return 0;
}