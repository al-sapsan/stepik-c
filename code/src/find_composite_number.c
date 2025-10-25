#include <stdio.h>

int main(void)
{
    int num = 0, digit;
    scanf("%d", &digit);

    // Если первая цифра 0, сразу выводим 0
    if (digit == 0) {
        printf("0\n");
        return 0;
    }

    // Формируем число из последовательности цифр до первой 0
    while (digit != 0) {
        num = num * 10 + digit;
        scanf("%d", &digit);
    }

    printf("%d\n", num);
    return 0;
}