/**
 * @file stack.cpp
 * @brief Пример реализации стека на односвязном списке
 * @version 1.0
 * @date 2025-07-18
 */

#include <iostream>

/*** Types ***/

/**
 * @brief Узел односвязного стека
 */
typedef struct node_t
{
    int data;            /**< значение узла */
    struct node_t *next; /**< указатель на следующий узел */
} node_t;

/*** Function Prototypes ***/

/**
 * @brief Добавляет элемент в вершину стека
 * @param[in] data значение для добавления
 * @param[in,out] top ссылка на вершину стека
 */
void push(int data, node_t *&top);

/**
 * @brief Извлекает элемент из вершины стека
 * @param[in,out] top ссылка на вершину стека
 * @return значение, извлечённое из вершины (0, если стек пуст)
 */
int pop(node_t *&top);

/**
 * @brief Читает значение из вершины стека, не удаляя его
 * @param[in] top указатель на вершину стека
 * @return значение из вершины (0, если стек пуст)
 */
int peek(const node_t *top);

/**
 * @brief Печатает содержимое стека
 * @param[in] top указатель на вершину стека
 */
void print(const node_t *top);

/**
 * @brief Полностью очищает стек
 * @param[in,out] top ссылка на вершину стека
 */
void clear(node_t *&top);

/**
 * @brief Показывает меню и возвращает выбор пользователя
 * @return выбранный пункт меню
 */
int menu();

/*** Main Function ***/

int main()
{
    node_t *top = nullptr;
    int data;

    for (;;)
    {
        int choice = menu();
        switch (choice)
        {
        case 1:
            std::cout << "Введите число: ";
            std::cin >> data;
            push(data, top);
            break;

        case 2:
            std::cout << "Извлечено из стека: " << pop(top) << "\n";
            break;

        case 3:
            std::cout << "Прочитано из вершины: " << peek(top) << "\n";
            break;

        case 4:
            print(top);
            break;

        case 5:
            clear(top);
            break;

        case 6:
            std::cout << "Завершение работы...\n";
            clear(top);
            return 0;
        }
    }
}

/*** Function Definitions ***/

void push(int data, node_t *&top)
{
    node_t *new_node = new node_t;
    new_node->data = data;
    new_node->next = top;
    top = new_node;
}

int pop(node_t *&top)
{
    if (top == nullptr)
    {
        return 0;
    }

    int result = top->data;
    node_t *new_node = top;
    top = top->next;
    delete new_node;

    return result;
}

int peek(const node_t *top)
{
    if (top == nullptr)
    {
        return 0;
    }

    return top->data;
}

void print(const node_t *top)
{
    if (top == nullptr)
    {
        std::cout << "Стек пуст\n";
        return;
    }

    std::cout << "Содержимое стека от вершины: ";
    const node_t *current = top;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

void clear(node_t *&top)
{
    while (top != nullptr)
    {
        node_t *new_node = top;
        top = top->next;
        delete new_node;
    }
}

int menu()
{
    int choice = 0;
    do
    {
        std::cout << "\n1 - Добавление в стек\n";
        std::cout << "2 - Удаление из стека\n";
        std::cout << "3 - Чтение вершины стека\n";
        std::cout << "4 - Печать стека\n";
        std::cout << "5 - Очистка стека\n";
        std::cout << "6 - Завершение работы\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        if (choice < 1 || choice > 6)
        {
            std::cout << "Неверный выбор! Повторите ввод!\n";
        }
    } while (choice < 1 || choice > 6);

    return choice;
}
