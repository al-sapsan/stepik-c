
/**********************************************************************
 * @file script4.cpp
 * @brief Классы фильтров воды и GeyserClassic (embedded C++ style)
 * @version 1.1 (Embedded C++ style)
 * @date 2025-09-25
 **********************************************************************/

/*** Core ***/
#include <cstddef>

/**
 * @brief Типы фильтров воды
 */
enum type_filter_water
{
    flt_none = 0,
    flt_mechanical = 1,
    flt_aragon = 2,
    flt_calcium = 3
};

/**
 * @brief Базовый класс фильтра воды
 */
class FilterWater
{
protected:
    unsigned date;
    type_filter_water type;

public:
    FilterWater();
    FilterWater(unsigned d, type_filter_water t);
    unsigned get_date() const;
    type_filter_water get_type() const;
    virtual ~FilterWater();
};

/**
 * @brief Механический фильтр
 */
class Mechanical : public FilterWater
{
public:
    Mechanical(unsigned d);
};

/**
 * @brief Арагоновый фильтр
 */
class Aragon : public FilterWater
{
public:
    Aragon(unsigned d);
};

/**
 * @brief Кальциевый фильтр
 */
class Calcium : public FilterWater
{
public:
    Calcium(unsigned d);
};

/**
 * @brief Класс GeyserClassic: набор фильтров для очистки воды
 */
class GeyserClassic
{
public:
    enum
    {
        total_slots = 3
    };

private:
    FilterWater *slots[total_slots]{nullptr};

public:
    GeyserClassic();
    GeyserClassic(FilterWater *f1);
    GeyserClassic(FilterWater *f1, FilterWater *f2);
    GeyserClassic(FilterWater *f1, FilterWater *f2, FilterWater *f3);
    ~GeyserClassic();
    GeyserClassic(const GeyserClassic &) = delete;
    GeyserClassic &operator=(const GeyserClassic &) = delete;
    GeyserClassic(GeyserClassic &&other) noexcept;
    GeyserClassic &operator=(GeyserClassic &&other) noexcept;
    const FilterWater *operator[](int index) const;
    void add_filter(int slot_num, FilterWater *filter);

private:
    bool isValidSlot(int slot_num, FilterWater *filter) const;
};

/*** Methods Implementation ***/
FilterWater::FilterWater() : date(0), type(flt_none) {}
FilterWater::FilterWater(unsigned d, type_filter_water t) : date(d), type(t) {}
unsigned FilterWater::get_date() const { return date; }
type_filter_water FilterWater::get_type() const { return type; }
FilterWater::~FilterWater() {}

Mechanical::Mechanical(unsigned d) : FilterWater(d, flt_mechanical) {}
Aragon::Aragon(unsigned d) : FilterWater(d, flt_aragon) {}
Calcium::Calcium(unsigned d) : FilterWater(d, flt_calcium) {}

GeyserClassic::GeyserClassic() {}
GeyserClassic::GeyserClassic(FilterWater *f1) { add_filter(1, f1); }
GeyserClassic::GeyserClassic(FilterWater *f1, FilterWater *f2)
{
    add_filter(1, f1);
    add_filter(2, f2);
}
GeyserClassic::GeyserClassic(FilterWater *f1, FilterWater *f2, FilterWater *f3)
{
    add_filter(1, f1);
    add_filter(2, f2);
    add_filter(3, f3);
}
GeyserClassic::~GeyserClassic()
{
    for (int i = 0; i < total_slots; ++i)
        delete slots[i];
}
GeyserClassic::GeyserClassic(GeyserClassic &&other) noexcept
{
    for (int i = 0; i < total_slots; ++i)
    {
        slots[i] = other.slots[i];
        other.slots[i] = nullptr;
    }
}
GeyserClassic &GeyserClassic::operator=(GeyserClassic &&other) noexcept
{
    if (this != &other)
    {
        for (int i = 0; i < total_slots; ++i)
        {
            delete slots[i];
            slots[i] = other.slots[i];
            other.slots[i] = nullptr;
        }
    }
    return *this;
}
const FilterWater *GeyserClassic::operator[](int index) const
{
    if (index < 0 || index >= total_slots)
        return nullptr;
    return slots[index];
}
void GeyserClassic::add_filter(int slot_num, FilterWater *filter)
{
    if (slot_num < 1 || slot_num > total_slots)
        return;
    if (slots[slot_num - 1] != nullptr)
        return;
    if (!isValidSlot(slot_num, filter))
        return;
    slots[slot_num - 1] = filter;
}
bool GeyserClassic::isValidSlot(int slot_num, FilterWater *filter) const
{
    if (slot_num < 1 || slot_num > total_slots)
        return false;
    if (!filter)
        return false;
    switch (slot_num)
    {
    case 1:
        return filter->get_type() == flt_mechanical;
    case 2:
        return filter->get_type() == flt_aragon;
    case 3:
        return filter->get_type() == flt_calcium;
    }
    return false;
}