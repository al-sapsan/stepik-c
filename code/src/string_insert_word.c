#include <stdio.h>

int main(void)
{
    char str[50] = "best string!";
    int len = 0;

    // Вычисляем длину строки без strlen()
    while (str[len] != '\0') {
        len++;
    }

    // Сдвигаем строку вправо на 4 символа
    for (int i = len; i >= 0; --i) {
        str[i + 4] = str[i];
    }
/* // Сдвигаем строку вправо на 4 символа
    size_t len = strlen(str);
    for (int i = (int)len; i >= 0; --i)
        str[i + 4] = str[i];
*/
    // Вставляем "The " в начало
    str[0] = 'T';
    str[1] = 'h';
    str[2] = 'e';
    str[3] = ' ';

    return 0;
}