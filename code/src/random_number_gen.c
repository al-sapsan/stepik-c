#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL)); // Инициализация генератора случайных чисел

    int N;
    // Считываем значение N
    if (scanf("%d", &N) != 1 || N < 0 || N > RAND_MAX) {
        printf("Input error.\n"); // Проверка корректности ввода
        return 0;
    }

    // Генерация случайных чисел и сохранение их в разные переменные
    int random1 = rand() % (N + 1);
    int random2 = rand() % (N + 1);
    int random3 = rand() % (N + 1);
    int random4 = rand() % (N + 1);
    int random5 = rand() % (N + 1);
    int random6 = rand() % (N + 1);
    int random7 = rand() % (N + 1);

    // Вывод значений переменных в одну строку через пробел
    printf("%d %d %d %d %d %d %d\n", random1, random2, random3, random4, random5, random6, random7);

    return 0;
}
    /*
    // Генерируем и выводим 7 случайных чисел в диапазоне от 0 до N
    for (int i = 0; i < 7; i++) {
        int random_number = rand() % (N + 1); // Генерация числа в диапазоне [0; N]
        printf("%d ", random_number);
    }
    printf("\n"); // Переход на новую строку после вывода чисел

    return 0;
} */