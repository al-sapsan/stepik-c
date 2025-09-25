/**********************************************************************
 * @file script5.cpp
 * @brief Классы фильтров воды и GeyserClassic (embedded C++ style)
 * @version 1.1 (Embedded C++ style)
 * @date 2025-09-25
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/

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
    unsigned date{0};
    type_filter_water type{flt_none};

public:
    FilterWater() = default;
    FilterWater(unsigned d, type_filter_water t) : date(d), type(t) {}
    /**
     * @brief Получить дату установки фильтра
     */
    unsigned get_date() const { return date; }
    /**
     * @brief Получить тип фильтра
     */
    type_filter_water get_type() const { return type; }
};

/**
 * @brief Механический фильтр
 */
class Mechanical : public FilterWater
{
public:
    Mechanical(unsigned date) : FilterWater(date, flt_mechanical) {}
};

/**
 * @brief Арагоновый фильтр
 */
class Aragon : public FilterWater
{
public:
    Aragon(unsigned date) : FilterWater(date, flt_aragon) {}
};

/**
 * @brief Кальциевый фильтр
 */
class Calcium : public FilterWater
{
public:
    Calcium(unsigned date) : FilterWater(date, flt_calcium) {}
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
    /**
     * @brief Проверить валидность фильтра для слота
     */
    bool isValidSlot(int slot_num, FilterWater *filter)
    {
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
    }

public:
    GeyserClassic() = default;
    /**
     * @brief Конструктор с одним фильтром
     */
    GeyserClassic(FilterWater *f1)
    {
        if (f1 && f1->get_type() == flt_mechanical)
            slots[0] = f1;
    }
    /**
     * @brief Конструктор с двумя фильтрами
     */
    GeyserClassic(FilterWater *f1, FilterWater *f2)
    {
        if (f1 && f1->get_type() == flt_mechanical)
            slots[0] = f1;
        if (f2 && f2->get_type() == flt_aragon)
            slots[1] = f2;
    }
    /**
     * @brief Конструктор с тремя фильтрами
     */
    GeyserClassic(FilterWater *f1, FilterWater *f2, FilterWater *f3)
    {
        if (f1 && f1->get_type() == flt_mechanical)
            slots[0] = f1;
        if (f2 && f2->get_type() == flt_aragon)
            slots[1] = f2;
        if (f3 && f3->get_type() == flt_calcium)
            slots[2] = f3;
    }
    /**
     * @brief Получить фильтр по индексу
     */
    const FilterWater *operator[](int index) const
    {
        if (index < 0 || index >= total_slots)
            return nullptr;
        return slots[index];
    }
    /**
     * @brief Добавить фильтр в слот
     */
    void add_filter(int slot_num, FilterWater *filter)
    {
        {
            if (slot_num < 1 || slot_num > total_slots)
                return;
            if (slots[slot_num - 1] != nullptr)
                return;
            if (!isValidSlot(slot_num, filter))
                return;
            slots[slot_num - 1] = filter;
        }
    }
};