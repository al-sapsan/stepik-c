/************************************************************************
 * @file script1.cpp
 * @brief Реализация односвязного списка: Object, OneLinkedList и исключение
 * @version 1.0
 * @date 2025-10-17
 ************************************************************************/

#include <memory>
#include <exception>
#include <string>

/**
 * @brief Исключение для некорректного индекса списка
 */
class LinkedListIndexError : public std::exception
{
public:
    const char *what() const noexcept override { return "Invalid element index."; }
};

/**
 * @brief Узел односвязного списка, содержащий данные типа T
 * @tparam T Тип данных
 */
template <typename T>
class Object
{
    T data{};
    std::shared_ptr<Object<T>> next{nullptr};

public:
    explicit Object(const T &d) : data(d), next(nullptr) {}
    T &get_data() { return data; }
    const T &get_data() const { return data; }
    std::shared_ptr<Object<T>> get_next() const { return next; }
    void set_next(const std::shared_ptr<Object<T>> &n) { next = n; }
    void set_data(const T &d) { data = d; }
};

/**
 * @brief Односвязный список с операциями push/pop и доступом по индексу
 * @tparam T Тип данных в списке
 */
template <typename T>
class OneLinkedList
{
    std::shared_ptr<Object<T>> head{nullptr};
    std::shared_ptr<Object<T>> tail{nullptr};
    size_t length{0};

public:
    OneLinkedList() = default;
    ~OneLinkedList() = default;

    std::shared_ptr<Object<T>> get_head() const { return head; }
    std::shared_ptr<Object<T>> get_tail() const { return tail; }

    void push_back(const T &value)
    {
        auto node = std::make_shared<Object<T>>(value);
        if (!head)
        {
            head = tail = node;
        }
        else
        {
            tail->set_next(node);
            tail = node;
        }
        ++length;
    }

    void push_front(const T &value)
    {
        auto node = std::make_shared<Object<T>>(value);
        if (!head)
        {
            head = tail = node;
        }
        else
        {
            node->set_next(head);
            head = node;
        }
        ++length;
    }

    void pop_back()
    {
        if (!head)
            return; // empty
        if (head == tail)
        {
            head.reset();
            tail.reset();
            length = 0;
            return;
        }
        // find previous to tail
        auto cur = head;
        while (cur->get_next() && cur->get_next() != tail)
        {
            cur = cur->get_next();
        }
        // cur now points to node before tail
        cur->set_next(nullptr);
        tail = cur;
        --length;
    }

    void pop_front()
    {
        if (!head)
            return;
        head = head->get_next();
        if (!head)
            tail.reset();
        --length;
    }

    // index operators (0-based)
    T &operator[](int idx)
    {
        if (idx < 0 || static_cast<size_t>(idx) >= length)
            throw LinkedListIndexError();
        auto cur = head;
        int i = 0;
        while (i < idx)
        {
            cur = cur->get_next();
            ++i;
        }
        return cur->get_data();
    }

    const T &operator[](int idx) const
    {
        if (idx < 0 || static_cast<size_t>(idx) >= length)
            throw LinkedListIndexError();
        auto cur = head;
        int i = 0;
        while (i < idx)
        {
            cur = cur->get_next();
            ++i;
        }
        return cur->get_data();
    }
};