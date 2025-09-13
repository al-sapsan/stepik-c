/**********************************************************************
 * @file script6.cpp
 * @brief Класс DeskTop: синглтон, get_instance, get_width, get_height
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-12
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс DeskTop (паттерн синглтон)
 */
class DeskTop
{
public:
    /**
     * @brief Получить единственный экземпляр
     * @param[in] width ширина
     * @param[in] height высота
     * @return указатель на DeskTop
     */
    static DeskTop *get_instance(int width, int height);
    /**
     * @brief Получить ширину
     * @return int
     */
    int get_width();
    /**
     * @brief Получить высоту
     * @return int
     */
    int get_height();

private:
    static DeskTop *m_instance;
    int m_width{0}, m_height{0};
    DeskTop(int width, int height) : m_width(width), m_height(height) {}
    DeskTop(const DeskTop &) = delete;
    DeskTop &operator=(const DeskTop &) = delete;
};

/*** Static Members Initialization ***/
DeskTop *DeskTop::m_instance = nullptr;

/*** Methods Implementation ***/
DeskTop *DeskTop::get_instance(int width, int height)
{
    if (!m_instance)
        m_instance = new DeskTop(width, height);
    return m_instance;
}

int DeskTop::get_width() { return m_width; }
int DeskTop::get_height() { return m_height; }

/*** Main Function ***/
int main(void)
{
    DeskTop *ptr_desk = DeskTop::get_instance(500, 200);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        // память не освобождается, т.к. синглтон живёт до конца программы
        return 0;
}
