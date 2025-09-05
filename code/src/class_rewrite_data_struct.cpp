/**********************************************************************
 * @file script8.cpp
 * @brief struct Person: приватные поля, методы, main
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-05
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Struct Definition ***/
/**
 * @brief Структура для хранения информации о человеке
 */
struct Person
{
private:
    std::string m_fio_str;  ///< ФИО
    std::string m_job_str;  ///< работа
    unsigned char m_old_u8; ///< возраст
public:
    /*** Function Prototypes ***/
    /**
     * @brief Задать данные человека
     * @param[in] fio ФИО
     * @param[in] job работа
     * @param[in] old возраст
     */
    void set_person_data(const std::string &fio, const std::string &job, unsigned char old)
    {
        m_fio_str = fio;
        m_job_str = job;
        m_old_u8 = old;
    }
    /**
     * @brief Задать данные из другого объекта
     * @param[in] p объект Person
     */
    void set_person_data(const Person &p)
    {
        m_fio_str = p.m_fio_str;
        m_job_str = p.m_job_str;
        m_old_u8 = p.m_old_u8;
    }
    /**
     * @brief Получить данные человека
     * @param[out] fio ссылка для ФИО
     * @param[out] job ссылка для работы
     * @param[out] old ссылка для возраста
     */
    void get_data(std::string &fio, std::string &job, unsigned char &old)
    {
        fio = m_fio_str;
        job = m_job_str;
        old = m_old_u8;
    }
};

/*** Main Function ***/
int main(void)
{
    Person p1, p2;
    p1.set_person_data("С.М. Балакирев", "Просветитель", 84);
    p2.set_person_data(p1);
    return 0;
}
