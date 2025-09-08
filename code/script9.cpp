/**********************************************************************
 * @file script9.cpp
 * @brief Класс VectorN: вектор N-мерный, память динамическая, вывод при удалении
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-08
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstddef>

/*** Class Definition ***/
/**
 * @brief Класс для хранения N-мерного вектора
 */
class VectorN
{
private:
    int dims;      ///< Размерность вектора
    short *coords; ///< Указатель на массив координат
public:
    /**
     * @brief Конструктор по размерности (все координаты 0)
     * @param[in] n размерность
     */
    VectorN(int n) : dims(n), coords(nullptr)
    {
        if (dims > 0)
        {
            coords = new short[dims]{};
        }
    }
    /**
     * @brief Конструктор по значениям
     * @param[in] a первая координата
     * @param[in] b вторая координата
     */
    VectorN(short a, short b) : dims(2), coords(nullptr)
    {
        coords = new short[2]{a, b};
    }
    /**
     * @brief Конструктор по массиву
     * @param[in] arr массив координат
     * @param[in] n размерность
     */
    VectorN(const short *arr, int n) : dims(n), coords(nullptr)
    {
        if (dims > 0 && arr)
        {
            coords = new short[dims];
            for (int i = 0; i < dims; ++i)
                coords[i] = arr[i];
        }
    }
    /**
     * @brief Деструктор: освобождает память и выводит координаты
     */
    ~VectorN()
    {
        if (coords)
        {
            std::cout << "delete coords:";
            for (int i = 0; i < dims; ++i)
            {
                std::cout << (i ? " " : " ") << coords[i];
            }
            std::cout << std::endl;
            delete[] coords;
        }
    }
    /**
     * @brief Получить координаты
     * @return указатель на массив координат
     */
    const short *get_coords() { return coords; }
    /**
     * @brief Получить размерность
     * @return размерность
     */
    int get_dims() { return dims; }
};