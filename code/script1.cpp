/************************************************************************
 * @file script1.cpp
 * @brief Шаблонная реализация стека (Object<T>, Stack<T>)
 * @version 1.0
 * @date 2025-10-16
 ************************************************************************/

#include <memory>
#include <iostream>

/**
 * @brief Узел стека, хранящий значение типа T
 * @tparam T Тип данных в узле
 */
template <typename T>
class Object
{
    T data{0};
    std::shared_ptr<Object<T>> next{nullptr};

public:
    explicit Object(const T &d) : data(d), next(nullptr) {}

    T get_data() const { return data; }
    std::shared_ptr<Object<T>> &get_next() { return next; }
};

template <typename T>
using shared_obj_ptr_t = std::shared_ptr<Object<T>>;

/**
 * @brief Стек на основе умных указателей
 * @tparam T Тип данных в стеке
 */
template <typename T>
class Stack
{
    shared_obj_ptr_t<T> top{nullptr};

public:
    shared_obj_ptr_t<T> get_top() { return top; }

    void push(const T &data)
    {
        auto node = std::make_shared<Object<T>>(data);
        node->get_next() = top;
        top = node;
    }

    shared_obj_ptr_t<T> pop()
    {
        if (!top)
            return nullptr;
        auto ptr = top;
        top = top->get_next();
        return ptr;
    }
};

// No main() as per task instructions
