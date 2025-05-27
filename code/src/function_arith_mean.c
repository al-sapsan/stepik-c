#include <stdio.h>

double get_mean2(int a, int b); // прототип функции

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);
    double mean = get_mean2(x, y);
    printf("%.1f\n", mean);
    return 0;
}

double get_mean2(int a, int b) {
    return (a + b) / 2.0;
}