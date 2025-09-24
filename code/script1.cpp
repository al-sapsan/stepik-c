/**********************************************************************
 * @file script1.cpp
 * @brief Классы Animal, Cat, Dog (embedded C++ style)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-24
 **********************************************************************/

/*** Core ***/
#include <string>

/*** Class Definition ***/
/**
 * @brief Класс Animal
 */
class Animal
{
protected:
    std::string name;
    short old = 0;

public:
    Animal() = default;
    Animal(const std::string &n, short o) : name(n), old(o) {}
    const std::string &get_name() const { return name; }
    short get_old() const { return old; }
};

/**
 * @brief Класс Cat (наследник Animal)
 */
class Cat : public Animal
{
private:
    int color = 0;
    double weight = 0.0;

public:
    Cat() = default;
    Cat(const std::string &n, short o, int c, double w)
        : Animal(n, o), color(c), weight(w) {}
    int get_color() const { return color; }
    double get_weight() const { return weight; }
    void set_info(const std::string &n, short o, int c, double w)
    {
        name = n;
        old = o;
        color = c;
        weight = w;
    }
};

/**
 * @brief Класс Dog (наследник Animal)
 */
class Dog : public Animal
{
private:
    std::string breed;
    short length = 0;

public:
    Dog() = default;
    Dog(const std::string &n, short o, const std::string &b, short l)
        : Animal(n, o), breed(b), length(l) {}
    const std::string &get_breed() const { return breed; }
    short get_length() const { return length; }
    void set_info(const std::string &n, short o, const std::string &b, short l)
    {
        name = n;
        old = o;
        breed = b;
        length = l;
    }
};
