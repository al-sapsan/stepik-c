/*
Вычислим кратную двойную сумму, где нижние индексы суммирования 
i=1,j=1, верхние индексы i=3,j=3, а каждый член равен i(j+1):
*/

#include <stdio.h>

int main() {
    int sum = 0;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            sum += i * (j + 1);
        }
    }
    printf("%d\n", sum);
    return 0;
}