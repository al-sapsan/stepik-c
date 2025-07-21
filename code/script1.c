#include <stdio.h>
#include <string.h>
#include <stddef.h>

/**
 * @brief Фильтр: запрещает копирование латинских букв
 * @param[in] ch символ
 * @return 1 если символ не латинский, 0 если латинский
 */
int no_latin(const char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 0;
    return 1;
}

/**
 * @brief Копирует строку src в dst с фильтром символов
 * @param[out] dst строка-приёмник
 * @param[in] max_len_dst максимальная длина dst
 * @param[in] src исходная строка
 * @param[in] filter функция-фильтр
 */
void copy_string(char *dst, size_t max_len_dst, const char *src, int (*filter)(const char))
{
    size_t j = 0;
    for (size_t i = 0; src[i] != '\0' && j < max_len_dst - 1; ++i)
    {
        if (filter(src[i]))
        {
            dst[j++] = src[i];
        }
    }
    dst[j] = '\0';
}

int main(void)
{
    char str[100] = {0}, str2[20];
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';

    copy_string(str2, sizeof(str2), str, no_latin);
    printf("%s\n", str2);

    return 0;
}
