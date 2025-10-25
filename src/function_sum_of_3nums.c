#include <stdio.h>

int get_sum2(int a, int b); // прототип функции

int main(void)
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    int sum = get_sum2(get_sum2(x, y), z);
    printf("%d\n", sum);
    return 0;
}

int get_sum2(int a, int b) {
    return a + b;
}