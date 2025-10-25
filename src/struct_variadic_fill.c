/********************************************************************
 * @file    script6.c
 * @brief   Заполнение структуры PERSON по форматной строке и вариадическим параметрам
 * @version 1.0
 * @date    2025-07-29
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/*** Typedefs ***/
typedef struct
{
    char fname[100];
    int old;
    int stag;
    int salary;
    double efs;
} PERSON;

/*** Function Prototypes ***/
/**
 * @brief  Заполняет структуру PERSON по форматной строке и вариадическим параметрам
 * @param[in,out] ptr Указатель на структуру PERSON
 * @param[in] fmt Форматная строка
 * @param[in] ... Вариадические параметры
 */
void fill_data(PERSON *ptr, const char *fmt, ...);

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Заполняет структуру PERSON по форматной строке
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    PERSON p;
    fill_data(&p, "#o #e #s #f", 35, 0.95, 120000, "Ivanov");
    return 0;
}

/*** Function Implementation ***/
void fill_data(PERSON *ptr, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    const char *p = fmt;
    while (*p)
    {
        if (*p == '#')
        {
            p++;
            switch (*p)
            {
            case 'f':
            {
                char *str = va_arg(args, char *);
                strncpy(ptr->fname, str, sizeof(ptr->fname) - 1);
                ptr->fname[sizeof(ptr->fname) - 1] = '\0';
                break;
            }
            case 'o':
                ptr->old = va_arg(args, int);
                break;
            case 'g':
                ptr->stag = va_arg(args, int);
                break;
            case 's':
                ptr->salary = va_arg(args, int);
                break;
            case 'e':
                ptr->efs = va_arg(args, double);
                break;
            default:
                break;
            }
        }
        p++;
    }
    va_end(args);
}
