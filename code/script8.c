
/********************************************************************
 * @file    script8.c
 * @brief   Объединение двух строк с динамическим выделением памяти
 * @version 1.0
 * @date    2025-07-28
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_ln(char *buffer, size_t max_len)
{
    fgets(buffer, max_len - 1, stdin);
    char *ptr_n = strrchr(buffer, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';
}

/*** Function Implementation ***/
char *merge_string(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char *ptr_result = (char *)malloc(len1 + len2 + 1);
    if (ptr_result == NULL)
        return NULL;
    memcpy(ptr_result, str1, len1);
    memcpy(ptr_result + len1, str2, len2);
    ptr_result[len1 + len2] = '\0';
    return ptr_result;
}

/*** Main Function ***/
int main(void)
{
    char str_1[200] = {0};
    char str_2[200] = {0};

    get_ln(str_1, sizeof(str_1));
    get_ln(str_2, sizeof(str_2));

    char *ptr_merged = merge_string(str_1, str_2);
    if (ptr_merged != NULL)
    {
        printf("%s\n", ptr_merged);
        free(ptr_merged);
    }
    return 0;
}
