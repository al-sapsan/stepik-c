/**********************************************************************
 * @file script7.cpp
 * @brief Класс Student: конструктор, запрет копирования и присваивания
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-12
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Class Definition ***/
/**
 * @brief Класс для хранения информации о студенте
 */
class Student
{
public:
    /**
     * @brief Конструктор с параметрами
     * @param[in] fio ФИО
     * @param[in] old возраст
     */
    Student(const std::string &fio, short old) : fio(fio), old(old) {}
    /**
     * @brief Установить данные
     * @param[in] fio ФИО
     * @param[in] old возраст
     */
    void set_data(const std::string &fio, short old)
    {
        this->fio = fio;
        this->old = old;
    }
    /**
     * @brief Получить ФИО
     * @return std::string&
     */
    std::string &get_fio() { return fio; }
    /**
     * @brief Получить возраст
     * @return short
     */
    short get_old() { return old; }
    // Запретить копирование и присваивание
    Student(const Student &) = delete;
    Student &operator=(const Student &) = delete;

private:
    std::string fio;
    short old;
};

/*** Main Function ***/
int main(void)
{
    Student *ptr_st = new Student("Pushkin", 21);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        delete ptr_st;
    return 0;
}
