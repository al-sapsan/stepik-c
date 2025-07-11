/**
 * @file    string_copy.c
 * @brief   Копирование одной строки в другую вручную
 * @version 1.0
 */

/* -------------------- Core -------------------- */
#include <stdio.h>

/* -------------------- Constants -------------------- */
static const int MAX_LEN = 128;

/* -------------------- Function Prototypes -------------------- */
/**
 * @brief Копирует строку source в dest
 * @param[out] dest  Указатель на строку назначения
 * @param[in]  source Указатель на исходную строку
 */
void my_strcpy(char *dest, char *source);

/* -------------------- Main -------------------- */
int main(void)
{
    char l_s[MAX_LEN];
    char l_t[MAX_LEN];

    /* Ввод строк */
    fgets(l_s, MAX_LEN, stdin);
    fgets(l_t, MAX_LEN, stdin);

    /* Удаление символов новой строки */
    for (int l_i = 0; l_s[l_i] != '\0'; l_i++)
    {
        if (l_s[l_i] == '\n')
        {
            l_s[l_i] = '\0';
            break;
        }
    }

    for (int l_i = 0; l_t[l_i] != '\0'; l_i++)
    {
        if (l_t[l_i] == '\n')
        {
            l_t[l_i] = '\0';
            break;
        }
    }

    /* Копирование строки */
    my_strcpy(l_s, l_t);

    /* Вывод результата */
    puts(l_s);
    puts(l_t);

    return 0;
}

/* -------------------- Function Definitions -------------------- */
void my_strcpy(char *dest, char *source)
{
    int l_i = 0;
    while (source[l_i] != '\0')
    {
        dest[l_i] = source[l_i];
        l_i++;
    }
    dest[l_i] = '\0';
}
