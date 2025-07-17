/**
 * @file struct_array_of_structures.cpp
 * @brief Поиск студента по фамилии в массиве структур
 * @version 1.0
 * @date 2025-07-17
 *
 * @note Используется массив структур типа Student
 * @warning Чувствительность к регистру при сравнении фамилий
 */

#include <iostream>
#include <cstring>

/*** Constants ***/

static const size_t N = 4;

/*** Data Types ***/

/**
 * @brief Структура, описывающая студента
 */
struct Student
{
    char name[40]; ///< имя (фамилия) студента
    size_t age;    ///< возраст студента
};

/*** Function Prototypes ***/

/**
 * @brief Выводит список всех студентов
 *
 * @param[in] group Массив студентов
 * @param[in] count Количество студентов в массиве
 */
void print_group(const Student group[], size_t count);

/**
 * @brief Ищет студента по фамилии
 *
 * @param[in] group Массив студентов
 * @param[in] count Количество студентов
 * @param[in] name Фамилия для поиска
 * @return Количество найденных студентов
 */
size_t find_student(const Student group[], size_t count, const char *name);

/*** Main Function ***/

int main()
{
    Student group[N] = {
        {"Иванов", 28},
        {"Семенов", 25},
        {"Петров", 20},
        {"Кулагин", 24}};

    std::cout << "Исходный список группы\n";
    print_group(group, N);

    char name_input[40];
    std::cout << "Введите фамилию студента: ";
    std::cin >> name_input;

    size_t matches = find_student(group, N, name_input);

    if (matches == 0)
    {
        std::cout << "Error\n";
    }

    return 0;
}

/*** Function Definitions ***/

void print_group(const Student group[], size_t count)
{
    for (size_t i = 0; i < count; ++i)
    {
        std::cout << group[i].name << " " << group[i].age << "\n";
    }
}

size_t find_student(const Student group[], size_t count, const char *name)
{
    size_t found = 0;

    for (size_t i = 0; i < count; ++i)
    {
        if (std::strcmp(group[i].name, name) == 0)
        {
            std::cout << group[i].name << " " << group[i].age << "\n";
            ++found;
        }
    }

    return found;
}
