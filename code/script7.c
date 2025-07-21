/*******************************************************************************
 * @file script7.c
 * @brief Удаление указанных символов из строки
 * @version 1.0
 * @date 2025-07-21
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

/*** Function Prototype ***/
/**
 * @brief Strip characters from string
 * @param ptr_str Указатель на строку для обработки
 * @param ptr_remove Указатель на строку с удаляемыми символами
 * @details Удаляет все символы из ptr_remove в строке ptr_str
 */
void strip_str(char *ptr_str, const char *ptr_remove);

/*** Main Function ***/
int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';

    strip_str(str, ".,-!?");
    printf("%s\n", str);
    return 0;
}

/*** Function Implementation ***/
void strip_str(char *ptr_str, const char *ptr_remove)
{
    size_t len = strlen(ptr_str);
    size_t k = 0;
    for (size_t i = 0; i < len; ++i)
    {
        if (strchr(ptr_remove, ptr_str[i]) == NULL)
        {
            ptr_str[k++] = ptr_str[i];
        }
    }
    ptr_str[k] = '\0';
}
