#include <stdio.h>

/**
 * @brief Сравнивает средние баллы двух команд и выводит результат.
 *
 * Ввод: 2 оценки первой команды, затем 4 оценки второй команды.
 * Вывод: "First", если средний балл первой команды больше,
 *        "Second", если больше у второй,
 *        "Draw", если средние баллы равны.
 *
 * @return 0 при успешном завершении
 */
int main() {
    int a1, a2, b1, b2, b3, b4;

    // Ввод баллов обеих команд
    if (scanf("%d %d %d %d %d %d", &a1, &a2, &b1, &b2, &b3, &b4) != 6) {
        printf("Input error.\n");
        return 0;
    }

    double avg1 = (a1 + a2) / 2.0;
    double avg2 = (b1 + b2 + b3 + b4) / 4.0;

    if (avg1 > avg2)
        printf("First\n");
    else if (avg2 > avg1)
        printf("Second\n");
    else
        printf("Draw\n");

    return 0;
}