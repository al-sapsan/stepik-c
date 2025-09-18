/**********************************************************************
 * @file script4.cpp
 * @brief Класс TicTacToe, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-18
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс TicTacToe: игровое поле крестики-нолики
 */
class TicTacToe
{
public:
    /**
     * @brief Прокси для доступа к строке
     */
    class RowProxy
    {
    public:
        RowProxy(char *row_ptr, int size) : row(row_ptr), size(size) {}
        char &operator[](int col)
        {
            if (col >= 0 && col < size)
                return row[col];
            static char dummy = 0;
            return dummy;
        }
        char operator[](int col) const
        {
            if (col >= 0 && col < size)
                return row[col];
            return 0;
        }

    private:
        char *row;
        int size;
    };
    /**
     * @brief Конструктор по умолчанию
     */
    TicTacToe();
    /**
     * @brief Получить игровое поле
     * @return const char*
     */
    const char *get_pole() const;
    /**
     * @brief Получить размер поля
     * @return int
     */
    int get_size() const;
    /**
     * @brief Оператор доступа к строке
     * @param[in] row индекс строки
     * @return RowProxy
     */
    RowProxy operator[](int row);
    /**
     * @brief Оператор доступа к строке (const)
     * @param[in] row индекс строки
     * @return RowProxy
     */
    RowProxy operator[](int row) const;

private:
    enum
    {
        size_pole = 3
    };
    char pole[size_pole * size_pole]{0};
};

/*** Methods Implementation ***/
TicTacToe::TicTacToe() {}
const char *TicTacToe::get_pole() const { return pole; }
int TicTacToe::get_size() const { return size_pole; }
TicTacToe::RowProxy TicTacToe::operator[](int row)
{
    if (row >= 0 && row < size_pole)
        return RowProxy(&pole[row * size_pole], size_pole);
    return RowProxy(nullptr, size_pole);
}
TicTacToe::RowProxy TicTacToe::operator[](int row) const
{
    if (row >= 0 && row < size_pole)
        return RowProxy(const_cast<char *>(&pole[row * size_pole]), size_pole);
    return RowProxy(nullptr, size_pole);
}

/*** Main ***/
int main(void)
{
    TicTacToe *ptr_game = new TicTacToe;
    (*ptr_game)[0][0] = 'x';
    (*ptr_game)[1][1] = 'x';
    (*ptr_game)[2][2] = 'x';
    __ASSERT_TESTS__
    delete ptr_game;
    ptr_game = nullptr;
    return 0;
}
