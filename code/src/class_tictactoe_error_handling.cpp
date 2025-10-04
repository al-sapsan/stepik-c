/************************************************************************
 * @file script3.cpp
 * @brief Класс TicTacToe для игры крестики-нолики
 * @version 1.0 (Embedded C++ bare-metal/RTOS)
 * @date 2025-10-04
 *
 * @warning Не использовать без проверки индексов!
 *************************************************************************/

#include <iostream>
#include <stdexcept>

/********** Exception Classes **********/

// == < Class ExceptionIndexError > == //
/**
 * @brief Класс исключения для ошибок индексации игрового поля
 */
class ExceptionIndexError
{
    int m_row{0}; ///< Ошибочный индекс строки
    int m_col{0}; ///< Ошибочный индекс столбца
public:
    /**
     * @brief Конструктор исключения
     * @param row Индекс строки
     * @param col Индекс столбца
     */
    ExceptionIndexError(int row, int col) : m_row(row), m_col(col) {}
    /**
     * @brief Получить ошибочный индекс строки
     */
    int get_row() const { return m_row; }
    /**
     * @brief Получить ошибочный индекс столбца
     */
    int get_col() const { return m_col; }
};

/************ Class Definition ***********/

// == < Class TicTacToe > == //
/**
 * @brief Класс для игры крестики-нолики
 */
class TicTacToe
{
public:
    enum
    {
        size_pole = 3
    };

private:
    char m_pole[size_pole * size_pole]{0}; ///< игровое поле

    // Вложенный прокси-класс для доступа к строке
    class RowProxy
    {
        TicTacToe &m_game;
        int m_row;

    public:
        RowProxy(TicTacToe &game, int row) : m_game(game), m_row(row) {}
        char &operator[](int col)
        {
            if (m_row < 0 || m_row >= size_pole || col < 0 || col >= size_pole)
                throw ExceptionIndexError(m_row, col);
            return m_game.m_pole[m_row * size_pole + col];
        }
        const char &operator[](int col) const
        {
            if (m_row < 0 || m_row >= size_pole || col < 0 || col >= size_pole)
                throw ExceptionIndexError(m_row, col);
            return m_game.m_pole[m_row * size_pole + col];
        }
    };

public:
    const char *get_pole() const { return m_pole; }
    int get_size() const { return size_pole; }

    // Оператор для доступа к строке
    RowProxy operator[](int row)
    {
        return RowProxy(*this, row);
    }
    const RowProxy operator[](int row) const
    {
        return RowProxy(const_cast<TicTacToe &>(*this), row);
    }
};

/********** Main Function **********/

int main()
{
    TicTacToe game;
    try
    {
        game[0][1] = 'o';
        game[1][1] = 'x';
        game[4][2] = 'x';
    }
    catch (const ExceptionIndexError &ex)
    {
        std::cout << "Incorrect index: " << ex.get_row() << ", " << ex.get_col() << std::endl;
    }

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
