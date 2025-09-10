/**********************************************************************
 * @file script9.cpp
 * @brief Классы Item и TVProg: расписание передач, добавление, геттеры
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-10
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Class Definition ***/
/**
 * @brief Класс для хранения одной передачи
 */
class Item
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Item() : name(""), duration(0) {}
    /**
     * @brief Конструктор с параметрами
     * @param[in] n название
     * @param[in] d длительность
     */
    Item(const std::string &n, unsigned short d) : name(n), duration(d) {}
    /**
     * @brief Получить название
     * @return std::string&
     */
    std::string &get_name() { return name; }
    /**
     * @brief Получить длительность
     * @return unsigned short
     */
    unsigned short get_duration() { return duration; }

private:
    std::string name;        ///< название программы
    unsigned short duration; ///< длительность в минутах
};

/**
 * @brief Класс для хранения списка передач
 */
class TVProg
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    TVProg() : count(0) {}
    /**
     * @brief Конструктор с массивом передач
     * @param[in] lst массив передач
     * @param[in] length количество передач
     */
    TVProg(const Item *lst, int length) : count(0)
    {
        append(lst, length);
    }
    /**
     * @brief Добавить одну передачу
     * @param[in] it передача
     */
    void append(const Item &it)
    {
        if (count < max_length)
        {
            items[count++] = it;
        }
    }
    /**
     * @brief Добавить несколько передач
     * @param[in] lst массив передач
     * @param[in] length количество передач
     */
    void append(const Item *lst, int length)
    {
        for (int i = 0; i < length; ++i)
        {
            if (count < max_length)
            {
                items[count++] = lst[i];
            }
            else
            {
                break;
            }
        }
    }
    /**
     * @brief Получить массив передач
     * @return Item*
     */
    Item *get_list() { return items; }
    /**
     * @brief Получить число передач
     * @return int
     */
    int get_count() { return count; }

private:
    enum
    {
        max_length = 100
    };
    Item items[max_length]; ///< массив передач
    int count{0};           ///< число передач
};

/*** Main Function ***/
int main(void)
{
    TVProg tv;
    tv.append(Item("Новости", 20));
    tv.append(Item("Модный приговор", 50));
    tv.append(Item("Жить здорово!", 60));
    tv.append(Item("Информационный канал", 15));
    tv.append(Item("Новости", 15));
    tv.append(Item("Давай поженимся!", 70));

    __ASSERT_TESTS__ // макроопределение для тестирования

        return 0;
}
