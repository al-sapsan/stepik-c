/**********************************************************************
 * @file script6.cpp
 * @brief Класс Vector3D: конструкторы из строки и массива, методы-геттеры
 * @version 2.0 (Improved Embedded C++ style)
 * @date 2025-09-08
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstring> // для strncpy, strtok
#include <cstdlib> // для atoi
#include <cctype>  // для isspace

/*** Class Definition ***/
/**
 * @brief Класс для хранения 3D-вектора с разными конструкторами
 */
class Vector3D
{
public:
    /*** Constants ***/
    static constexpr size_t MAX_INPUT_LENGTH = 127;
    static constexpr int DEFAULT_COORDINATE = 0;

    /*** Constructors ***/
    /**
     * @brief Конструктор по умолчанию
     */
    Vector3D() noexcept : m_x(DEFAULT_COORDINATE), m_y(DEFAULT_COORDINATE), m_z(DEFAULT_COORDINATE) {}

    /**
     * @brief Конструктор из отдельных координат
     */
    Vector3D(int x, int y, int z) noexcept : m_x(x), m_y(y), m_z(z) {}

    /**
     * @brief Конструктор из C-строки
     * @param[in] str C-строка с координатами
     * @details Извлекает первые три числа, преобразует к int, нечисловое = 0
     */
    explicit Vector3D(const char *str) noexcept : m_x(DEFAULT_COORDINATE), m_y(DEFAULT_COORDINATE), m_z(DEFAULT_COORDINATE)
    {
        if (str == nullptr)
            return;

        // Безопасное копирование
        char buffer[MAX_INPUT_LENGTH + 1] = {0};
        std::strncpy(buffer, str, MAX_INPUT_LENGTH);

        // Парсинг с помощью strtok (оригинальный подход)
        char *token = std::strtok(buffer, " ,;:");
        if (token)
        {
            m_x = safe_atoi(token);
            token = std::strtok(nullptr, " ,;:");
        }
        if (token)
        {
            m_y = safe_atoi(token);
            token = std::strtok(nullptr, " ,;:");
        }
        if (token)
        {
            m_z = safe_atoi(token);
        }
    }

    /**
     * @brief Конструктор из массива int
     * @param[in] arr массив int (минимум 3 элемента)
     */
    explicit Vector3D(const int arr[]) noexcept : m_x(DEFAULT_COORDINATE), m_y(DEFAULT_COORDINATE), m_z(DEFAULT_COORDINATE)
    {
        if (arr != nullptr)
        {
            m_x = arr[0];
            m_y = arr[1];
            m_z = arr[2];
        }
    }

    /**
     * @brief Конструктор из std::string
     */
    explicit Vector3D(const std::string &str) noexcept : Vector3D(str.c_str()) {}

    /*** Methods ***/
    /**
     * @brief Получить координаты
     * @param[out] x координата X
     * @param[out] y координата Y
     * @param[out] z координата Z
     */
    void get_coords(int &x, int &y, int &z) const noexcept
    {
        x = m_x;
        y = m_y;
        z = m_z;
    }

    /**
     * @brief Получить координату X
     */
    int get_x() const noexcept { return m_x; }

    /**
     * @brief Получить координату Y
     */
    int get_y() const noexcept { return m_y; }

    /**
     * @brief Получить координату Z
     */
    int get_z() const noexcept { return m_z; }

    /**
     * @brief Установить координаты
     */
    void set_coords(int x, int y, int z) noexcept
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    /**
     * @brief Сброс координат к значениям по умолчанию
     */
    void reset() noexcept
    {
        m_x = DEFAULT_COORDINATE;
        m_y = DEFAULT_COORDINATE;
        m_z = DEFAULT_COORDINATE;
    }

private:
    int m_x;
    int m_y;
    int m_z;

    /*** Private Helpers ***/
    /**
     * @brief Безопасное преобразование строки в int
     * @param[in] str Строка для преобразования
     * @return Преобразованное число или 0 при ошибке
     */
    static int safe_atoi(const char *str) noexcept
    {
        if (str == nullptr || *str == '\0')
            return 0;
        return std::atoi(str);
    }

    /**
     * @brief Пропустить разделители
     * @param[in,out] ptr Указатель на текущую позицию в строке
     */
    static void skip_delimiters(const char *&ptr) noexcept
    {
        if (ptr == nullptr)
            return;
        while (*ptr && (std::isspace(*ptr) || *ptr == ',' || *ptr == ';' || *ptr == ':'))
        {
            ++ptr;
        }
    }

    /**
     * @brief Извлечь следующее число из строки
     * @param[in,out] ptr Указатель на текущую позицию в строке
     * @return Извлеченное число
     */
    static int extract_next_number(const char *&ptr) noexcept
    {
        if (ptr == nullptr || *ptr == '\0')
            return 0;

        // Пропускаем разделители
        skip_delimiters(ptr);
        if (*ptr == '\0')
            return 0;

        // Извлекаем число
        int value = safe_atoi(ptr);

        // Пропускаем цифры и двигаем указатель
        while (*ptr && (std::isdigit(*ptr) || *ptr == '-' || *ptr == '+'))
        {
            ++ptr;
        }

        return value;
    }
};

/*** Пример использования ***/
int main()
{
    // Разные способы создания объектов
    Vector3D v1;                // (0, 0, 0)
    Vector3D v2("10 20 30");    // (10, 20, 30)
    Vector3D v3("5, -7; 12");   // (5, -7, 12)
    Vector3D v4("1.5 2.8 3.2"); // (1, 2, 3)

    int arr[] = {15, 25, 35};
    Vector3D v5(arr); // (15, 25, 35)

    Vector3D v6(100, 200, 300); // (100, 200, 300)

    return 0;
}