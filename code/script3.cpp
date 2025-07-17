/**
 * @file    script3.cpp
 * @brief   Выводит книги заданного года и их среднюю цену
 * @version 1.0
 * @date    2025-07-17
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 6
#define MAX_STR 128

typedef struct
{
    char title[MAX_STR];
    char author[MAX_STR];
    int year;
    double price;
} Book;

int main(void)
{
    Book arr[MAX_BOOKS];
    char buf[MAX_STR * 4];
    for (int i = 0; i < MAX_BOOKS; ++i)
    {
        if (!fgets(buf, sizeof(buf), stdin))
            return 1;
        char *p = strtok(buf, ";");
        if (!p)
            return 1;
        strncpy(arr[i].title, p, MAX_STR - 1);
        arr[i].title[MAX_STR - 1] = '\0';
        p = strtok(NULL, ";");
        if (!p)
            return 1;
        strncpy(arr[i].author, p, MAX_STR - 1);
        arr[i].author[MAX_STR - 1] = '\0';
        p = strtok(NULL, ";");
        if (!p)
            return 1;
        arr[i].year = atoi(p);
        p = strtok(NULL, ";\n");
        if (!p)
            return 1;
        arr[i].price = atof(p);
    }
    int search_year;
    scanf("%d", &search_year);
    int found = 0;
    double sum = 0.0;
    for (int i = 0; i < MAX_BOOKS; ++i)
    {
        if (arr[i].year == search_year)
        {
            printf("%s/%s/%d/%.2f\n", arr[i].title, arr[i].author, arr[i].year, arr[i].price);
            sum += arr[i].price;
            ++found;
        }
    }
    if (found > 0)
    {
        printf("%.2f\n", sum / found);
    }
    else
    {
        printf("ERROR\n");
    }
    return 0;
}
