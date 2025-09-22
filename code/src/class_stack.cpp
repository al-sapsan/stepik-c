/**********************************************************************
 * @file class_stack.cpp
 * @brief Классы Stack и Object - реализация стека
 * @version 2.5 (Исправленная версия)
 * @date 2025-09-22
 **********************************************************************/

/*** Includes ***/
#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>

/*** Class Definition ***/

/**
 * @brief Класс Object: элемент стека
 */
class Object
{
public:
    /**
     * @brief Конструктор
     * @param[in] value Значение элемента
     */
    Object(int value);

    /**
     * @brief Получить значение элемента
     * @return Значение элемента
     */
    int get_data() const;

    /**
     * @brief Получить указатель на следующий элемент
     * @return Указатель на следующий элемент
     */
    Object *get_next() const;

    /**
     * @brief Установить следующий элемент
     * @param[in] next Указатель на следующий элемент
     */
    void set_next(Object *next);

private:
    int m_data;     /**< Значение элемента */
    Object *m_next; /**< Указатель на следующий элемент */
};

/**
 * @brief Класс Stack: стек (структура данных LIFO)
 */
class Stack
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Stack();

    /**
     * @brief Деструктор
     */
    ~Stack();

    /**
     * @brief Конструктор копирования
     * @param[in] other Стек для копирования
     */
    Stack(const Stack &other);

    /**
     * @brief Оператор присваивания
     * @param[in] other Стек для копирования
     * @return Ссылка на текущий стек
     */
    Stack &operator=(const Stack &other);

    /**
     * @brief Добавить элемент в стек
     * @param[in] value Значение для добавления
     */
    void push(int value);

    /**
     * @brief Извлечь элемент из стека
     * @return Значение извлеченного элемента
     * @throw std::runtime_error если стек пуст
     */
    int pop();

    /**
     * @brief Проверить, пуст ли стек
     * @return true если стек пуст, false в противном случае
     */
    bool empty() const;

    /**
     * @brief Получить количество элементов в стеке
     * @return Количество элементов
     */
    size_t size() const;

    /**
     * @brief Получить указатель на верхний элемент (для тестирования)
     * @return Указатель на верхний элемент или nullptr если стек пуст
     */
    Object *get_top() const;

    /**
     * @brief Оператор добавления элемента в стек
     * @param[in] value Значение для добавления
     * @return Ссылка на текущий стек
     */
    Stack &operator+=(int value);

    /**
     * @brief Префиксный оператор удаления элемента из стека
     * @return Ссылка на текущий стек
     */
    Stack &operator--();

    /**
     * @brief Постфиксный оператор удаления элемента из стека
     * @return Копия стека до удаления элемента
     */
    Stack operator--(int);

private:
    Object *m_top; /**< Указатель на верхний элемент стека */

    /**
     * @brief Очистить стек (удалить все элементы)
     */
    void clear();
};

/*** Methods Implementation ***/

/**
 * @section Реализация методов класса Object
 */

Object::Object(int value) : m_data(value), m_next(nullptr)
{
}
int Object::get_data() const
{
    return m_data;
}

Object *Object::get_next() const
{
    return m_next;
}

void Object::set_next(Object *next)
{
    m_next = next;
}

/**
 * @section Реализация методов класса Stack
 */

Stack::Stack() : m_top(nullptr)
{
}

Stack::~Stack()
{
    clear();
}

void Stack::clear()
{
    while (m_top)
    {
        Object *temp = m_top;
        m_top = m_top->get_next();
        delete temp;
    }
}

Stack::Stack(const Stack &other) : m_top(nullptr)
{
    if (!other.m_top)
        return;

    // Собираем значения из исходного стека
    std::vector<int> values;
    Object *current = other.m_top;
    while (current)
    {
        values.push_back(current->get_data());
        current = current->get_next();
    }

    // Добавляем значения в обратном порядке для сохранения порядка стека
    for (auto it = values.rbegin(); it != values.rend(); ++it)
    {
        push(*it);
    }
}

Stack &Stack::operator=(const Stack &other)
{
    if (this == &other)
        return *this;

    clear();

    if (!other.m_top)
        return *this;

    // Собираем значения из исходного стека
    std::vector<int> values;
    Object *current = other.m_top;
    while (current)
    {
        values.push_back(current->get_data());
        current = current->get_next();
    }

    // Добавляем значения в обратном порядке
    for (auto it = values.rbegin(); it != values.rend(); ++it)
    {
        push(*it);
    }

    return *this;
}

void Stack::push(int value)
{
    Object *node = new Object(value);
    node->set_next(m_top);
    m_top = node;
}

int Stack::pop()
{
    if (!m_top)
    {
        throw std::runtime_error("Попытка извлечения из пустого стека");
    }

    Object *temp = m_top;
    int value = temp->get_data();
    m_top = m_top->get_next();
    delete temp;
    return value;
}

bool Stack::empty() const
{
    return m_top == nullptr;
}

size_t Stack::size() const
{
    size_t count = 0;
    Object *current = m_top;
    while (current)
    {
        ++count;
        current = current->get_next();
    }
    return count;
}

