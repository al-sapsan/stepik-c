/**********************************************************************
 * @file script3.cpp
 * @brief Класс Distance, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-23
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Class Definition ***/
/**
 * @brief Класс Distance
 */
class Distance
{
public:
	/**
	 * @brief Конструктор по умолчанию
	 */
	Distance() : m_dist(0) {}
	/**
	 * @brief Конструктор с параметром
	 * @param[in] d Дистанция
	 */
	Distance(int d) : m_dist(d) {}
	/**
	 * @brief Деструктор
	 */
	~Distance() {}
	/**
	 * @brief Конструктор копирования
	 * @param[in] other Другой объект
	 */
	Distance(const Distance &other) : m_dist(other.m_dist) {}
	/**
	 * @brief Оператор копирующего присваивания
	 * @param[in] other Другой объект
	 * @return Ссылка на объект
	 */
	Distance &operator=(const Distance &other)
	{
		if (this != &other)
			m_dist = other.m_dist;
		return *this;
	}
	/**
	 * @brief Оператор перемещающего присваивания
	 * @param[in] other Другой объект
	 * @return Ссылка на объект
	 */
	Distance &operator=(Distance &&other) noexcept
	{
		if (this != &other)
			m_dist = other.m_dist;
		return *this;
	}
	/**
	 * @brief Конструктор перемещения
	 * @param[in] other Другой объект
	 */
	Distance(Distance &&other) noexcept : m_dist(other.m_dist) {}
	/**
	 * @brief Оператор присваивания int
	 * @param[in] d Дистанция
	 * @return Ссылка на объект
	 */
	Distance &operator=(int d)
	{
		m_dist = d;
		return *this;
	}
	/**
	 * @brief Оператор +=
	 * @param[in] d Дистанция
	 * @return Ссылка на объект
	 */
	Distance &operator+=(int d)
	{
		m_dist += d;
		return *this;
	}
	/**
	 * @brief Оператор -=
	 * @param[in] d Дистанция
	 * @return Ссылка на объект
	 */
	Distance &operator-=(int d)
	{
		m_dist -= d;
		return *this;
	}
	/**
	 * @brief Оператор *=
	 * @param[in] d Множитель
	 * @return Ссылка на объект
	 */
	Distance &operator*=(int d)
	{
		m_dist *= d;
		return *this;
	}
	/**
	 * @brief Оператор /=
	 * @param[in] d Делитель
	 * @return Ссылка на объект
	 */
	Distance &operator/=(int d)
	{
		m_dist /= d;
		return *this;
	}
	/**
	 * @brief Оператор вызова
	 * @return Значение дистанции
	 */
	int operator()() const { return m_dist; }
	/**
	 * @brief Получить значение
	 * @return Значение дистанции
	 */
	int get_dist() const { return m_dist; }

private:
	int m_dist; ///< Дистанция
};

/*** Main ***/
int main()
{
	// Создание объекта и ссылок
	Distance d(547);
	Distance &lnk_d = d;
	Distance &&lnk_r_d = static_cast<Distance &&>(d);
	lnk_r_d += 100;

	__ASSERT_TESTS__ // макроопределение для тестирования
		return 0;
}
