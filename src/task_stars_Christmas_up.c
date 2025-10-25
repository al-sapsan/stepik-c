#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        // Печатаем пробелы
        for (int s = 1; s <= n - i; s++) {
            printf(" ");
        }
        // Печатаем звёздочки
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}