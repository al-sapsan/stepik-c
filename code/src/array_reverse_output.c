#include <stdio.h>

int main(void)
{
    const int total = 5;      // Константная переменная total
    int marks[100];           // Массив для хранения чисел

    // Считываем total целых чисел
    for (int i = 0; i < total; ++i)
        scanf("%d", &marks[i]);

    // Выводим числа в обратном порядке
    for (int i = total - 1; i >= 0; --i)
        printf("%d ", marks[i]);

    return 0;
}