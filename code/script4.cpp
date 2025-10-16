/************************************************************************
 * @file script4.cpp
 * @brief Шаблонные классы Array и Student для учета оценок
 * @version 1.0
 * @date 2025-10-16
 ************************************************************************/

#include <iostream>
#include <string>
#include <iterator>

class Person
{
protected:
    std::string fio;
    short old{0};

public:
    Person(const std::string &fio, short old) : fio(fio), old(old) {}
    virtual ~Person() {}
    const std::string &get_fio() const { return fio; }
    short get_old() const { return old; }
};

/**
 * @brief Шаблонный класс для хранения массива элементов
 * @tparam T Тип элементов массива
 */
template <typename T>
class Array
{
public:
    enum
    {
        max_array_size = 100
    };

protected:
    T data_array[max_array_size]{0}; ///< массив элементов типа T
    int length_array{0};             ///< длина массива
public:
    Array() = default;
    Array(T *d, int size)
    {
        length_array = (size > max_array_size) ? max_array_size : size;
        for (int i = 0; i < length_array; ++i)
            data_array[i] = d[i];
    }
    virtual ~Array() {}

    T *get_data() { return data_array; }
    int get_length() const { return length_array; }
};

/**
 * @brief Шаблонный класс студента с оценками
 * @tparam T Тип оценок
 */
template <typename T>
class Student : public Person, public Array<T>
{
private:
    std::string group;

public:
    Student(const std::string &fio, short old)
        : Person(fio, old), Array<T>() {}

    Student(const std::string &fio, short old, T *marks, int size)
        : Person(fio, old), Array<T>(marks, size) {}

    void set_group(const std::string &g) { group = g; }
    const std::string &get_group() const { return group; }
};

int main()
{
    short marks[] = {3, 3, 4, 2};
    Student<short> *ptr_st = new Student<short>("Bechterev S. A.", 52, marks, std::size(marks));

#ifndef __ASSERT_TESTS__
#define __ASSERT_TESTS__
#endif

    __ASSERT_TESTS__

    delete ptr_st;
    return 0;
}
