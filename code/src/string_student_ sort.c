/**
 * @file    students_sort.c
 * @brief   Сортировка записей об учениках по алфавиту
 * @version 1.0
 * @date    2025-07-16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*** Constants ***/
static const size_t MAX_STR_LEN = 128;

/*** Types ***/
typedef uint32_t u32_t;

/*** Function Prototypes ***/

/**
 * @brief Считывает и сортирует записи об учениках
 * @param[in] n_u32 Количество записей
 */
void process_students(u32_t n_u32);

/**
 * @brief Сравнивает две строки для qsort
 * @param[in] a Указатель на первый элемент
 * @param[in] b Указатель на второй элемент
 * @return <0 если a < b, 0 если a == b, >0 если a > b
 */
static int compare_students(const void *a, const void *b);

/*** Main Function ***/
int main(void)
{
    u32_t count_u32 = 0;

    if ((scanf("%u", &count_u32) != 1) || (count_u32 == 0))
    {
        return 1;
    }

    while (getchar() != '\n')
    {
        ; // Очистить буфер ввода
    }

    process_students(count_u32);

    return 0;
}

/*** Function Definitions ***/
static int compare_students(const void *a, const void *b)
{
    const char *const *pa = (const char *const *)a;
    const char *const *pb = (const char *const *)b;
    return strcmp(*pa, *pb);
}

void process_students(u32_t n_u32)
{
    char **arr_students = (char **)malloc(n_u32 * sizeof(char *));
    if (arr_students == NULL)
    {
        return;
    }

    for (u32_t i_u32 = 0; i_u32 < n_u32; ++i_u32)
    {
        char buf[MAX_STR_LEN];

        if (fgets(buf, MAX_STR_LEN, stdin) == NULL)
        {
            arr_students[i_u32] = NULL;
            continue;
        }

        size_t len = strlen(buf);
        if (len > 0 && buf[len - 1] == '\n')
        {
            buf[len - 1] = '\0';
        }

        arr_students[i_u32] = (char *)malloc((strlen(buf) + 1) * sizeof(char));
        if (arr_students[i_u32] != NULL)
        {
            strcpy(arr_students[i_u32], buf);
        }
    }

    qsort(arr_students, n_u32, sizeof(char *), compare_students);

    for (u32_t i_u32 = 0; i_u32 < n_u32; ++i_u32)
    {
        if (arr_students[i_u32] != NULL)
        {
            printf("%s\n", arr_students[i_u32]);
            free(arr_students[i_u32]);
        }
    }

    free(arr_students);
}
