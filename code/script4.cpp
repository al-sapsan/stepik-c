/**********************************************************************
 * @file script4.cpp
 * @brief Класс CoordsND, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-23
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс CoordsND (координаты в N-мерном пространстве)
 */
class CoordsND
{
public:
    enum
    {
        max_coords = 10
    };
    /**
     * @brief Конструктор по списку
     * @param[in] lst Массив координат
     * @param[in] sz Количество координат
     */
    CoordsND(int *lst, int sz);
    /**
     * @brief Деструктор
     */
    ~CoordsND();
    /**
     * @brief Конструктор копирования
     * @param[in] other Другой объект
     */
    CoordsND(const CoordsND &other);
    /**
     * @brief Конструктор перемещения
     * @param[in] other Другой объект
     */
    CoordsND(CoordsND &&other) noexcept;
    /**
     * @brief Оператор присваивания копированием
     * @param[in] other Другой объект
     * @return Ссылка на объект
     */
    CoordsND &operator=(const CoordsND &other);
    /**
     * @brief Получить координаты
     * @return Указатель на массив координат
     */
    int *get_coords();
    /**
     * @brief Получить размер
     * @return Количество координат
     */
    int get_size() const;

private:
    int *coords; ///< Массив координат
    int size;    ///< Количество координат
};

/*** Methods Implementation ***/
CoordsND::CoordsND(int *lst, int sz)
{
    size = (sz > max_coords) ? max_coords : sz;
    coords = new int[size];
    for (int i = 0; i < size; ++i)
        coords[i] = lst[i];
}
CoordsND::~CoordsND() { delete[] coords; }
CoordsND::CoordsND(const CoordsND &other)
{
    size = other.size;
    coords = new int[size];
    for (int i = 0; i < size; ++i)
        coords[i] = other.coords[i];
}
CoordsND::CoordsND(CoordsND &&other) noexcept
{
    size = other.size;
    coords = other.coords;
    other.coords = nullptr;
    other.size = 0;
}
CoordsND &CoordsND::operator=(const CoordsND &other)
{
    if (this != &other)
    {
        delete[] coords;
        size = other.size;
        coords = new int[size];
        for (int i = 0; i < size; ++i)
            coords[i] = other.coords[i];
    }
    return *this;
}
int *CoordsND::get_coords() { return coords; }
int CoordsND::get_size() const { return size; }
