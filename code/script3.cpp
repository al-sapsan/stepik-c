/**********************************************************************
 * @file script3.cpp
 * @brief Классы Clock, ClockShow (embedded C++ style)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-24
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <iomanip>

/*** Class Definition ***/
/**
 * @brief Класс Clock
 */
class Clock
{
protected:
	unsigned time_current = 0;

public:
	Clock() = default;
	Clock(unsigned tm) : time_current(tm) {}
	void set_time(unsigned tm) { time_current = tm; }
	unsigned get_hours() const { return time_current / 3600; }
	unsigned get_minutes() const { return (time_current / 60) % 60; }
	unsigned get_seconds() const { return time_current % 60; }
};

/**
 * @brief Класс ClockShow (наследник Clock)
 */
class ClockShow : public Clock
{
public:
	enum time_format
	{
		tm_hhmmss = 1,
		tm_hms = 2,
		tm_ssmmhh = 3,
		tm_smh = 4
	};

private:
	time_format format = tm_hhmmss;

public:
	ClockShow() = default;
	ClockShow(unsigned tm) : Clock(tm), format(tm_hhmmss) {}
	ClockShow(unsigned tm, time_format fmt) : Clock(tm), format(fmt) {}
	/**
	 * @brief Отображает время в заданном формате
	 */
	void show_time() const
	{
		unsigned h = get_hours(), m = get_minutes(), s = get_seconds();
		switch (format)
		{
		case tm_hhmmss:
			std::cout << std::setw(2) << std::setfill('0') << h << ":"
					  << std::setw(2) << std::setfill('0') << m << ":"
					  << std::setw(2) << std::setfill('0') << s << std::endl;
			break;
		case tm_hms:
			std::cout << h << ":" << m << ":" << s << std::endl;
			break;
		case tm_ssmmhh:
			std::cout << std::setw(2) << std::setfill('0') << s << ":"
					  << std::setw(2) << std::setfill('0') << m << ":"
					  << std::setw(2) << std::setfill('0') << h << std::endl;
			break;
		case tm_smh:
			std::cout << s << ":" << m << ":" << h << std::endl;
			break;
		}
	}
};

/*** Main ***/
int main()
{
	unsigned t;
	std::cin >> t;
	ClockShow clock(t, ClockShow::tm_hms);
	clock.show_time();

	__ASSERT_TESTS__ // макроопределение для тестирования
		return 0;
}
