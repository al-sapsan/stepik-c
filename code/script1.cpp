/************************************************************************
 * @file script1.cpp
 * @brief Класс PointND для представления точки в N-мерном пространстве
 * @version 1.0 (Embedded C++ bare-metal/RTOS)
 * @date 2025-10-04
 *
 * @warning Не использовать без проверки индексов!
 *************************************************************************/

#include <cstddef>
#include <exception>

/********** Exception Classes **********/

/**
 * @brief Класс исключения для ошибок индексации
 */
class IndexError : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Index Error for PointND";
    }
};

/************ Class Prototypes ***********/

// == < Class PointND > == //
/**
 * @brief Класс для представления точки в N-мерном пространстве
 */
class PointND
{
    double *m_coords{nullptr}; ///< координаты точки
    size_t m_dims{0};          ///< число координат
public:
    PointND() noexcept = default;

    explicit PointND(const double *cds, size_t len)
        : m_coords(nullptr), m_dims(len)
    {
        if (m_dims > 0 && cds != nullptr)
        {
            m_coords = new double[m_dims];
            for (size_t i = 0; i < m_dims; ++i)
                m_coords[i] = cds[i];
        }
    }

    ~PointND() { delete[] m_coords; }

    PointND(const PointND &other)
        : m_coords(nullptr), m_dims(other.m_dims)
    {
        if (m_dims > 0 && other.m_coords != nullptr)
        {
            m_coords = new double[m_dims];
            for (size_t i = 0; i < m_dims; ++i)
                m_coords[i] = other.m_coords[i];
        }
    }

    PointND &operator=(const PointND &other)
    {
        if (this != &other)
        {
            delete[] m_coords;
            m_dims = other.m_dims;
            m_coords = (m_dims > 0) ? new double[m_dims] : nullptr;
            for (size_t i = 0; i < m_dims; ++i)
                m_coords[i] = other.m_coords[i];
        }
        return *this;
    }

    size_t get_dims() const noexcept { return m_dims; }

    double operator[](size_t idx) const
    {
        if (idx >= m_dims)
            throw IndexError();
        return m_coords[idx];
    }

    double &operator[](size_t idx)
    {
        if (idx >= m_dims)
            throw IndexError();
        return m_coords[idx];
    }
};

/********** Main Function **********/

int main(void)
{
    double coords[] = {0.1, 0.2, 0.5, -1.4};
    PointND pt(coords, sizeof(coords) / sizeof(coords[0]));

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
};
