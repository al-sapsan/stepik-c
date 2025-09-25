/**********************************************************************
 * @file script1.cpp
 * @brief Классы Animal, Cat, Dog (embedded C++ style)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-25
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Class Definition ***/
class Animal
{
protected:
    std::string name;
    short old{0};
};

class Cat : public Animal
{
private:
    int color{0};
    double weight{0.0};

public:
    Cat(const std::string &n, short o, int c, double w)
    {
        name = n;
        old = o;
        color = c;
        weight = w;
    }
    void get_data(std::string &n, short &o, int &c, double &w)
    {
        n = name;
        o = old;
        c = color;
        w = weight;
    }
};

class Dog : public Animal
{
private:
    int height{0};
    int speed{0};

public:
    Dog(const std::string &n, short o, int h, int s)
    {
        name = n;
        old = o;
        height = h;
        speed = s;
    }
    void get_data(std::string &n, short &o, int &h, int &s)
    {
        n = name;
        o = old;
        h = height;
        s = speed;
    }
};

/*** Main ***/
int main(void)
{
    Cat cat_1("Zeus", 5, 0, 1.2);
    Cat cat_2("Poseidon", 7, 122, 0.9);
    Dog dog_1("Rex", 10, 50, 32);

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
