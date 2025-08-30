/**********************************************************************
 * @file script7.cpp
 * @brief Singly linked list with shared_ptr, push_back, pop_front, show
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-30
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <memory>

/*** Struct Definition ***/
/**
 * @brief Структура односвязного списка
 * @details Хранит данные и указатель на следующий элемент
 */
struct object
{
    int data;
    std::shared_ptr<object> next;
};

using shared_obj_ptr = std::shared_ptr<object>;

/*** Function Definition ***/
/**
 * @brief Добавление нового элемента в конец односвязного списка
 * @param[in,out] head Указатель на первый элемент
 * @param[in,out] tail Указатель на последний элемент
 * @param[in] data Значение для поля data
 */
void push_back(shared_obj_ptr &head, shared_obj_ptr &tail, int data);

/**
 * @brief Удаление первого элемента односвязного списка
 * @param[in,out] head Указатель на первый элемент
 * @param[in,out] tail Указатель на последний элемент
 */
void pop_front(shared_obj_ptr &head, shared_obj_ptr &tail);

/**
 * @brief Отображение значений поля data всех элементов списка
 * @param[in] head Указатель на первый элемент
 */
void show(const shared_obj_ptr &head);

/*** Main Function ***/
/**
 * @brief Точка входа в программу
 * @details Формирует односвязный список, выводит значения
 * @return Код завершения (0 — успешно)
 */
int main(void)
{
    shared_obj_ptr head = nullptr, tail = nullptr;
    push_back(head, tail, 1);
    push_back(head, tail, 2);
    push_back(head, tail, 3);
    push_back(head, tail, 4);
    show(head);
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}

/*** Functions Implementation ***/

void push_back(shared_obj_ptr &head, shared_obj_ptr &tail, int data)
{
    shared_obj_ptr new_obj = std::make_shared<object>();
    new_obj->data = data;
    new_obj->next = nullptr;
    if (!head)
    {
        head = tail = new_obj;
    }
    else
    {
        tail->next = new_obj;
        tail = new_obj;
    }
}

void pop_front(shared_obj_ptr &head, shared_obj_ptr &tail)
{
    if (!head)
        return;
    head = head->next;
    if (!head)
        tail = nullptr;
}

void show(const shared_obj_ptr &head)
{
    auto curr = head;
    while (curr)
    {
        std::cout << curr->data;
        if (curr->next)
            std::cout << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}
