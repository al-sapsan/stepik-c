/**********************************************************************
 * @file script3.cpp
 * @brief Классы фильтров воды и GeyserClassic (embedded C++ style)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-25
 **********************************************************************/

/*** Core ***/
#include <cstddef>

/*** Class Definition ***/
/**
 * @brief Типы фильтров воды
 */
enum class type_filter_water : int
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
	FilterWater() : date(0), type(type_filter_water::flt_none) {}
	FilterWater(unsigned d, type_filter_water t) : date(d), type(t) {}
	unsigned get_date() const { return date; }
	type_filter_water get_type() const { return type; }
	virtual ~FilterWater() {}
};

/**
 * @brief Механический фильтр
 */
class Mechanical : public FilterWater
{
public:
	Mechanical(unsigned d) : FilterWater(d, type_filter_water::flt_mechanical) {}
};

/**
 * @brief Арагоновый фильтр
 */
class Aragon : public FilterWater
{
public:
	Aragon(unsigned d) : FilterWater(d, type_filter_water::flt_aragon) {}
};

/**
 * @brief Кальциевый фильтр
 */
class Calcium : public FilterWater
{
public:
	Calcium(unsigned d) : FilterWater(d, type_filter_water::flt_calcium) {}
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
	GeyserClassic() = default;
	GeyserClassic(FilterWater *f1) { add_filter(1, f1); }
	GeyserClassic(FilterWater *f1, FilterWater *f2)
	{
		add_filter(1, f1);
		add_filter(2, f2);
	}
	GeyserClassic(FilterWater *f1, FilterWater *f2, FilterWater *f3)
	{
		add_filter(1, f1);
		add_filter(2, f2);
		add_filter(3, f3);
	}
	// Rule of Five
	~GeyserClassic()
	{
		for (int i = 0; i < total_slots; ++i)
			delete slots[i];
	}
	GeyserClassic(const GeyserClassic &) = delete;
	GeyserClassic &operator=(const GeyserClassic &) = delete;
	GeyserClassic(GeyserClassic &&other) noexcept
	{
		for (int i = 0; i < total_slots; ++i)
		{
			slots[i] = other.slots[i];
			other.slots[i] = nullptr;
		}
	}
	GeyserClassic &operator=(GeyserClassic &&other) noexcept
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
	/**
	 * @brief Получить фильтр по индексу (0-based)
	 * @param index Индекс слота
	 * @return Указатель на фильтр или nullptr
	 */
	const FilterWater *operator[](int index) const
	{
		if (index < 0 || index >= total_slots)
			return nullptr;
		return slots[index];
	}
	/**
	 * @brief Добавить фильтр в слот
	 * @param slot_num Номер слота (1-based)
	 * @param filter Указатель на фильтр
	 */
	void add_filter(int slot_num, FilterWater *filter)
	{
		if (slot_num < 1 || slot_num > total_slots || !filter)
			return;
		int idx = slot_num - 1;
		if (slots[idx] != nullptr)
			return;
		if ((idx == 0 && filter->get_type() == type_filter_water::flt_mechanical) ||
			(idx == 1 && filter->get_type() == type_filter_water::flt_aragon) ||
			(idx == 2 && filter->get_type() == type_filter_water::flt_calcium))
		{
			slots[idx] = filter;
		}
	}
};
