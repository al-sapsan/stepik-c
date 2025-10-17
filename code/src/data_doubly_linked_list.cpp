/************************************************************************
 * @file script2.cpp
 * @brief Двусвязный список: Object, LinkedList и исключение
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
    const char *what() const noexcept override
    {
        return "Invalid element index.";
    }
};

/**
 * @brief Узел двусвязного списка
 * @tparam T Тип данных в узле
 */
template <typename T>
class Object
{
private:
    T data{};
    std::shared_ptr<Object<T>> next{nullptr};
    std::shared_ptr<Object<T>> prev{nullptr};

public:
    explicit Object(const T &d) : data(d) {}

    T &get_data() { return data; }
    const T &get_data() const { return data; }

    std::shared_ptr<Object<T>> get_next() const { return next; }
    std::shared_ptr<Object<T>> get_prev() const { return prev; }

    void set_next(const std::shared_ptr<Object<T>> &n) { next = n; }
    void set_prev(const std::shared_ptr<Object<T>> &p) { prev = p; }
};

/**
 * @brief Двусвязный список с операциями вставки/удаления и доступом по индексу
 * @tparam T Тип данных в списке
 */
template <typename T>
class LinkedList
{
private:
    std::shared_ptr<Object<T>> head{nullptr};
    std::shared_ptr<Object<T>> tail{nullptr};
    size_t length{0};

    void check_index(int idx) const
    {
        if (idx < 0 || static_cast<size_t>(idx) >= length)
            throw LinkedListIndexError();
    }

public:
    LinkedList() = default;
    ~LinkedList() = default;

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
            node->set_prev(tail);
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
            head->set_prev(node);
            head = node;
        }
        ++length;
    }

    void pop_back()
    {
        if (!tail)
            return;
        if (head == tail)
        {
            head.reset();
            tail.reset();
        }
        else
        {
            tail = tail->get_prev();
            tail->set_next(nullptr);
        }
        --length;
    }

    void pop_front()
    {
        if (!head)
            return;
        if (head == tail)
        {
            head.reset();
            tail.reset();
        }
        else
        {
            head = head->get_next();
            head->set_prev(nullptr);
        }
        --length;
    }

    void insert(int idx, const T &value)
    {
        if (idx < 0 || static_cast<size_t>(idx) > length)
            throw LinkedListIndexError();

        if (idx == 0)
        {
            push_front(value);
            return;
        }
        if (static_cast<size_t>(idx) == length)
        {
            push_back(value);
            return;
        }

        auto node = std::make_shared<Object<T>>(value);
        auto cur = head;
        for (int i = 0; i < idx; ++i)
            cur = cur->get_next();

        node->set_prev(cur->get_prev());
        node->set_next(cur);
        cur->get_prev()->set_next(node);
        cur->set_prev(node);
        ++length;
    }

    void remove(int idx)
    {
        check_index(idx);

        if (idx == 0)
        {
            pop_front();
            return;
        }
        if (static_cast<size_t>(idx) == length - 1)
        {
            pop_back();
            return;
        }

        auto cur = head;
        for (int i = 0; i < idx; ++i)
            cur = cur->get_next();

        cur->get_prev()->set_next(cur->get_next());
        cur->get_next()->set_prev(cur->get_prev());
        --length;
    }

    T &operator[](int idx)
    {
        check_index(idx);
        auto cur = head;
        for (int i = 0; i < idx; ++i)
            cur = cur->get_next();
        return cur->get_data();
    }

    const T &operator[](int idx) const
    {
        check_index(idx);
        auto cur = head;
        for (int i = 0; i < idx; ++i)
            cur = cur->get_next();
        return cur->get_data();
    }
};
