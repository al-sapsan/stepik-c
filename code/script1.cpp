/**********************************************************************
 * @file script1.cpp
 * @brief Класс Person: делегирующий конструктор, динамическое создание
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-08
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Class Definition ***/
/**
 * @brief Класс для хранения информации о челе
 */
class Person
{
public:
    /**
     * @brief Конструктор по ФИО
     * @param[in] fio ФИО
     */
    Person(const std::string &fio) : fio(fio)
    {
        std::cout << "Person(string)" << std::endl;
    }
    /**
     * @brief Делегирующий конструктор
     * @param[in] fio ФИО
     * @param[in] old возраст
     * @param[in] salary зарплата
     */
    Person(const std::string &fio, short old, long salary)
        : Person(fio)
    {
        this->old = old;
        this->salary = salary;
    }
    /**
     * @brief Получить данные
     * @param[out] fio ФИО
     * @param[out] old возраст
     * @param[out] salary зарплата
     */
    void get_data(std::string &fio, short &old, long &salary)
    {
        fio = this->fio;
        old = this->old;
        salary = this->salary;
    }

private:
    std::string fio;
    short old{0};
    long salary{0};
};

/*** Main Function ***/
int main(void)
{
    // создаём объект через делегирующий конструктор
    Person *ptr_p = new Person("Рахманинов С.В.", 75, 13204);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        // освобождаем память
        delete ptr_p;

    return 0;
}
