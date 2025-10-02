/**********************************************************************
 * @file script2.cpp
 * @brief Employee, Lector, Laborant implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-02
 **********************************************************************/

#include <iostream>
#include <string>

/********** Global Constants **********/

enum
{
    max_persons = 255
};

/********** Class Definition **********/

// == < Employee > == //
/**
 * @brief Абстрактный класс сотрудника
 */
class Employee
{
public:
    virtual const std::string &get_fname() const = 0;
    virtual const std::string &get_lname() const = 0;
    virtual short get_old() const = 0;
    virtual ~Employee() = default;
};

// == < Lector > == //
/**
 * @brief Класс лектора
 * @param first_name Имя
 * @param last_name Фамилия
 * @param old Возраст
 * @param salary Зарплата
 */
class Lector : public Employee
{
private:
    std::string m_first_name;
    std::string m_last_name;
    short m_old{0};
    int m_salary{0};

public:
    Lector(const std::string &first_name, const std::string &last_name, short old)
        : m_first_name(first_name), m_last_name(last_name), m_old(old) {}

    Lector(const std::string &first_name, const std::string &last_name, short old, int salary)
        : m_first_name(first_name), m_last_name(last_name), m_old(old), m_salary(salary > 0 ? salary : 0) {}

    virtual const std::string &get_fname() const override { return m_first_name; }
    virtual const std::string &get_lname() const override { return m_last_name; }
    virtual short get_old() const override { return m_old; }

    void set_salary(int salary)
    {
        if (salary > 0)
            m_salary = salary;
    }
    int get_salary() const { return m_salary; }
    virtual ~Lector() override = default;
};

// == < Laborant > == //
/**
 * @brief Класс лаборанта
 * @param first_name Имя
 * @param last_name Фамилия
 * @param old Возраст
 * @param job_title Должность
 */
class Laborant : public Employee
{
private:
    std::string m_first_name;
    std::string m_last_name;
    short m_old{0};
    std::string m_job_title;

public:
    Laborant(const std::string &first_name, const std::string &last_name, short old)
        : m_first_name(first_name), m_last_name(last_name), m_old(old) {}

    Laborant(const std::string &first_name, const std::string &last_name, short old, const std::string &job_title)
        : m_first_name(first_name), m_last_name(last_name), m_old(old), m_job_title(job_title) {}

    virtual const std::string &get_fname() const override { return m_first_name; }
    virtual const std::string &get_lname() const override { return m_last_name; }
    virtual short get_old() const override { return m_old; }

    void set_job_title(const std::string &job_title) { m_job_title = job_title; }
    const std::string &get_job_title() const { return m_job_title; }
    virtual ~Laborant() override = default;
};

/********** Main Function **********/

int main(void)
{
    Employee *staff[max_persons]{nullptr};

    staff[0] = new Lector("Sergey", "Balakirev", 33, 85000);
    staff[1] = new Laborant("Elena", "Pozdnjakova", 27, "Programmer");
    staff[2] = new Lector("Olga", "Levkina", 38, 120000);

    for (int i = 0; i < 3; ++i)
    {
        std::cout << staff[i]->get_fname();
        if (i < 2)
            std::cout << " ";
    }
    std::cout << std::endl;

    __ASSERT_TESTS__

    int staff_count = 3; // Explicit counter
    for (int i = 0; i < staff_count; ++i)
    {
        delete staff[i];
    }

    return 0;
}