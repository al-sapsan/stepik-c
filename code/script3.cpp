/**********************************************************************
 * @file script3.cpp
 * @brief Класс GamePole: игровое поле, копирование, деструктор, методы const
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-13
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstring>

/*** Class Definition ***/
/**
 * @brief Класс для хранения игрового поля
 */
class GamePole
{
public:
    /**
     * @brief Конструктор с размерами
     * @param[in] rows строки
     * @param[in] cols столбцы
     */
    GamePole(int rows, int cols) : m_rows(rows), m_cols(cols), m_pole(nullptr)
    {
        m_pole = new char[m_rows * m_cols]();
    }
    /**
     * @brief Копирующий конструктор
     * @param[in] other другой объект
     */
    GamePole(const GamePole &other) : m_rows(other.m_rows), m_cols(other.m_cols), m_pole(nullptr)
    {
        m_pole = new char[m_rows * m_cols];
        std::memcpy(m_pole, other.m_pole, m_rows * m_cols);
    }
    /**
     * @brief Деструктор: освобождает память
     */
    ~GamePole() { delete[] m_pole; }
    /**
     * @brief Установить значение в ячейку
     * @param[in] row строка
     * @param[in] col столбец
     * @param[in] value значение
     */
    void set_item(int row, int col, char value)
    {
        m_pole[row * m_cols + col] = value;
    }
    /**
     * @brief Получить значение ячейки
     * @param[in] row строка
     * @param[in] col столбец
     * @return char
     */
    char get_item(int row, int col) const
    {
        return m_pole[row * m_cols + col];
    }
    /**
     * @brief Получить массив поля
     * @return const char*
     */
    const char *get_pole() const { return m_pole; }
    /**
     * @brief Получить размеры
     * @param[out] rows строки
     * @param[out] cols столбцы
     */
    void get_size(int &rows, int &cols) const
    {
        rows = m_rows;
        cols = m_cols;
    }

private:
    int m_rows{0}, m_cols{0};
    char *m_pole{nullptr};
};

/*** Main Function ***/
int main(void)
{
    GamePole gp(10, 7);
    gp.set_item(3, 5, '#');
    gp.set_item(4, 2, '*');
    gp.set_item(4, 4, '*');

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        return 0;
}
