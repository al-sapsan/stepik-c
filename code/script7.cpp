/**********************************************************************
 * @file script7.cpp
 * @brief Класс IntOperator: арифметика массива, деструктор обнуляет исходный массив
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-08
 **********************************************************************/

/*** Core ***/
#include <cstddef>
#include <limits>

/*** Class Definition ***/
/**
 * @brief Класс для операций над массивом int
 */
class IntOperator
{
private:
    int *data; ///< Указатель на массив int
    int size;  ///< Размер массива
    int *src;  ///< Указатель на исходный массив (для обнуления)
public:
    /**
     * @brief Конструктор по умолчанию
     */
    IntOperator() : data(nullptr), size(0), src(nullptr) {}
    /**
     * @brief Конструктор с массивом
     * @param[in] arr указатель на массив int
     * @param[in] sz размер массива
     */
    IntOperator(int *arr, int sz) : data(arr), size(sz), src(arr) {}
    /**
     * @brief Деструктор: обнуляет исходный массив
     */
    ~IntOperator()
    {
        if (src)
        {
            for (int i = 0; i < size; ++i)
                src[i] = 0;
        }
    }
    /*** Methods Implementation ***/
    /**
     * @brief Среднее арифметическое
     * @return double среднее значение
     */
    double average()
    {
        if (!data || size == 0)
            return 0.0;
        int s = 0;
        for (int i = 0; i < size; ++i)
            s += data[i];
        return static_cast<double>(s) / size;
    }
    /**
     * @brief Сумма элементов
     * @return int сумма
     */
    int sum()
    {
        if (!data || size == 0)
            return 0.0;
        int s = 0;
        for (int i = 0; i < size; ++i)
            s += data[i];
        return static_cast<double>(s) / size;
    }
    /**
     * @brief Максимум
     * @return int максимум
     */
    int max()
    {
        if (!data || size == 0)
            return 0;
        int m = data[0];
        for (int i = 1; i < size; ++i)
        {
            if (data[i] > m)
                m = data[i];
        }
        return m;
    }

    /**
     * @brief Минимум
     * @return int минимум
     */
    int min()
    {
        if (!data || size == 0)
            return 0;
        int m = data[0];
        for (int i = 1; i < size; ++i)
        {
            if (data[i] < m)
                m = data[i];
        }
        return m;
    }
};