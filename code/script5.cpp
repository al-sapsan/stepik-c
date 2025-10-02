/**********************************************************************
 * @file script5.cpp
 * @brief Student, Person, IntegerArray implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-02
 **********************************************************************/

#include <string> // for std::string

/********** Class Definition **********/

// == < Person > == //
class Person
{
protected:
    std::string m_fio;
    short m_old{0};

public:
    Person(const std::string &fio, short old) : m_fio(fio), m_old(old) {}
    virtual ~Person() = default;
    const std::string &get_fio() const { return m_fio; }
    short get_old() const { return m_old; }
};

// == < IntegerArray > == //
class IntegerArray
{
public:
    enum
    {
        max_array_size = 100
    };

protected:
    int m_data_array[max_array_size]{0};
    int m_length_array{0};

public:
    IntegerArray() = default;
    IntegerArray(int *d, int size)
    {
        m_length_array = (size > max_array_size) ? max_array_size : size;
        for (int i = 0; i < m_length_array; ++i)
            m_data_array[i] = d[i];
    }
    virtual ~IntegerArray() = default;

    int *get_data() { return m_data_array; }
    int get_length() const { return m_length_array; }
};

// == < Student > == //
class Student : public Person, public IntegerArray
{
private:
    std::string m_group;

public:
    Student(const std::string &fio, short old)
        : Person(fio, old), IntegerArray(), m_group() {}

    Student(const std::string &fio, short old, int *d, int size)
        : Person(fio, old), IntegerArray(d, size), m_group() {}

    void set_group(const std::string &group) { m_group = group; }
    const std::string &get_group() const { return m_group; }
    virtual ~Student() = default;
};

/********** Main Function **********/

int main(void)
{
    int marks[] = {5, 4, 3, 4, 5};
    Student *ptr_st = new Student("Евстигнеев А.Б.", 23, marks, std::size(marks));

    __ASSERT_TESTS__

    delete ptr_st;
    ptr_st = nullptr;

    return 0;
}