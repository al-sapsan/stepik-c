#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(void)
{
    time_t t = time(NULL); // time_t time(time_t * const _Time);
    // возвращает текущее время в секундах в виде аргумента
    srand(t); // void srand(unsigned int seed);
    // задает начальное значение «зерна» (seed) для датчика псевдослучайных чисел 
    // краткая запись `srand(time(NULL))`;
    int r_1 = rand();
    int r_2 = rand();
 
    printf("%d, %d, %d, %d, %d\n", r_1, r_2, rand(), rand(), rand());
 
    return 0;
}