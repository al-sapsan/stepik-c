#include <stdio.h>

unsigned long long fact(int n); // прототип функции fact

int main(void)
{
    int number = 6;
    printf("%d\n", fact(number));
    return 0;
}

// Функция вычисления факториала (итеративный способ)
unsigned long long fact(int n) {
    if (n < 0) return -1; // Факториал отрицательного числа не определён
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}