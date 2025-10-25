#include <stdio.h>

int main(void)
{
    unsigned int number; // Переменная для хранения неотрицательного числа

    // Считываем число из входного потока
    if (scanf("%u", &number) != 1) {
        printf("Input error.\n"); // Если ввод некорректен
        return 0;
    }

    // Выполняем целочисленное деление на 4 с использованием сдвига вправо
    unsigned int result = number >> 2;

    // Выводим результат
    printf("%u\n", result);

    return 0;
}