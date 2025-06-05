#include <stdio.h>

/**
 * @brief Простой калькулятор для выполнения операций +, -, *, /
 *
 * Пользователь вводит два целых числа и знак операции.
 * В случае деления на ноль или неизвестной операции выводится сообщение об ошибке.
 *
 * @return 0 при успешном завершении
 */
int main() {
    int a, b, res;
    char op;
    int flag = 1; ///< признак вывода результата

    printf("\nВведите 1й операнд : ");
    scanf("%d", &a);
    printf("\nВведите знак операции : ");
    scanf(" %c", &op); // пробел перед %c для пропуска пробелов/переводов строки
    printf("\nВведите 2й операнд : ");
    scanf("%d", &b);

    switch (op) {
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a * b; break;
        case '/':
            if (b != 0)
                res = a / b;
            else {
                printf("Деление на 0 невозможно!\n");
                flag = 0;
            }
            break;
        default:
            printf("\nНеизвестная операция\n");
            flag = 0;
    }
    if (flag)
        printf("\nРезультат : %d\n", res);

    return 0;
}