/**********************************************************************
 * @file script2.cpp
 * @brief Класс Operator: создание только через create_obj, копирование разрешено
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-10
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс Operator с приватным конструктором
 */
class Operator
{
    long a{0}, b{0}, c{0};
    /**
     * @brief Конструктор по умолчанию (приватный)
     */
    Operator() = default;

public:
    /**
     * @brief Копирующий конструктор (разрешён)
     */
    Operator(const Operator &) = default;
    /**
     * @brief Создать объект в динамической памяти
     * @return указатель на объект
     */
    static Operator *create_obj()
    {
        Operator *ptr_obj = new Operator();
        return ptr_obj;
    }
};