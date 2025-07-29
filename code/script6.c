/********************************************************************
 * @file    script6.c
 * @brief   Заполнение структуры tag_student из переменных
 * @version 1.0
 * @date    2025-07-28
 ********************************************************************/

/*** Includes ***/
#include <stdio.h>
#include <string.h>

/*** Typedefs ***/
typedef struct tag_fio
{
    char firstname[50];
    char otch[50];
    char lastname[50];
} tag_fio;

typedef struct tag_student
{
    tag_fio fio;
    short old;
    short height;
    short weight;
} tag_student;

/*** Function Prototypes ***/
void getline(char *buffer, size_t max_len);

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 *         Заполняет структуру tag_student из переменных
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    char fname[50], otch[50], lname[50]; // имя, отчество, фамилия
    short old, height, weight;           // возраст, высота, вес

    getline(fname, sizeof(fname));
    getline(otch, sizeof(otch));
    getline(lname, sizeof(lname));

    scanf("%hd, %hd, %hd", &old, &height, &weight);

    tag_student st;
    strncpy(st.fio.firstname, fname, sizeof(st.fio.firstname) - 1);
    st.fio.firstname[sizeof(st.fio.firstname) - 1] = '\0';
    strncpy(st.fio.otch, otch, sizeof(st.fio.otch) - 1);
    st.fio.otch[sizeof(st.fio.otch) - 1] = '\0';
    strncpy(st.fio.lastname, lname, sizeof(st.fio.lastname) - 1);
    st.fio.lastname[sizeof(st.fio.lastname) - 1] = '\0';
    st.old = old;
    st.height = height;
    st.weight = weight;

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}

/*** Function Implementation ***/
void getline(char *buffer, size_t max_len)
{
    fgets(buffer, max_len - 1, stdin);
    char *ptr_n = strrchr(buffer, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';
}
