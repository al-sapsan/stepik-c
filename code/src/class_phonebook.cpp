/**********************************************************************
 * @file script9.cpp
 * @brief Класс PhoneBook, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-16
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Struct Definition ***/
/**
 * @brief Структура PhoneBookItem: контакт
 */
struct PhoneBookItem
{
    std::string fio;
    std::string phone_number;
    PhoneBookItem() = default;
    PhoneBookItem(const std::string &fio_, const std::string &phone_number_)
        : fio(fio_), phone_number(phone_number_) {}
};

/*** Class Definition ***/
/**
 * @brief Класс PhoneBook: телефонная книжка
 */
class PhoneBook
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    PhoneBook();
    /**
     * @brief Конструктор копирования из массива
     * @param[in] lst массив контактов
     * @param[in] size количество контактов
     */
    PhoneBook(const PhoneBookItem *lst, size_t size);
    /**
     * @brief Конструктор копирования
     * @param[in] other другой объект PhoneBook
     */
    PhoneBook(const PhoneBook &other);
    /**
     * @brief Деструктор
     */
    ~PhoneBook();
    /**
     * @brief Оператор присваивания
     * @param[in] other другой объект PhoneBook
     * @return PhoneBook&
     */
    PhoneBook &operator=(const PhoneBook &other);
    /**
     * @brief Оператор сложения (добавляет контакт)
     * @param[in] item контакт
     * @return PhoneBook
     */
    PhoneBook operator+(const PhoneBookItem &item) const;
    /**
     * @brief Получить массив контактов
     * @return const PhoneBookItem*
     */
    const PhoneBookItem *get_phone_book() const;
    /**
     * @brief Получить количество контактов
     * @return size_t
     */
    size_t get_count() const;
    /**
     * @brief Добавить контакт
     * @param[in] item контакт
     * @return bool
     */
    bool append(const PhoneBookItem &item);

private:
    enum
    {
        max_phone_book = 100
    };
    PhoneBookItem *phone_book{nullptr};
    size_t count{0};
};

/*** Methods Implementation ***/
PhoneBook::PhoneBook() : phone_book(new PhoneBookItem[max_phone_book]), count(0) {}
PhoneBook::PhoneBook(const PhoneBookItem *lst, size_t size)
    : phone_book(new PhoneBookItem[max_phone_book]), count(size > max_phone_book ? max_phone_book : size)
{
    for (size_t i = 0; i < count; ++i)
    {
        phone_book[i] = lst[i];
    }
}
PhoneBook::PhoneBook(const PhoneBook &other)
    : phone_book(new PhoneBookItem[max_phone_book]), count(other.count)
{
    for (size_t i = 0; i < count; ++i)
    {
        phone_book[i] = other.phone_book[i];
    }
}
PhoneBook::~PhoneBook()
{
    delete[] phone_book;
}
PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
    if (this != &other)
    {
        delete[] phone_book;
        phone_book = new PhoneBookItem[max_phone_book];
        count = other.count;
        for (size_t i = 0; i < count; ++i)
        {
            phone_book[i] = other.phone_book[i];
        }
    }
    return *this;
}
PhoneBook PhoneBook::operator+(const PhoneBookItem &item) const
{
    PhoneBook result(*this);
    result.append(item);
    return result;
}
const PhoneBookItem *PhoneBook::get_phone_book() const
{
    return phone_book;
}
size_t PhoneBook::get_count() const
{
    return count;
}
bool PhoneBook::append(const PhoneBookItem &item)
{
    if (count < max_phone_book)
    {
        phone_book[count++] = item;
        return true;
    }
    return false;
}

/*** Main ***/
int main(void)
{
    PhoneBook phone_lst;
    phone_lst = phone_lst + PhoneBookItem("А. Дзюба", "+71237694401");
    phone_lst = phone_lst + PhoneBookItem("П. Гагарина", "+79234694105");
    phone_lst = phone_lst + PhoneBookItem("О. Бузова", "+79041563055");
    phone_lst = phone_lst + PhoneBookItem("Тимати", "+79121000000");
    // память освобождается автоматически деструктором
    return 0;
}
