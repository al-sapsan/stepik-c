/************************************************************************
 * @file script3.cpp
 * @brief Шаблонный класс Thing и его специализация для char*
 * @version 1.0
 * @date 2025-10-16
 ************************************************************************/

#include <iostream>
#include <cstring>

/**
 * @brief Шаблонный класс для представления объекта с уникальным ID
 * @tparam T1 Тип ID
 * @tparam T2 Тип имени
 */
template <typename T1, typename T2>
class Thing
{
    static T1 acc_uid;
    T1 uid{0};
    T2 name;
    int price{0};
    double weight{0.0};

public:
    Thing(T2 name, int price, double weight) : name(name), price(price), weight(weight)
    {
        uid = acc_uid++;
    }

    T1 get_uid() const { return uid; }
    T2 get_name() const { return name; }
    void get_data(int &price, double &weight)
    {
        price = this->price;
        weight = this->weight;
    }
};

// Инициализация статического члена для основного шаблона
template <typename T1, typename T2>
T1 Thing<T1, T2>::acc_uid = 0;

/**
 * @brief Специализация класса Thing для работы с char*
 * @tparam T1 Тип ID
 */
template <typename T1>
class Thing<T1, char *>
{
    static T1 acc_uid;
    T1 uid{0};
    char name[100]{0};
    int price{0};
    double weight{0.0};

public:
    Thing(char *n, int p, double w) : price(p), weight(w)
    {
        strncpy(name, n, 99);
        name[99] = '\0';
        uid = acc_uid++;
    }

    T1 get_uid() const { return uid; }
    const char *get_name() const { return name; }
    void get_data(int &p, double &w)
    {
        p = price;
        w = weight;
    }
};

// Инициализация статического члена для специализации
template <typename T1>
T1 Thing<T1, char *>::acc_uid = 0;

int main()
{
    Thing<int, char *> th("Templates in C++", 2000, 0.13);

#ifndef __ASSERT_TESTS__
#define __ASSERT_TESTS__
#endif

    __ASSERT_TESTS__
    return 0;
}
