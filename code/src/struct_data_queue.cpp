/**
 * @file queue.cpp
 * @brief Пример реализации очереди (queue) на односвязном списке
 * @version 1.0
 * @date 2025-07-18
 */

#include <iostream>
#include <cstddef>

/*** Types ***/
typedef struct Node_t
{
    int data;
    Node_t *next;
} Node_t;

/*** Function prototypes ***/
void push(int value, Node_t *&head, Node_t *&tail);
int pop(Node_t *&head, Node_t *&tail);
int peek(const Node_t *head);
void print(const Node_t *head);
void clear(Node_t *&head, Node_t *&tail);

/*** Main function ***/
int main()
{
    Node_t *Head = NULL, *Tail = NULL;
    int choice = 0;
    int number = 0;
    for (;;)
    {
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cin >> number;
            push(number, Head, Tail);
            break;
        case 2:
            if (Head)
                std::cout << "Извлечено: " << pop(Head, Tail) << std::endl;
            else
                std::cout << "Очередь пуста" << std::endl;
            break;
        case 3:
            if (Head)
                std::cout << "Первый: " << peek(Head) << std::endl;
            else
                std::cout << "Очередь пуста" << std::endl;
            break;
        case 4:
            if (Head)
                print(Head);
            else
                std::cout << "Очередь пуста" << std::endl;
            break;
        case 5:
            clear(Head, Tail);
            break;
        default:
            clear(Head, Tail);
            return 0;
        }
    }
}

/*** Function definitions ***/

/**
 * @brief Добавляет элемент в конец очереди
 * @param[in] value Значение для добавления
 * @param[in,out] head Указатель на голову очереди
 * @param[in,out] tail Указатель на хвост очереди
 */
void push(int value, Node_t *&head, Node_t *&tail)
{
    Node_t *node = new Node_t;
    node->data = value;
    node->next = NULL;
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
 * @brief Извлекает элемент из начала очереди
 * @param[in,out] head Указатель на голову очереди
 * @param[in,out] tail Указатель на хвост очереди
 * @return Значение извлечённого элемента
 */
int pop(Node_t *&head, Node_t *&tail)
{
    if (!head)
        return 0;
    int val = head->data;
    Node_t *tmp = head;
    head = head->next;
    if (!head)
        tail = NULL;
    delete tmp;
    return val;
}

/**
 * @brief Возвращает значение первого элемента очереди
 * @param[in] head Указатель на голову очереди
 * @return Значение первого элемента
 */
int peek(const Node_t *head)
{
    if (!head)
        return 0;
    return head->data;
}

/**
 * @brief Печатает все элементы очереди
 * @param[in] head Указатель на голову очереди
 */
void print(const Node_t *head)
{
    std::cout << "Очередь (с начала): ";
    for (const Node_t *p = head; p; p = p->next)
    {
        std::cout << p->data << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Очищает всю очередь
 * @param[in,out] head Указатель на голову очереди
 * @param[in,out] tail Указатель на хвост очереди
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
