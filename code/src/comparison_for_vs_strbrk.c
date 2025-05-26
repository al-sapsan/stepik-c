#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    char res[100] = {0};
    char *src = str;
    char *dst = res;
    // Замена всех подряд идущих дефисов на один дефис
    while (*src) {
        if (*src == '-') {
            *dst++ = '-';
            // Пропускаем все последующие дефисы
            src = strpbrk(src, "-");
            while (src && *src == '-') ++src;
            if (!src) break;
        } else {
            *dst++ = *src++;
        }
    }
    *dst = '\0';

    /* Просто. понятно и быстрее
    char res[100] = {0};
    int j = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '-') {
            res[j++] = '-';
            while (str[i + 1] == '-')
                ++i;
        } else {
            res[j++] = str[i];
        }
    }
    res[j] = '\0'; */

    printf("%s\n", res);

    return 0;
}