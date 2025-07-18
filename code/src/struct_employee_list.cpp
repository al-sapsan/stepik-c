/**
 * @file    employee_manager.cpp
 * @brief   Управление списком сотрудников с добавлением и удалением по позиции
 * @version 1.2
 * @date    2025-07-17
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

/**
 * @brief Считывает исходный список сотрудников
 *
 * @param[out] employees Указатель на массив сотрудников
 * @param[in] size Количество сотрудников
 */
void read_initial_employees(employee_t **employees, std::size_t size);

/**
 * @brief Печатает список сотрудников
 *
 * @param[in] employees Указатель на массив сотрудников
 * @param[in] size Количество сотрудников
 */
void print_employees(const employee_t *employees, std::size_t size);

/**
 * @brief Добавляет сотрудника на заданную позицию
 *
 * @param[in,out] employees Указатель на массив сотрудников
 * @param[in,out] size Количество сотрудников
 * @param[in] position Позиция для вставки (1-based)
 */
void add_employee(employee_t **employees, std::size_t *size, std::size_t position);

/**
 * @brief Удаляет сотрудника с заданной позиции
 *
 * @param[in,out] employees Указатель на массив сотрудников
 * @param[in,out] size Количество сотрудников
 * @param[in] position Позиция для удаления (1-based)
 */
void remove_employee(employee_t **employees, std::size_t *size, std::size_t position);

/*** Main Function ***/

int main()
{
    std::size_t size = 0;
    std::cin >> size;

    employee_t *employees = new employee_t[size];
    std::cin.ignore(); // очистка буфера после чтения size
    read_initial_employees(&employees, size);

    for (;;)
    {
        int action = 0;
        std::cin >> action;

        if (action != 1 && action != 2)
        {
            break;
        }

        std::size_t position = 0;
        std::cin >> position;

        if (action == 1)
        {
            add_employee(&employees, &size, position);
        }
        else if (action == 2)
        {
            remove_employee(&employees, &size, position);
        }
    }

    print_employees(employees, size);
    delete[] employees;

    return 0;
}

/*** Function Definitions ***/

void read_initial_employees(employee_t **employees, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        char line[256];
        std::cin.getline(line, sizeof(line));

        char *word = std::strtok(line, "#");
        std::strcpy((*employees)[i].full_name, word);

        word = std::strtok(NULL, "#");
        std::strcpy((*employees)[i].gender, word);

        word = std::strtok(NULL, "#");
        (*employees)[i].age = std::atoi(word);

        word = std::strtok(NULL, "#");
        (*employees)[i].experience = std::atoi(word);
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

void add_employee(employee_t **employees, std::size_t *size, std::size_t position)
{
    if (position < 1 || position > *size + 1)
    {
        return;
    }

    employee_t *new_employees = new employee_t[*size + 1];
    std::size_t j = 0;

    for (std::size_t i = 0; i < *size + 1; ++i)
    {
        if (i == position - 1)
        {
            char line[256];
            std::cin.ignore(); // очистка перед getline
            std::cin.getline(line, sizeof(line));

            char *word = std::strtok(line, "#");
            std::strcpy(new_employees[i].full_name, word);

            word = std::strtok(NULL, "#");
            std::strcpy(new_employees[i].gender, word);

            word = std::strtok(NULL, "#");
            new_employees[i].age = std::atoi(word);

            word = std::strtok(NULL, "#");
            new_employees[i].experience = std::atoi(word);
        }
        else
        {
            new_employees[i] = (*employees)[j++];
        }
    }

    delete[] *employees;
    *employees = new_employees;
    ++(*size);
}

void remove_employee(employee_t **employees, std::size_t *size, std::size_t position)
{
    if (position < 1 || position > *size)
    {
        return;
    }

    employee_t *new_employees = new employee_t[*size - 1];
    std::size_t j = 0;

    for (std::size_t i = 0; i < *size; ++i)
    {
        if (i != position - 1)
        {
            new_employees[j++] = (*employees)[i];
        }
    }

    delete[] *employees;
    *employees = new_employees;
    --(*size);
}
