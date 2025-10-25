#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    /* Подсчет количества вхождений "is" с помощью strstr
    int count = 0;
    char *p = str;
    while ((p = strstr(p, "is")) != NULL) {
        ++count;
        p += 1; // обязательно сдвигаем указатель вперед */

    // Быстрее и надежней
    int count = 0;
    for (int i = 0; str[i] != '\0' && str[i+1] != '\0'; ++i) {
        if (str[i] == 'i' && str[i+1] == 's')
            ++count;
    }
    printf("%d\n", count);

    return 0;
}