/**********************************************************************
 * @file script1.cpp
 * @brief CommonInterface, Thing implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-01
 **********************************************************************/

#include <iostream> // for std::cout, std::endl
#include <string>   // for std::string

/********** Global Constants **********/
enum
{
    max_size = 100
};

/********** Class Definition **********/
// == < CommonInterface > == //
/**
 * @brief Базовый интерфейс
 */
class CommonInterface
{
public:
    virtual long long get_id() const = 0;
    virtual void set_id(long long id) = 0;
    virtual ~CommonInterface() = default;
};

// == < Thing > == //
/**
 * @brief Класс товара
 * @param id Идентификатор
 * @param name Название
 * @param price Цена
 */
class Thing : public CommonInterface
{
private:
    long long m_id{0};
    std::string m_name;
    int m_price{0};

public:
    Thing(long long id, const std::string &name, int price)
        : m_id(id), m_name(name), m_price(price) {}

    virtual long long get_id() const override { return m_id; }
    virtual void set_id(long long id) override { m_id = id; }
    const std::string &get_name() const { return m_name; }
    int get_price() const { return m_price; }
    virtual ~Thing() override = default;
};

/********** Main Function **********/
int main(void)
{
    CommonInterface *lst[max_size]{nullptr};

    lst[0] = new Thing(4, "Book C++", 2500);
    lst[1] = new Thing(1, "Computer HP", 125000);
    lst[2] = new Thing(10, "Mouse Lg", 4300);
    lst[3] = new Thing(19, "Monitor Samsung", 9560);

    for (int i = 0; i < max_size && lst[i] != nullptr; ++i)
    {
        std::cout << lst[i]->get_id();
        if (i < 3)
            std::cout << " ";
    }
    std::cout << std::endl;

    __ASSERT_TESTS__

    for (int i = 0; i < max_size && lst[i] != nullptr; ++i)
    {
        delete lst[i];
    }

    return 0;
}