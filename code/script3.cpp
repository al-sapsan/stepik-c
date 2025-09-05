/**********************************************************************
 * @file script3.cpp
 * @brief Класс Table: приватные размеры, методы, main
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-05
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс для хранения размеров стола
 */
class Table
{
private:
    unsigned m_width_u32;
    unsigned m_height_u32;
    unsigned m_depth_u32;

public:
    /*** Methods Implementation ***/
    /**
     * @brief Установить размеры стола
     * @param[in] width ширина
     * @param[in] height высота
     * @param[in] depth глубина
     */
    void set_dims(unsigned width, unsigned height, unsigned depth)
    {
        m_width_u32 = width;
        m_height_u32 = height;
        m_depth_u32 = depth;
    }
    /**
     * @brief Получить ширину
     * @return ширина
     */
    unsigned get_width() { return m_width_u32; }
    /**
     * @brief Получить высоту
     * @return высота
     */
    unsigned get_height() { return m_height_u32; }
    /**
     * @brief Получить глубину
     * @return глубина
     */
    unsigned get_depth() { return m_depth_u32; }
};

/*** Main Function ***/
int main(void)
{
    Table t1, t2, t3;
    t1.set_dims(10, 10, 5);
    t2.set_dims(7, 20, 7);
    t3.set_dims(12, 40, 6);
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)
        return 0;
}
