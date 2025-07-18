/**
 * @file    student_manager.cpp
 * @brief   Менеджер списка студентов с динамической памятью
 * @version 1.0
 * @date    2025-07-17
 *
 * @note    Формат ввода одной строки студента: Фамилия;Имя;Возраст
 * @warning Отсутствует проверка длины имени/фамилии и на корректный ввод возраста
 */

#include <iostream>
#include <cstring>
#include <cstdlib>

/*** Data Types ***/

/**
 * @brief Структура, описывающая студента
 */
typedef struct
{
    char *surname; ///< фамилия студента
    char *name;    ///< имя студента
    size_t age;    ///< возраст студента
} student_t;

/*** Function Prototypes ***/

/**
 * @brief Считывает данные одного студента из stdin
 * @param[out] item Структура студента для заполнения
 */
void read_student(student_t &item);

/**
 * @brief Выводит список студентов на экран
 * @param[in] list Указатель на массив студентов
 * @param[in] count Количество студентов
 */
void print_list(const student_t *list, size_t count);

/**
 * @brief Показывает меню и возвращает выбор пользователя
 * @return Число от 1 до 4, соответствующее пункту меню
 */
int show_menu();

/**
 * @brief Добавляет нового студента в конец списка
 * @param[in,out] list Указатель на массив студентов
 * @param[in,out] count Количество студентов
 */
void insert_student(student_t *&list, size_t &count);

/**
 * @brief Удаляет студента по номеру
 * @param[in,out] list Указатель на массив студентов
 * @param[in,out] count Количество студентов
 */
void delete_student(student_t *&list, size_t &count);

/**
 * @brief Освобождает динамически выделенную память
 * @param[in] list Массив студентов
 * @param[in] count Количество студентов
 */
void destroy_list(student_t *list, size_t count);

/*** Main Function ***/

int main()
{
    size_t count = 0;
    std::cin >> count;
    std::cin.ignore(1000, '\n'); // очищаем буфер после ввода числа
    // or std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); with <limits>

    student_t *list = new student_t[count];
    for (size_t i = 0; i < count; ++i)
    {
        read_student(list[i]);
    }

    print_list(list, count);

    for (;;)
    {
        size_t choice = show_menu();
        switch (choice)
        {
        case 1:
            insert_student(list, count);
            break;
        case 2:
            delete_student(list, count);
            break;
        case 3:
            print_list(list, count);
            break;
        case 4:
            std::cout << "Завершаем...\n";
            destroy_list(list, count);
            return 0;
        }
    }
}

/*** Function Definitions ***/

void read_student(student_t &item)
{
    const size_t MAX_LEN = 300;
    char buffer[MAX_LEN];
    std::fgets(buffer, MAX_LEN, stdin);

    char *word = std::strtok(buffer, ";\n"); ///< фамилия студента
    item.surname = new char[std::strlen(word) + 1];
    std::strcpy(item.surname, word);

    word = std::strtok(NULL, ";\n"); ///< имя студента
    item.name = new char[std::strlen(word) + 1];
    std::strcpy(item.name, word);

    word = std::strtok(NULL, ";\n"); ///< возраст студента
    item.age = std::atoi(word);
}

void print_list(const student_t *list, size_t count)
{
    std::cout << "\nСписок студентов:\n";
    for (size_t i = 0; i < count; ++i)
    {
        std::cout << (i + 1) << " " << list[i].surname << " "
                  << list[i].name << " " << list[i].age << "\n";
    }
}

size_t show_menu()
{
    size_t choice = 0;
    do
    {
        std::cout << "\n1 - добавление студента\n";
        std::cout << "2 - удаление студента\n";
        std::cout << "3 - печать списка студентов\n";
        std::cout << "4 - завершение работы программы\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore(1000, '\n');
        if (choice < 1 || choice > 4)
        {
            std::cout << "Неверный выбор! Повторите ввод!\n";
        }
    } while (choice < 1 || choice > 4);
    return choice;
}

void insert_student(student_t *&list, size_t &count)
{
    std::cout << "Введите данные нового студента: ";
    student_t new_item;
    read_student(new_item);

    student_t *new_list = new student_t[count + 1];
    for (size_t i = 0; i < count; ++i)
    {
        new_list[i] = list[i];
    }
    new_list[count] = new_item;

    delete[] list;
    list = new_list;
    ++count;
}

void delete_student(student_t *&list, size_t &count)
{
    std::cout << "Введите номер студента, которого нужно удалить: ";
    size_t index = 0;
    std::cin >> index;
    std::cin.ignore(1000, '\n');

    if (index < 1 || index > count)
        return;

    size_t del_idx = index - 1;

    delete[] list[del_idx].surname;
    delete[] list[del_idx].name;

    student_t *new_list = new student_t[count - 1];
    size_t j = 0;

    for (size_t i = 0; i < count; ++i)
    {
        if (i == del_idx)
            continue;
        new_list[j++] = list[i];
    }

    delete[] list;
    list = new_list;
    --count;
}

void destroy_list(student_t *list, size_t count)
{
    for (size_t i = 0; i < count; ++i)
    {
        delete[] list[i].surname;
        delete[] list[i].name;
    }
    delete[] list;
}
