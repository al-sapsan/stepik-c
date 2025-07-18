
/**
 * @file parse_dynamic_arr.cpp
 * @brief Dynamic Employee list editor (insert by index, C++ embedded style)
 * @version 1.0
 * @date 2025-07-18
 *
 * @note Следует соглашениям emb_style_cpp_en.h
 */

// === Core ===
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

// === Types ===
typedef uint8_t u8_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
typedef int32_t i32_t;
typedef float f32_t;
typedef double f64_t;
typedef bool b_t;

/*** Employee structure ***/
/**
 * @brief Структура сотрудника
 * @details Хранит ФИО, пол, возраст и стаж работы сотрудника
 */
typedef struct
{
    char m_fio[128];   ///< ФИО
    char m_gender[16]; ///< Пол
    u8_t m_age_u8;     ///< Возраст
    u8_t m_exp_u8;     ///< Стаж
} Employee_t;

/**
 * @brief Разбор строки сотрудника
 * @param[in] line Строка с данными (поля через '#')
 * @param[out] emp Структура сотрудника
 */
void parse_employee(const char *line, Employee_t &emp)
{
    // Копируем поля из строки
    const char *p = line;
    char buf[128];
    int field = 0, idx = 0, len = strlen(line);
    int pos = 0;
    for (size_t i = 0; i <= (size_t)len; ++i)
    {
        if (line[i] == '#' || line[i] == '\0')
        {
            buf[idx] = '\0';
            switch (field)
            {
            case 0:
                strncpy(emp.m_fio, buf, sizeof(emp.m_fio) - 1);
                emp.m_fio[sizeof(emp.m_fio) - 1] = '\0';
                break;
            case 1:
                strncpy(emp.m_gender, buf, sizeof(emp.m_gender) - 1);
                emp.m_gender[sizeof(emp.m_gender) - 1] = '\0';
                break;
            case 2:
                emp.m_age_u8 = (u8_t)atoi(buf);
                break;
            case 3:
                emp.m_exp_u8 = (u8_t)atoi(buf);
                break;
            }
            field++;
            idx = 0;
        }
        else
        {
            if (idx < 127)
                buf[idx++] = line[i];
        }
    }
}

/**
 * @brief Печать всех сотрудников
 * @param[in] arr Массив сотрудников
 * @param[in] n Количество сотрудников
 */
void print_employees(const Employee_t *arr, u16_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf("%s %s %d %d\n", arr[i].m_fio, arr[i].m_gender, (int)arr[i].m_age_u8, (int)arr[i].m_exp_u8);
    }
}

/*** Main function ***/
int main()
{
    u16_t n = 0;
    scanf("%hu\n", &n);
    Employee_t *arr = (Employee_t *)malloc(n * sizeof(Employee_t));
    char buf[256];
    for (size_t i = 0; i < n; ++i)
    {
        if (!fgets(buf, sizeof(buf), stdin))
            break;
        size_t l = strlen(buf);
        if (l && buf[l - 1] == '\n')
            buf[l - 1] = '\0';
        parse_employee(buf, arr[i]);
    }
    u16_t arr_size = n;
    for (;;)
    {
        i32_t pos = 0;
        if (scanf("%d\n", &pos) != 1)
            break;
        if (pos < 1 || pos > (i32_t)arr_size + 1)
        {
            print_employees(arr, arr_size);
            break;
        }
        if (!fgets(buf, sizeof(buf), stdin))
            break;
        size_t l = strlen(buf);
        if (l && buf[l - 1] == '\n')
            buf[l - 1] = '\0';
        Employee_t new_emp;
        parse_employee(buf, new_emp);
        Employee_t *new_arr = (Employee_t *)malloc((arr_size + 1) * sizeof(Employee_t));
        for (size_t i = 0; i < (size_t)(pos - 1); ++i)
            new_arr[i] = arr[i];
        new_arr[pos - 1] = new_emp;
        for (size_t i = pos; i <= arr_size; ++i)
            new_arr[i] = arr[i - 1];
        free(arr);
        arr = new_arr;
        arr_size++;
    }
    free(arr);
    return 0;
}
