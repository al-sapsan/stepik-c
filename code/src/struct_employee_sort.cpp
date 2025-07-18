/**
 * @file    script5.cpp
 * @brief   Сортировка сотрудников по ФИО (возрастание) или стажу (убывание)
 * @version 2.0
 * @date    2025-07-18
 *
 * @note    Формат строки ввода: ФИО#Пол#Возраст#Стаж
 * @warning Память управляется вручную, нет проверки длины строк
 */

#include <iostream>
#include <cstring>
#include <cstdlib>

/*** Data Types ***/

/**
 * @brief Структура, описывающая сотрудника
 */
typedef struct
{
    char full_name[100]; ///< полное имя
    char gender[20];     ///< пол
    int age;             ///< возраст
    int experience;      ///< стаж работы
} employee_t;

/*** Function Prototypes ***/
void read_employees(employee_t *employees, std::size_t size);
void print_employees(const employee_t *employees, std::size_t size);
int cmp_by_name(const void *a, const void *b);
int cmp_by_experience(const void *a, const void *b);

/*** Main Function ***/
int main()
{
    std::size_t size = 0;
    std::cin >> size;
    std::cin.ignore();
    employee_t *employees = new employee_t[size];
    read_employees(employees, size);

    int sort_mode = 0;
    std::cin >> sort_mode;

    if (sort_mode == 1)
    {
        qsort(employees, size, sizeof(employee_t), cmp_by_name);
    }
    else if (sort_mode == 2)
    {
        qsort(employees, size, sizeof(employee_t), cmp_by_experience);
    }

    print_employees(employees, size);
    delete[] employees;
    return 0;
}

/*** Function Definitions ***/
void read_employees(employee_t *employees, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        char line[256];
        std::cin.getline(line, sizeof(line));
        char *word = std::strtok(line, "#");
        std::strcpy(employees[i].full_name, word);
        word = std::strtok(NULL, "#");
        std::strcpy(employees[i].gender, word);
        word = std::strtok(NULL, "#");
        employees[i].age = std::atoi(word);
        word = std::strtok(NULL, "#");
        employees[i].experience = std::atoi(word);
    }
}

void print_employees(const employee_t *employees, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        std::cout << employees[i].full_name << " "
                  << employees[i].gender << " "
                  << employees[i].age << " "
                  << employees[i].experience << "\n";
    }
}

int cmp_by_name(const void *a, const void *b)
{
    const employee_t *ea = (const employee_t *)a;
    const employee_t *eb = (const employee_t *)b;
    return std::strcmp(ea->full_name, eb->full_name);
}

int cmp_by_experience(const void *a, const void *b)
{
    const employee_t *ea = (const employee_t *)a;
    const employee_t *eb = (const employee_t *)b;
    // По убыванию
    return eb->experience - ea->experience;
}
