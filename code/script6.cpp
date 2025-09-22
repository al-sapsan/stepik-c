/**********************************************************************
 * @file script6.cpp
 * @brief Класс Stack и Object, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-22
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <memory>
#include <vector>

/*** Class Definition ***/
/**
 * @brief Класс Object: элемент стека
 */
class Object
{
    int data{0};
    std::shared_ptr<Object> next{nullptr};

public:
    Object(int d);
    int get_data() const;
    std::shared_ptr<Object> &get_next();
};
using shared_obj_ptr = std::shared_ptr<Object>;

/**
 * @brief Класс Stack: стек
 */
class Stack
{
public:
    Stack();
    Stack(const Stack &other);
    Stack &operator=(const Stack &other);
    shared_obj_ptr get_top();
    void push(int data);
    shared_obj_ptr pop();
    Stack &operator+=(int data);
    Stack &operator--();   // prefix
    Stack operator--(int); // postfix
private:
    shared_obj_ptr top{nullptr};
    void clear();
};

/*** Methods Implementation ***/
Object::Object(int d) : data(d), next(nullptr) {}
int Object::get_data() const { return data; }
std::shared_ptr<Object> &Object::get_next() { return next; }

Stack::Stack() : top(nullptr) {}
Stack::Stack(const Stack &other) : top(nullptr)
{
    if (!other.top)
        return;
    // Copy all nodes
    std::vector<int> vals;
    shared_obj_ptr cur = other.top;
    while (cur)
    {
        vals.push_back(cur->get_data());
        cur = cur->get_next();
    }
    for (auto it = vals.rbegin(); it != vals.rend(); ++it)
        push(*it);
}
Stack &Stack::operator=(const Stack &other)
{
    if (this != &other)
    {
        clear();
        if (!other.top)
            return *this;
        std::vector<int> vals;
        shared_obj_ptr cur = other.top;
        while (cur)
        {
            vals.push_back(cur->get_data());
            cur = cur->get_next();
        }
        for (auto it = vals.rbegin(); it != vals.rend(); ++it)
            push(*it);
    }
    return *this;
}
void Stack::clear()
{
    while (top)
        pop();
}
shared_obj_ptr Stack::get_top() { return top; }
void Stack::push(int data)
{
    shared_obj_ptr node = std::make_shared<Object>(data);
    node->get_next() = top;
    top = node;
}
shared_obj_ptr Stack::pop()
{
    if (!top)
        return nullptr;
    shared_obj_ptr ptr = top;
    top = top->get_next();
    return ptr;
}
Stack &Stack::operator+=(int data)
{
    push(data);
    return *this;
}
Stack &Stack::operator--()
{
    pop();
    return *this;
}
Stack Stack::operator--(int)
{
    Stack temp(*this);
    pop();
    return temp;
}
