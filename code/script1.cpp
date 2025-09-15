/**********************************************************************
 * @file script1.cpp
 * @brief Класс CellItem: конструкторы, const-геттеры, set_data
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-13
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс для хранения элемента ячейки
 */
class CellItem
{
public:
    /**
     * @brief Конструктор с двумя параметрами
     * @param[in] row строка
     * @param[in] col столбец
     */
    CellItem(int row, int col) : m_row(row), m_col(col), m_data(0.0) {}
    /**
     * @brief Конструктор с тремя параметрами
     * @param[in] row строка
     * @param[in] col столбец
     * @param[in] data значение
     */
    CellItem(int row, int col, double data) : m_row(row), m_col(col), m_data(data) {}
    /**
     * @brief Получить значение
     * @return double
     */
    double get_data() const { return m_data; }
    /**
     * @brief Получить строку
     * @return int
     */
    int get_row() const { return m_row; }
    /**
     * @brief Получить столбец
     * @return int
     */
    int get_col() const { return m_col; }
    /**
     * @brief Установить значение
     * @param[in] d значение
     */
    void set_data(double d) { m_data = d; }

private:
    int m_row{0}, m_col{0};
    double m_data{0.0};
};

/*** Main Function ***/
int main(void)
{
    CellItem cell(5, 7, 0.79);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        return 0;
}
