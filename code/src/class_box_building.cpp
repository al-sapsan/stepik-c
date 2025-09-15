/**********************************************************************
 * @file script2.cpp
 * @brief Класс BoxDims: габариты, объём, деструктор, методы const
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-13
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс для хранения габаритов предмета
 */
class BoxDims
{
public:
    /**
     * @brief Конструктор для 1D
     */
    BoxDims(unsigned size_1) : m_dimension(1), m_dims(new unsigned[1]{size_1}) {}
    /**
     * @brief Конструктор для 2D
     */
    BoxDims(unsigned size_1, unsigned size_2) : m_dimension(2), m_dims(new unsigned[2]{size_1, size_2}) {}
    /**
     * @brief Конструктор для 3D
     */
    BoxDims(unsigned size_1, unsigned size_2, unsigned size_3) : m_dimension(3), m_dims(new unsigned[3]{size_1, size_2, size_3}) {}
    /**
     * @brief Конструктор с массивом
     * @param[in] ds массив габаритов
     * @param[in] size_ds размер массива
     */
    BoxDims(const unsigned *ds, unsigned short size_ds) : m_dimension(size_ds), m_dims(new unsigned[size_ds])
    {
        for (unsigned short i = 0; i < size_ds; ++i)
            m_dims[i] = ds[i];
    }
    /**
     * @brief Деструктор: освобождает память
     */
    ~BoxDims() { delete[] m_dims; }
    /**
     * @brief Задать новые габариты
     * @param[in] ds массив габаритов
     */
    void set_dims(unsigned *ds)
    {
        for (unsigned short i = 0; i < m_dimension; ++i)
            m_dims[i] = ds[i];
    }
    /**
     * @brief Получить размерность
     * @return unsigned short
     */
    unsigned short get_dimension() const { return m_dimension; }
    /**
     * @brief Получить массив габаритов
     * @return const unsigned*
     */
    const unsigned *get_dims() const { return m_dims; }
    /**
     * @brief Получить объём
     * @return unsigned
     */
    unsigned get_volume() const
    {
        unsigned v = 1;
        for (unsigned short i = 0; i < m_dimension; ++i)
            v *= m_dims[i];
        return v;
    }

private:
    unsigned short m_dimension{0}; ///< размерность
    unsigned *m_dims{nullptr};     ///< массив габаритов
};

/*** Main Function ***/
int main(void)
{
    BoxDims box(3, 10, 5);

    return 0;
}
