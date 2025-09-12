/**********************************************************************
 * @file script1.cpp
 * @brief Класс Operator: запрет копирования, create_copy разрешён
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-10
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс Operator с запретом копирования
 */
class Operator
{
    long a{0}, b{0}, c{0};

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Operator() = default;
    /**
     * @brief Копирующий конструктор (запрещён)
     */
    Operator(const Operator &) = delete;
    /**
     * @brief Метод для создания копии объекта в динамической памяти
     * @return указатель на копию
     */
    Operator *create_copy()
    {
        Operator *ptr_obj = new Operator(*this);
        return ptr_obj;
    }
};