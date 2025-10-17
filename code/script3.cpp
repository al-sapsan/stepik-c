/************************************************************************
 * @file script3.cpp
 * @brief Dynamic Array Implementation (Vector) and Exception (VectorIndexError)
 * @section DESCRIPTION
 * This file contains the implementation of a dynamic array class Vector<T>
 * and the exception class VectorIndexError for index validation.
 * @version 1.0
 * @date 2025-10-17
 ************************************************************************/

#include <cstddef>
#include <exception>
#include <algorithm>

/**
 * @brief Исключение для некорректного индекса динамического массива
 */
/**
 * @class VectorIndexError
 * @brief Исключение для некорректного индекса динамического массива
 * @details Генерируется при попытке обращения к несуществующему элементу массива Vector.
 */
class VectorIndexError : public std::exception
{
public:
    /**
     * @brief Получить текст сообщения об ошибке
     * @return Строка с описанием ошибки
     */
    const char *what() const noexcept override
    {
        return "Invalid element index.";
    }
};
/**
 * @class Vector
 * @brief Динамический массив с автоматическим увеличением размера
 * @details Класс реализует динамический массив с операциями добавления, удаления, вставки, индексации и объединения.
 * @tparam T Тип элементов массива
 */
template <typename T>
class Vector
{
    // ...existing code...
};
size_t capacity_{8};

/**
 * @class Vector
 * @brief Динамический массив с автоматическим увеличением размера
 * @details Класс реализует динамический массив с операциями добавления, удаления, вставки, индексации и объединения.
 * @tparam T Тип элементов массива
 */
template <typename T>
class Vector
{
private:
    T *data{nullptr};    ///< Указатель на массив данных
    size_t length{0};    ///< Текущее количество элементов
    size_t capacity_{8}; ///< Физический размер массива

    /**
     * @brief Проверка индекса на корректность
     * @param idx Индекс
     * @throws VectorIndexError При некорректном индексе
     */
    void check_index(int idx) const
    {
        if (idx < 0 || static_cast<size_t>(idx) >= length)
            throw VectorIndexError();
    }
    /**
     * @brief Изменить размер массива
     * @param new_cap Новый размер
     */
    void resize(size_t new_cap)
    {
        T *new_data = new T[new_cap]{};
        for (size_t i = 0; i < length; ++i)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
        capacity_{new_cap};
    }

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Vector() : data(new T[capacity_]{}), length(0) {}

    /**
     * @brief Конструктор копирования
     * @param other Копируемый объект
     */
    Vector(const Vector &other) : data(new T[other.capacity_]{}), length(other.length), capacity_(other.capacity_)
    {
        for (size_t i = 0; i < length; ++i)
            data[i] = other.data[i];
    }

    /**
     * @brief Оператор присваивания
     * @param other Копируемый объект
     * @return Ссылка на текущий объект
     */
    Vector &operator=(const Vector &other)
    {
        if (this == &other)
            return *this;
        delete[] data;
        capacity_ = other.capacity_;
        length = other.length;
        data = new T[capacity_]{};
        for (size_t i = 0; i < length; ++i)
            data[i] = other.data[i];
        return *this;
    }

    /**
     * @brief Деструктор
     */
    ~Vector() { delete[] data; }

    /**
     * @brief Добавить элемент в конец массива
     * @param value Значение
     */
    void push_back(const T &value)
    {
        if (length == capacity_)
            resize(capacity_ * 2);
        data[length++] = value;
    }

    /**
     * @brief Добавить элемент в начало массива
     * @param value Значение
     */
    void push_front(const T &value)
    {
        if (length == capacity_)
            resize(capacity_ * 2);
        for (size_t i = length; i > 0; --i)
            data[i] = data[i - 1];
        data[0] = value;
        ++length;
    }

    /**
     * @brief Удалить последний элемент массива
     */
    void pop_back()
    {
        if (length > 0)
            --length;
    }

    /**
     * @brief Удалить первый элемент массива
     */
    void pop_front()
    {
        if (length == 0)
            return;
        for (size_t i = 0; i < length - 1; ++i)
            data[i] = data[i + 1];
        --length;
    }

    /**
     * @brief Вставить элемент по индексу
     * @param idx Индекс
     * @param value Значение
     * @throws VectorIndexError При некорректном индексе
     */
    void insert(int idx, const T &value)
    {
        if (idx < 0 || static_cast<size_t>(idx) > length)
            throw VectorIndexError();
        if (length == capacity_)
            resize(capacity_ * 2);
        for (size_t i = length; i > static_cast<size_t>(idx); --i)
            data[i] = data[i - 1];
        data[idx] = value;
        ++length;
    }

    /**
     * @brief Удалить элемент по индексу
     * @param idx Индекс
     * @throws VectorIndexError При некорректном индексе
     */
    void remove(int idx)
    {
        check_index(idx);
        for (size_t i = static_cast<size_t>(idx); i < length - 1; ++i)
            data[i] = data[i + 1];
        --length;
    }

    /**
     * @brief Оператор индексации (изменяемый)
     * @param idx Индекс
     * @return Ссылка на элемент
     * @throws VectorIndexError При некорректном индексе
     */
    T &operator[](int idx)
    {
        check_index(idx);
        return data[idx];
    }

    /**
     * @brief Оператор индексации (константный)
     * @param idx Индекс
     * @return Константная ссылка на элемент
     * @throws VectorIndexError При некорректном индексе
     */
    const T &operator[](int idx) const
    {
        check_index(idx);
        return data[idx];
    }

    /**
     * @brief Получить текущий размер массива
     * @return Количество элементов
     */
    size_t capacity() const { return capacity_; }

    /**
     * @brief Получить количество элементов
     * @return Количество элементов
     */
    size_t size() const { return length; }

    /**
     * @brief Проверить, пуст ли массив
     * @return true, если массив пуст
     */
    bool empty() const { return length == 0; }

    /**
     * @brief Очистить массив
     */
    void clear() { length = 0; }

    /**
     * @brief Оператор объединения массивов (+=)
     * @param other Массив для объединения
     * @return Ссылка на текущий объект
     */
    Vector &operator+=(const Vector &other)
    {
        for (size_t i = 0; i < other.length; ++i)
            push_back(other.data[i]);
        return *this;
    }

    /**
     * @brief Оператор объединения массивов (+)
     * @param other Массив для объединения
     * @return Новый объект Vector, содержащий объединенные элементы
     */
    Vector operator+(const Vector &other) const
    {
        Vector res(*this);
        res += other;
        return res;
    }
};
