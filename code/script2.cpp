/**********************************************************************
 * @file script2.cpp
 * @brief Классы Thing, TV, Book, Store (embedded C++ style)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-25
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Class Definition ***/
/**
 * @brief Класс Thing: базовый товар
 */
class Thing
{
protected:
    std::string name;
    int price{0};

public:
    void set_base_info(const std::string &name, int &price)
    {
        this->name = name;
        this->price = price;
    }
    void get_base_info(std::string &name, int &price)
    {
        name = this->name;
        price = this->price;
    }
    virtual ~Thing() {}
};

/**
 * @brief Класс TV: телевизор
 */
class TV : public Thing
{
private:
    int size{0};
    double weight{0.0};

public:
    TV(const std::string &n, int p, int s, double w)
    {
        name = n;
        price = p;
        size = s;
        weight = w;
    }
    void get_data(std::string &n, int &p, int &s, double &w)
    {
        n = name;
        p = price;
        s = size;
        w = weight;
    }
};

/**
 * @brief Класс Book: книга
 */
class Book : public Thing
{
private:
    std::string author;
    int pages{0};

public:
    Book(const std::string &n, int p, const std::string &a, int pg)
    {
        name = n;
        price = p;
        author = a;
        pages = pg;
    }
    void get_data(std::string &n, int &p, std::string &a, int &pg)
    {
        n = name;
        p = price;
        a = author;
        pg = pages;
    }
};

/**
 * @brief Класс Store: магазин
 */
class Store
{
private:
    enum
    {
        max_total = 100
    };
    Thing *things[max_total]{nullptr};
    int total{0};

public:
    ~Store()
    {
        for (int i = 0; i < total; ++i)
        {
            delete things[i];
        }
    }
    void append(Thing *th)
    {
        if (total < max_total)
        {
            things[total++] = th;
        }
    }
    Thing *operator[](int index)
    {
        if (index < 0 || index >= total)
            return nullptr;
        return things[index];
    }
    int get_total() const { return total; }
};

/*** Main ***/
int main(void)
{
    Store st;
    st.append(new TV("Samsung", 54300, 43, 5.4));
    st.append(new Book("C++", 2000, "Balakirev", 543));
    st.append(new TV("Sony", 97000, 80, 7.5));

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
