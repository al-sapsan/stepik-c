#include <stdio.h>

extern short marks[];      // Внешний массив marks
extern int marks_size;     // Внешняя переменная с размером массива

int main(void)
{
    int sum = 0;
    for (int i = 0; i < marks_size; ++i) {
        sum += marks[i];
    }

    double avg = (double)sum / marks_size;
    printf("%.2f\n", avg);

    return 0;
}