/**********************************************************************
 * @file script6.cpp
 * @brief Класс Notes: приватные поля, методы, main
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-05
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Class Definition ***/
/**
 * @brief Класс для хранения информации о заметке
 */
class Notes
{
private:
    std::string m_title_str;
    std::string m_author_str;
    int m_pages_i32;

public:
    /*** Function Prototypes ***/
    /**
     * @brief Задать данные заметки
     * @param[in] title название
     * @param[in] author автор
     * @param[in] pages число страниц
     */
    void set_data(const std::string &title, const std::string &author, int pages)
    {
        m_title_str = title;
        m_author_str = author;
        m_pages_i32 = pages;
    }
    /**
     * @brief Задать данные из другой заметки
     * @param[in] note объект Notes
     */
    void set_data(const Notes &note)
    {
        m_title_str = note.m_title_str;
        m_author_str = note.m_author_str;
        m_pages_i32 = note.m_pages_i32;
    }
    /**
     * @brief Получить название
     * @return ссылка на название
     */
    const std::string &get_title() { return m_title_str; }
    /**
     * @brief Получить автора
     * @return ссылка на автора
     */
    const std::string &get_author() { return m_author_str; }
    /**
     * @brief Получить число страниц
     * @return число страниц
     */
    int get_pages() { return m_pages_i32; }
};

/*** Main Function ***/
int main(void)
{
    Notes *ptr_note1 = new Notes;
    Notes *ptr_note2 = new Notes;
    ptr_note1->set_data("Фантазия экспромт", "Ф. Шопен", 5);
    ptr_note2->set_data(*ptr_note1);
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)
        delete ptr_note1;
    ptr_note1 = nullptr; // <- тренируем мышечную память
    delete ptr_note2;
    ptr_note2 = nullptr;
    return 0;
}
