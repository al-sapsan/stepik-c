
/********************************************************************
 * @file    script2.c
 * @brief   Определение мажорных нот через enum и функцию
 * @version 1.0
 * @date    2025-07-28
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>

/*** Typedefs ***/
typedef enum
{
    _do = 1,
    _re = 2,
    _mi = 3,
    _fa = 4,
    _sol = 5,
    _la = 6,
    _si = 7
} NOTES;

/*** Function Prototypes ***/
/**
 * @brief Проверяет, является ли нота мажорной (_do, _mi, _sol)
 *
 * @param[in] note Нота типа NOTES
 * @return 1 — если мажорная, 0 — иначе
 */
int get_major(NOTES note);

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0)
 */
int main(void)
{
    int arr_notes[5];
    for (size_t i = 0; i < 5; ++i)
        scanf("%d", &arr_notes[i]);

    for (size_t i = 0; i < 5; ++i)
    {
        if (get_major((NOTES)arr_notes[i]))
            printf("%d ", arr_notes[i]);
    }
    printf("\n");
    return 0;
}

/*** Function Implementation ***/
int get_major(NOTES note)
{
    return (note == _do || note == _mi || note == _sol) ? 1 : 0;
}
