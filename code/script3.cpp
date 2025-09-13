/**********************************************************************
 * @file script3.cpp
 * @brief Класс Operator: создание только через статический метод create
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-12
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс Operator с приватными конструкторами
 */
class Operator
{
    int type{0};
    short operation{-1};
    /**
     * @brief Приватный конструктор по умолчанию
     */
    Operator() = default;
    /**
     * @brief Приватный копирующий конструктор
     */
    Operator(const Operator &) = default;

public:
    /**
     * @brief Создать объект в динамической памяти
     * @return указатель на объект
     */
    static Operator *create() { return new Operator(); }
    /**
     * @brief Установить состояние
     * @param[in] t тип
     * @param[in] o операция
     */
    void set_state(int t, short o)
    {
        type = t;
        operation = o;
    }
    /**
     * @brief Получить состояние
     * @param[out] t тип
     * @param[out] o операция
     */
    void get_state(int &t, short &o)
    {
        t = type;
        o = operation;
    }
};