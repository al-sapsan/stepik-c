#include <stdio.h>

/**
 * @brief Демонстрация трёх способов суммирования 10 чисел: while, for, do-while.
 *
 * Каждый способ выводит результат с подписью, соответствующей использованному циклу.
 *
 * @return 0 при успешном завершении
 */
int main() {
    int x, sum, k;

    // Сумма с помощью while
    sum = 0;
    k = 0;
    while (k < 10) {
        scanf("%d", &x);
        sum += x;
        k++;
    }
    printf("Сумма чисел (while) = %d\n", sum);

    // Сумма с помощью for
    sum = 0;
    for (k = 0; k < 10; k++) {
        scanf("%d", &x);
        sum += x;
    }
    printf("Сумма чисел (for) = %d\n", sum);

    // Сумма с помощью do-while
    sum = 0;
    k = 0;
    do {
        scanf("%d", &x);
        sum += x;
        k++;
    } while (k < 10);
    printf("Сумма чисел (do-while) = %d\n", sum);

    return 0;
}
