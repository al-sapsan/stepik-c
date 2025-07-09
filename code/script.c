#include <stdio.h>

int main()
{
    char str[31];                   // 30 символов + '\0'
    fgets(str, sizeof(str), stdin); // Чтение строки с пробелами

    // Удаление символа новой строки (если он есть)
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }

    printf("%s", str);
    return 0;
}