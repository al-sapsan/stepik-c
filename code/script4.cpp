/**********************************************************************
 * @file script4.cpp
 * @brief Класс GamePole: синглтон, запрет копирования, методы const
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-13
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstring>

/*** Class Definition ***/
/**
 * @brief Класс для хранения игрового поля (синглтон)
 */
class GamePole
{
public:
    /**
     * @brief Получить/создать единственный экземпляр
     * @param[in] rows строки
     * @param[in] cols столбцы
     * @return указатель на GamePole
     */
    static GamePole *init(int rows, int cols)
    {
        if (!m_instance)
            m_instance = new GamePole(rows, cols);
        return m_instance;
    }
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
    // Запретить копирование
    GamePole(const GamePole &) = delete;
    GamePole &operator=(const GamePole &) = delete;
    /**
     * @brief Деструктор: освобождает память
     */
    ~GamePole() { delete[] m_pole; }

private:
    GamePole(int rows, int cols) : m_rows(rows), m_cols(cols), m_pole(nullptr)
    {
        m_pole = new char[m_rows * m_cols]();
    }
    static GamePole *m_instance;
    int m_rows{0}, m_cols{0};
    char *m_pole{nullptr};
};

/*** Static Members Initialization ***/
GamePole *GamePole::m_instance = nullptr;

/*** Main Function ***/
int main(void)
{
    GamePole *ptr_pl = GamePole::init(5, 10);
    ptr_pl->set_item(1, 1, '@');
    ptr_pl->set_item(4, 9, '#');
    ptr_pl->set_item(3, 2, '*');

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        // память не освобождается, т.к. синглтон живёт до конца программы
        return 0;
}
