#include <stdio.h>

/**
 * @brief Определяет действие по знаку операции.
 *
 * Пользователь вводит символ операции (+, -, *, /).
 * Программа выводит название действия или "Неизвестная операция" для других символов.
 *
 * @return 0 при успешном завершении
 */
int main() {
    char op;
    if (scanf(" %c", &op) != 1) {
        printf("Неизвестная операция\n");
        return 0;
    }

    switch (op) {
        case '+':
            printf("Сложение\n");
            break;
        case '-':
            printf("Вычитание\n");
            break;
        case '*':
            printf("Умножение\n");
            break;
        case '/':
            printf("Деление\n");
            break;
        default:
            printf("Неизвестная операция\n");
    }
    return 0;
}