#include <stdio.h>

int main(void)
{
    char data[5][10];

    // Считываем 5 слов, каждое не длиннее 9 символов (+1 для '\0')
    for (int i = 0; i < 5; ++i)
        scanf("%9s", data[i]);

    // Выводим каждое слово в квадратных скобках с новой строки
    for (int i = 0; i < 5; ++i)
        printf("[%s]\n", data[i]);

    return 0;
}