/**********************************************************************
 * @file script7.cpp
 * @brief Класс IntOperator: арифметика массива, деструктор обнуляет исходный массив
 * @version 2.0 (Improved Embedded C++ style)
 * @date 2025-09-08
 **********************************************************************/

/*** Core ***/
#include <cstddef>
#include <limits>
#include <algorithm> // для std::min, std::max

/*** Class Definition ***/
/**
 * @brief Класс для операций над массивом int
 */
class IntOperator
{
public:
    /*** Constants ***/
    static constexpr int DEFAULT_VALUE = 0;

    /*** Constructors ***/
    /**
     * @brief Конструктор по умолчанию
     */
    IntOperator() noexcept : m_data(nullptr), m_size(0), m_original(nullptr), m_owns_data(false) {}

    /**
     * @brief Конструктор с массивом
     * @param[in] arr указатель на массив int
     * @param[in] sz размер массива
     * @param[in] own_data флаг владения данными (по умолчанию true)
     */
    explicit IntOperator(int *arr, int sz, bool own_data = true) noexcept
        : m_data(arr), m_size(sz), m_original(arr), m_owns_data(own_data)
    {
        if (sz < 0)
            m_size = 0;
    }

    /**
     * @brief Запрет копирования (правило пяти)
     */
    IntOperator(const IntOperator &) = delete;
    IntOperator &operator=(const IntOperator &) = delete;

    /**
     * @brief Конструктор перемещения
     */
    IntOperator(IntOperator &&other) noexcept
        : m_data(other.m_data), m_size(other.m_size),
          m_original(other.m_original), m_owns_data(other.m_owns_data)
    {
        other.m_data = nullptr;
        other.m_size = 0;
        other.m_original = nullptr;
        other.m_owns_data = false;
    }

    /**
     * @brief Оператор перемещения
     */
    IntOperator &operator=(IntOperator &&other) noexcept
    {
        if (this != &other)
        {
            cleanup(); // Освобождаем текущие ресурсы

            m_data = other.m_data;
            m_size = other.m_size;
            m_original = other.m_original;
            m_owns_data = other.m_owns_data;

            other.m_data = nullptr;
            other.m_size = 0;
            other.m_original = nullptr;
            other.m_owns_data = false;
        }
        return *this;
    }

    /**
     * @brief Деструктор: обнуляет исходный массив если владеем данными
     */
    ~IntOperator() noexcept
    {
        cleanup();
    }

public:
    /*** Methods ***/
    /**
     * @brief Среднее арифметическое
     * @return double среднее значение
     */
    double average() const noexcept
    {
        if (!is_valid())
            return 0.0;

        long long sum = 0; // Используем long long для избежания переполнения
        for (int i = 0; i < m_size; ++i)
        {
            sum += m_data[i];
        }
        return static_cast<double>(sum) / m_size;
    }

    /**
     * @brief Сумма элементов
     * @return int сумма
     */
    int sum() const noexcept
    {
        if (!is_valid())
            return 0;

        int result = 0;
        for (int i = 0; i < m_size; ++i)
        {
            result += m_data[i];
        }
        return result;
    }

    /**
     * @brief Максимум
     * @return int максимум
     */
    int max() const noexcept
    {
        if (!is_valid())
            return 0;

        int result = m_data[0];
        for (int i = 1; i < m_size; ++i)
        {
            if (m_data[i] > result)
            {
                result = m_data[i];
            }
        }
        return result;
    }

    /**
     * @brief Минимум
     * @return int минимум
     */
    int min() const noexcept
    {
        if (!is_valid())
            return 0;

        int result = m_data[0];
        for (int i = 1; i < m_size; ++i)
        {
            if (m_data[i] < result)
            {
                result = m_data[i];
            }
        }
        return result;
    }

    /**
     * @brief Получить размер массива
     */
    int get_size() const noexcept { return m_size; }

    /**
     * @brief Проверить валидность данных
     */
    bool is_data_valid() const noexcept { return is_valid(); }

    /**
     * @brief Освободить владение данными
     */
    void release_ownership() noexcept { m_owns_data = false; }

    /**
     * @brief Получить владение данными
     */
    void claim_ownership() noexcept { m_owns_data = true; }

    /**
     * @brief Сбросить массив к значениям по умолчанию
     */
    void reset() noexcept
    {
        if (is_valid())
        {
            std::fill_n(m_data, m_size, DEFAULT_VALUE);
        }
    }

private:
    int *m_data;      ///< Указатель на массив int
    int m_size;       ///< Размер массива
    int *m_original;  ///< Указатель на исходный массив (для обнуления)
    bool m_owns_data; ///< Флаг владения данными

private:
    /**
     * @brief Очистка ресурсов
     */
    void cleanup() noexcept
    {
        if (m_owns_data && m_original && m_size > 0)
        {
            std::fill_n(m_original, m_size, DEFAULT_VALUE);
        }
        m_data = nullptr;
        m_size = 0;
        m_original = nullptr;
        m_owns_data = false;
    }

    /**
     * @brief Проверка валидности данных
     * @return true если данные валидны
     */
    bool is_valid() const noexcept
    {
        return m_data != nullptr && m_size > 0;
    }
};

/*** Пример использования ***/
int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    // С владением данными (обнулит при destruction)
    IntOperator op1(arr, 5, true);

    // Без владения данными (не обнулит)
    IntOperator op2(arr, 5, false);

    // Использование методов
    double avg = op1.average();
    int total = op1.sum();
    int max_val = op1.max();
    int min_val = op1.min();

    return 0;
}