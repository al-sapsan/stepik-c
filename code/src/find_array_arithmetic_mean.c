#include <stdio.h>

int main(void)
{
    double array[20];
    int count = 0;

    // Считываем не более 20 вещественных чисел
    while (count < 20 && scanf("%lf", &array[count]) == 1)
        ++count;

    // Вычисляем среднее арифметическое
    double sum = 0.0;
    for (int i = 0; i < count; ++i) {
        sum += array[i];
    }

    double avg = (count > 0) ? (sum / count) : 0.0;
    printf("%.2f\n", avg);

    return 0;
}