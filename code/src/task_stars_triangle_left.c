#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {         // Внешний цикл по строкам
        for (int j = 1; j <= i; j++) {     // Внутренний цикл по столбцам (звёздочкам)
            printf("*");
        }
        printf("\n");                      // Переход на новую строку после каждой строки
    }

    return 0;
}