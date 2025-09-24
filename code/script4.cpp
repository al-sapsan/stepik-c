/**********************************************************************
 * @file script4.cpp
 * @brief Классы Thing, ThingPhisical, ThingElectro (embedded C++ style)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-24
 **********************************************************************/

/*** Core ***/
#include <string>

/*** Class Definition ***/
/**
 * @brief Класс Thing
 */
class Thing
{
private:
    unsigned id = 0;

protected:
    std::string name;
    int price = 0;

public:
    Thing() = default;
    Thing(const std::string &n, int p) : name(n), price(p) {}
    void set_data(const std::string &n, int p)
    {
        name = n;
        price = p;
    }
    unsigned get_id() const { return id; }
    std::string get_name() const { return name; }
    int get_price() const { return price; }
};

/**
 * @brief Класс ThingPhisical (материальный товар)
 */
class ThingPhisical : public Thing
{
private:
    unsigned width = 0, height = 0, depth = 0;
    double weight = 0.0;

public:
    ThingPhisical() = default;
    ThingPhisical(const std::string &n, int p) : Thing(n, p) {}
    ThingPhisical(const std::string &n, int p, unsigned w, unsigned h, unsigned d, double wt)
        : Thing(n, p), width(w), height(h), depth(d), weight(wt) {}
    void set_dims(unsigned w, unsigned h, unsigned d)
    {
        width = w;
        height = h;
        depth = d;
    }
    void set_weight(double wt) { weight = wt; }
    void get_dims(unsigned &w, unsigned &h, unsigned &d) const
    {
        w = width;
        h = height;
        d = depth;
    }
    double get_weight() const { return weight; }
};

/**
 * @brief Класс ThingElectro (электронный товар)
 */
class ThingElectro : public Thing
{
private:
    unsigned volume = 0;

public:
    ThingElectro() = default;
    ThingElectro(const std::string &n, int p) : Thing(n, p) {}
    ThingElectro(const std::string &n, int p, unsigned v) : Thing(n, p), volume(v) {}
    void set_volume(unsigned v) { volume = v; }
    unsigned get_volume() const { return volume; }
};
