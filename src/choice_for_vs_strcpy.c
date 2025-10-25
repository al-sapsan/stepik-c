#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    /* Замена всех '-' на "-+-"
    char res[100] = {0};
    char *src = str;
    char *dst = res;

    while (*src) {
        if (*src == '-') {
            strcpy(dst, "-+-");
            dst += 3;
            src++;
        } else {
            *dst++ = *src++;
        }
    }
    *dst = '\0';*/
    
    // Понятнее и надежнее, но медленее ~(0_0)~
    char res[100] = {0};
    int j = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '-') {
            res[j++] = '-';
            res[j++] = '+';
            res[j++] = '-';
        } else {
            res[j++] = str[i];
        }
    }
    res[j] = '\0';

    printf("%s\n", res);

    return 0;
}