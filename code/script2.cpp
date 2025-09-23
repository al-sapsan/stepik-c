/**********************************************************************
 * @file script2.cpp
 * @brief Класс SquareValue, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-23
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Class Definition ***/
/**
 * @brief Класс SquareValue
 */
class SquareValue
{
private:
    unsigned m_value; ///< Квадрат числа
public:
    /**
     * @brief Конструктор по умолчанию
     */
    SquareValue() : m_value(0) {}
    /**
     * @brief Конструктор с параметром
     * @param[in] val Число
     */
    SquareValue(int val) : m_value(static_cast<unsigned>(val * val)) {}
    /**
     * @brief Оператор присваивания
     * @param[in] val Число
     * @return Ссылка на объект
     */
    SquareValue &operator=(int val)
    {
        m_value = static_cast<unsigned>(val * val);
        return *this;
    }
    /**
     * @brief Оператор преобразования к unsigned
     * @return Квадрат числа
     */
    operator unsigned() const { return m_value; }
    /**
     * @brief Получить значение
     * @return Квадрат числа
     */
    unsigned get_value() const { return m_value; }
};

int main()
{
    // Создание объекта и ссылок
    SquareValue sq(9);
    SquareValue &lnk_sq = sq;
    SquareValue &&lnk_r_sq = SquareValue(9);

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
