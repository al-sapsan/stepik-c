#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(void)
{
    srand(time(NULL));

    int range = 10; // Определяем диапазон

    int r_1 = rand() % range; // число в диапазоне от 0 до range-1
    int r_2 = rand() % range -5; // число в диапазоне от -5 до range-6
    int r_3 = rand() + rand(); // число в диапазоне от 0 до 2*RAND_MAX
    // RAND_MAX = 32767

    double range_float = (double)rand() / (double)RAND_MAX; // [0; 1] - для вещественных чисел

    /*После этого, используя вещественное случайное значение range_float 
    диапазона [0; 1], мы легко можем формировать любые другие диапазоны из 
    псевдослучайных вещественных чисел.*/

    printf("%d, %d, %d, %d, %d, %.2f\n", r_1, r_2, rand(), rand(), rand(), range_float);
 
    return 0;
}