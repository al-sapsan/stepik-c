/**********************************************************************
 * @file script6.cpp
 * @brief Класс LimitLength, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-19
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс LimitLength: ограниченная длина
 */
class LimitLength
{
public:
    /**
     * @brief Конструктор
     * @param[in] len длина
     */
    LimitLength(int len = 0);
    /**
     * @brief Получить длину
     * @return int
     */
    int get_length() const;
    /**
     * @brief Оператор постфиксного инкремента
     * @return int (старое значение)
     */
    int operator++(int);
    /**
     * @brief Оператор префиксного инкремента
     * @return int (новое значение)
     */
    int operator++();
    /**
     * @brief Оператор постфиксного декремента
     * @return int (старое значение)
     */
    int operator--(int);
    /**
     * @brief Оператор префиксного декремента
     * @return int (новое значение)
     */
    int operator--();
    /**
     * @brief Оператор +=
     * @param[in] val
     * @return int (новое значение)
     */
    int operator+=(int val);
    /**
     * @brief Оператор -=
     * @param[in] val
     * @return int (новое значение)
     */
    int operator-=(int val);
    /**
     * @brief Оператор *=
     * @param[in] val
     * @return int (новое значение)
     */
    int operator*=(int val);
    /**
     * @brief Оператор /=
     * @param[in] val
     * @return int (новое значение)
     */
    int operator/=(int val);

private:
    enum
    {
        min_length = -10,
        max_length = 10
    };
    int length{0};
    void clamp();
};

/*** Methods Implementation ***/
LimitLength::LimitLength(int len) : length(len) { clamp(); }
int LimitLength::get_length() const { return length; }
void LimitLength::clamp()
{
    if (length < min_length)
        length = min_length;
    if (length > max_length)
        length = max_length;
}
int LimitLength::operator++(int)
{
    int old = length;
    ++length;
    clamp();
    return old;
}
int LimitLength::operator++()
{
    ++length;
    clamp();
    return length;
}
int LimitLength::operator--(int)
{
    int old = length;
    --length;
    clamp();
    return old;
}
int LimitLength::operator--()
{
    --length;
    clamp();
    return length;
}
int LimitLength::operator+=(int val)
{
    length += val;
    clamp();
    return length;
}
int LimitLength::operator-=(int val)
{
    length -= val;
    clamp();
    return length;
}
int LimitLength::operator*=(int val)
{
    length *= val;
    clamp();
    return length;
}
int LimitLength::operator/=(int val)
{
    if (val != 0)
        length /= val;
    clamp();
    return length;
}