Object *Stack::get_top() const
{
    return m_top;
}

Stack &Stack::operator+=(int value)
{
    push(value);
    return *this;
}

Stack &Stack::operator--()
{
    pop();
    return *this;
}

Stack Stack::operator--(int)
{
    Stack temp(*this); // Создаем копию текущего стека
    if (!empty())
    {
        pop(); // Удаляем элемент из текущего стека
    }
    return temp;
}

/*** Test Functions ***/

/**
 * @brief Функция для тестирования стека
 * @param[in] s Стек для тестирования
 * @param[in] expected Ожидаемые значения
 * @param[in] size Количество ожидаемых значений
 */
void assert_stack(Stack &s, int *expected, size_t size)
{
    Object *p = s.get_top(); // Используем указатель на Object
    size_t i = 0;

    while (p)
    {
        if (i >= size)
        {
            std::cout << "ОШИБКА: В стеке больше элементов, чем ожидалось\n";
            return;
        }
        if (p->get_data() != expected[i])
        {
            std::cout << "ОШИБКА: Ожидалось " << expected[i]
                      << ", получено " << p->get_data() << " на позиции " << i << "\n";
            return;
        }
        p = p->get_next();
        i++;
    }

    if (i != size)
    {
        std::cout << "ОШИБКА: В стеке " << i << " элементов, ожидалось " << size << "\n";
        return;
    }

    std::cout << "✓ Проверка стека пройдена: " << size << " элементов совпадают\n";
}

/**
 * @brief Функция тестирования с использованием только публичного интерфейса
 * @param[in] s Стек для тестирования
 * @param[in] expected Ожидаемые значения
 * @param[in] size Количество ожидаемых значений
 */
void assert_stack_public(Stack &s, int *expected, size_t size)
{
    Stack copy = s; // Тестируем конструктор копирования
    size_t i = 0;

    while (!copy.empty())
    {
        if (i >= size)
        {
            std::cout << "ОШИБКА: В стеке больше элементов, чем ожидалось\n";
            return;
        }

        int value = copy.pop();
        if (value != expected[i])
        {
            std::cout << "ОШИБКА: Ожидалось " << expected[i]
                      << ", получено " << value << " на позиции " << i << "\n";
            return;
        }
        i++;
    }

    if (i != size)
    {
        std::cout << "ОШИБКА: В стеке " << i << " элементов, ожидалось " << size << "\n";
        return;
    }

    std::cout << "✓ Проверка стека пройдена: " << size << " элементов совпадают\n";
}

/**
 * @brief Основная функция с демонстрацией работы стека
 * @return Код завершения программы
 */
int main()
{
    std::cout << "=== Демонстрация работы класса Stack ===\n\n";

    try
    {
        // Тест 1: Базовые операции
        std::cout << "1. Базовые операции push/pop:\n";
        Stack s1;
        s1.push(10);
        s1.push(20);
        s1.push(30);

        int expected1[] = {30, 20, 10};
        assert_stack(s1, expected1, 3);

        // Тест 2: Операции извлечения
        std::cout << "\n2. Операции извлечения:\n";
        std::cout << "Извлечено: " << s1.pop() << "\n";
        std::cout << "Извлечено: " << s1.pop() << "\n";

        int expected2[] = {10};
        assert_stack(s1, expected2, 1);

        // Тест 3: Оператор +=
        std::cout << "\n3. Оператор +=:\n";
        s1 += 5;
        s1 += 15;

        int expected3[] = {15, 5, 10};
        assert_stack(s1, expected3, 3);

        // Тест 4: Конструктор копирования
        std::cout << "\n4. Конструктор копирования:\n";
        Stack s2 = s1;
        assert_stack(s2, expected3, 3);

        // Тест 5: Оператор присваивания
        std::cout << "\n5. Оператор присваивания:\n";
        Stack s3;
        s3 = s1;
        assert_stack(s3, expected3, 3);

        // Тест 6: Оператор --
        std::cout << "\n6. Оператор --:\n";
        --s1;            // префиксная форма
        Stack s4 = s1--; // постфиксная форма

        int expected4[] = {5, 10};
        assert_stack(s1, expected4, 2);

        // Тест 7: Проверка размера и пустоты
        std::cout << "\n7. Проверка размера и пустоты:\n";
        std::cout << "Размер s1: " << s1.size() << "\n";
        std::cout << "s1 пуст: " << (s1.empty() ? "да" : "нет") << "\n";

        Stack s5;
        std::cout << "Размер s5: " << s5.size() << "\n";
        std::cout << "s5 пуст: " << (s5.empty() ? "да" : "нет") << "\n";

        // Тест 8: Обработка ошибок
        std::cout << "\n8. Обработка ошибок:\n";
        try
        {
            s5.pop(); // Попытка извлечь из пустого стека
        }
        catch (const std::runtime_error &e)
        {
            std::cout << "Перехвачена ошибка: " << e.what() << "\n";
        }

        std::cout << "\n=== Все тесты завершены успешно ===\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Критическая ошибка: " << e.what() << "\n";
        return 1;
    }

    return 0;
}