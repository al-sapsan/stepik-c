/**
 * @file script7.cpp
 * @brief Реализация дека на двусвязном списке с функциями push/pop left/right, print, clear
 * @version 1.0
 * @date 2025-07-19
 *
 * @note Стиль: typedef struct с постфиксом _t, size_t для индексов, Doxygen-комментарии на русском (заголовки на английском), циклы for(;;), без std::vector и std::string
 */
#include <iostream>
#include <cstddef>

/**
 * @brief Узел дека (двусвязный список)
 */
typedef struct Node_t
{
    int data;
    Node_t *next;
    Node_t *prev;
} Node_t;

/*** Function prototypes ***/
void push_right(int value, Node_t *&head, Node_t *&tail);
void push_left(int value, Node_t *&head, Node_t *&tail);
int pop_right(Node_t *&head, Node_t *&tail);
int pop_left(Node_t *&head, Node_t *&tail);
int right(const Node_t *tail);
int left(const Node_t *head);
void print(const Node_t *head);
void clear(Node_t *&head, Node_t *&tail);

/*** Main function ***/
int main()
{
    Node_t *Head = NULL, *Tail = NULL;
    int choice = 0, number = 0;
    std::cout << "1 - push_right, 2 - push_left, 3 - pop_right, 4 - pop_left, 5 - right, 6 - left, 7 - print, 8 - clear, 0 - exit\n";
    for (;;)
    {
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cin >> number;
            push_right(number, Head, Tail);
            break;
        case 2:
            std::cin >> number;
            push_left(number, Head, Tail);
            break;
        case 3:
            if (Tail)
                std::cout << "Извлечено справа: " << pop_right(Head, Tail) << std::endl;
            else
                std::cout << "Дек пуст" << std::endl;
            break;
        case 4:
            if (Head)
                std::cout << "Извлечено слева: " << pop_left(Head, Tail) << std::endl;
            else
                std::cout << "Дек пуст" << std::endl;
            break;
        case 5:
            if (Tail)
                std::cout << "Правый: " << right(Tail) << std::endl;
            else
                std::cout << "Дек пуст" << std::endl;
            break;
        case 6:
            if (Head)
                std::cout << "Левый: " << left(Head) << std::endl;
            else
                std::cout << "Дек пуст" << std::endl;
            break;
        case 7:
            if (Head)
                print(Head);
            else
                std::cout << "Дек пуст" << std::endl;
            break;
        case 8:
            clear(Head, Tail);
            break;
        case 0:
            clear(Head, Tail);
            return 0;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    }
}

/*** Function definitions ***/

/**
 * @brief Добавляет элемент справа
 */
void push_right(int value, Node_t *&head, Node_t *&tail)
{
    Node_t *node = new Node_t;
    node->data = value;
    node->next = NULL;
    node->prev = tail;
    if (!tail)
    {
        head = tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

/**
 * @brief Добавляет элемент слева
 */
void push_left(int value, Node_t *&head, Node_t *&tail)
{
    Node_t *node = new Node_t;
    node->data = value;
    node->prev = NULL;
    node->next = head;
    if (!head)
    {
        head = tail = node;
    }
    else
    {
        head->prev = node;
        head = node;
    }
}

/**
 * @brief Извлекает элемент справа
 */
int pop_right(Node_t *&head, Node_t *&tail)
{
    if (!tail)
        return 0;
    int val = tail->data;
    Node_t *tmp = tail;
    tail = tail->prev;
    if (tail)
        tail->next = NULL;
    else
        head = NULL;
    delete tmp;
    return val;
}

/**
 * @brief Извлекает элемент слева
 */
int pop_left(Node_t *&head, Node_t *&tail)
{
    if (!head)
        return 0;
    int val = head->data;
    Node_t *tmp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    else
        tail = NULL;
    delete tmp;
    return val;
}

/**
 * @brief Чтение элемента справа без удаления
 */
int right(const Node_t *tail)
{
    if (!tail)
        return 0;
    return tail->data;
}

/**
 * @brief Чтение элемента слева без удаления
 */
int left(const Node_t *head)
{
    if (!head)
        return 0;
    return head->data;
}

/**
 * @brief Печать дека слева направо
 */
void print(const Node_t *head)
{
    std::cout << "Дек (слева направо): ";
    for (const Node_t *p = head; p; p = p->next)
    {
        std::cout << p->data << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Очистка дека
 */
void clear(Node_t *&head, Node_t *&tail)
{
    while (head)
    {
        Node_t *tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = NULL;
}
