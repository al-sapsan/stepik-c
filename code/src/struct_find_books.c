/**
 * @file    script3.cpp
 * @brief   Выводит книги заданного года и их среднюю цену
 * @version 1.0
 * @date    2025-07-17
 *
 * @note    Каждая книга считывается с новой строки формата:
 *          Название;Автор;Год;Цена
 * @warning Нет обработки некорректного формата данных
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*** Macros ***/

#define MAX_BOOKS 6
#define MAX_STR 128

/*** Data Types ***/

/**
 * @brief Структура, описывающая книгу
 */
typedef struct
{
    char title[MAX_STR];  ///< название книги
    char author[MAX_STR]; ///< автор книги
    int year;             ///< год издания
    double price;         ///< цена книги
} book_t;

/*** Main Function ***/

int main(void)
{
    book_t books[MAX_BOOKS];
    char buf[MAX_STR * 4];

    for (int i = 0; i < MAX_BOOKS; ++i)
    {
        if (!fgets(buf, sizeof(buf), stdin))
        {
            return 1;
        }

        char *p = strtok(buf, ";");
        if (!p)
            return 1;
        strncpy(books[i].title, p, MAX_STR - 1);
        books[i].title[MAX_STR - 1] = '\0';

        p = strtok(NULL, ";");
        if (!p)
            return 1;
        strncpy(books[i].author, p, MAX_STR - 1);
        books[i].author[MAX_STR - 1] = '\0';

        p = strtok(NULL, ";");
        if (!p)
            return 1;
        books[i].year = atoi(p);

        p = strtok(NULL, ";\n");
        if (!p)
            return 1;
        books[i].price = atof(p);
    }

    int search_year = 0;
    if (scanf("%d", &search_year) != 1)
    {
        printf("ERROR\n");
        return 1;
    }

    int count = 0;
    double sum = 0.0;

    for (int i = 0; i < MAX_BOOKS; ++i)
    {
        if (books[i].year == search_year)
        {
            printf("%s/%s/%d/%.2f\n",
                   books[i].title,
                   books[i].author,
                   books[i].year,
                   books[i].price);
            sum += books[i].price;
            ++count;
        }
    }

    if (count > 0)
    {
        printf("%.2f\n", sum / count);
    }
    else
    {
        printf("ERROR\n");
    }

    return 0;
}
