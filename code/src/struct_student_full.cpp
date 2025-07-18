/**
 * @file student_list_full.cpp
 * @brief Управление списком студентов: добавление, удаление, сортировка.
 * @version 1.1
 * @date 2025-07-18
 */

#include <iostream>
#include <cstring>
#include <cstdlib>

/*** Types ***/
typedef struct
{
    char *surname; /**< фамилия студента */
    char *name;    /**< имя студента */
    int age;       /**< возраст студента */
} student_t;

/*** Function Prototypes ***/

/**
 * @brief Считывает данные одного студента из stdin
 * @param[out] item структура студента, куда записываются данные
 */
void read_student(student_t &item);

/**
 * @brief Печатает список студентов
 * @param[in] list массив студентов
 * @param[in] count количество студентов
 */
void print_list(student_t *list, size_t count);

/**
 * @brief Отображает меню и возвращает выбор пользователя
 * @return выбранный пункт меню
 */
int show_menu();

/**
 * @brief Добавляет нового студента в список
 * @param[in,out] list ссылка на массив студентов
 * @param[in,out] count ссылка на текущее количество студентов
 */
void insert_student(student_t *&list, size_t &count);

/**
 * @brief Удаляет студента из списка по номеру
 * @param[in,out] list ссылка на массив студентов
 * @param[in,out] count ссылка на текущее количество студентов
 */
void delete_student(student_t *&list, size_t &count);

/**
 * @brief Освобождает всю выделенную память
 * @param[in] list массив студентов
 * @param[in] count количество студентов
 */
void destroy_list(student_t *list, size_t count);

/**
 * @brief Сравнивает двух студентов по выбранному критерию
 * @param[in] first первый студент
 * @param[in] second второй студент
 * @param[in] type тип сравнения (1 - по фамилии и имени, 2 - по возрасту)
 * @return результат сравнения (аналог strcmp / разность возрастов)
 */
int student_cmp(student_t *first, student_t *second, int type);

/**
 * @brief Печатает отсортированный список студентов
 * @param[in] list массив студентов
 * @param[in] count количество студентов
 */
void print_sorted(student_t *list, size_t count);

/*** Main Function ***/
int main()
{
    size_t count;
    std::cin >> count;
    while (std::cin.get() != '\n')
        ;

    student_t *list = new student_t[count];
    for (size_t i = 0; i < count; ++i)
    {
        read_student(list[i]);
    }

    print_list(list, count);

    for (;;)
    {
        int choice = show_menu();
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
            print_sorted(list, count);
            break;
        case 5:
            std::cout << "Завершаем...\n";
            destroy_list(list, count);
            return 0;
        }
    }
}

/*** Function Definitions ***/
void read_student(student_t &item)
{
    constexpr size_t MAXLEN = 300;
    char buffer[MAXLEN];
    std::fgets(buffer, MAXLEN, stdin);

    char *word = std::strtok(buffer, ";\n");
    item.surname = new char[std::strlen(word) + 1];
    std::strcpy(item.surname, word);

    word = std::strtok(nullptr, ";\n");
    item.name = new char[std::strlen(word) + 1];
    std::strcpy(item.name, word);

    word = std::strtok(nullptr, ";\n");
    item.age = std::atoi(word);
}

void print_list(student_t *list, size_t count)
{
    std::cout << "\nСписок студентов:\n";
    for (size_t i = 0; i < count; ++i)
    {
        std::cout << i + 1 << " " << list[i].surname << " "
                  << list[i].name << " " << list[i].age << "\n";
    }
}

int show_menu()
{
    int choice;
    do
    {
        std::cout << "\n1 - добавление студента\n";
        std::cout << "2 - удаление студента\n";
        std::cout << "3 - печать списка студентов\n";
        std::cout << "4 - печать отсортированного списка студентов\n";
        std::cout << "5 - завершение работы программы\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        if (choice < 1 || choice > 5)
        {
            std::cout << "Неверный выбор! Повторите ввод!\n";
        }
    } while (choice < 1 || choice > 5);
    return choice;
}

void insert_student(student_t *&list, size_t &count)
{
    std::cout << "Введите данные нового студента:\n";
    while (std::cin.get() != '\n')
        ;
    student_t new_student;
    read_student(new_student);

    student_t *new_list = new student_t[count + 1];
    for (size_t i = 0; i < count; ++i)
    {
        new_list[i] = list[i];
    }
    new_list[count] = new_student;

    delete[] list;
    list = new_list;
    ++count;
}

void delete_student(student_t *&list, size_t &count)
{
    std::cout << "Введите номер студента, которого нужно удалить: ";
    size_t index;
    std::cin >> index;
    if (index < 1 || index > count)
    {
        return;
    }

    delete[] list[index - 1].surname;
    delete[] list[index - 1].name;

    student_t *new_list = new student_t[count - 1];
    size_t j = 0;
    for (size_t i = 0; i < count; ++i)
    {
        if (i == index - 1)
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

int student_cmp(student_t *first, student_t *second, int type)
{
    if (type == 1)
    {
        int cmp = std::strcmp(first->surname, second->surname);
        return (cmp == 0) ? std::strcmp(first->name, second->name) : cmp;
    }
    if (type == 2)
    {
        return first->age - second->age;
    }
    return 0;
}

void print_sorted(student_t *list, size_t count)
{
    std::cout << "1 - сортировка по фамилии и имени\n";
    std::cout << "2 - сортировка по возрасту\n";
    std::cout << "Ваш выбор: ";
    int type;
    std::cin >> type;

    student_t **ptr_array = new student_t *[count];
    for (size_t i = 0; i < count; ++i)
    {
        ptr_array[i] = &list[i];
    }

    for (size_t i = 0; i < count - 1; ++i)
    {
        for (size_t j = 0; j < count - i - 1; ++j)
        {
            if (student_cmp(ptr_array[j], ptr_array[j + 1], type) > 0)
            {
                std::swap(ptr_array[j], ptr_array[j + 1]);
            }
        }
    }

    std::cout << "Отсортированный список студентов:\n";
    for (size_t i = 0; i < count; ++i)
    {
        std::cout << ptr_array[i]->surname << " "
                  << ptr_array[i]->name << " "
                  << ptr_array[i]->age << "\n";
    }

    delete[] ptr_array;
}
