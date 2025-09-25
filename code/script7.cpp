/**********************************************************************
 * @file script7.cpp
 * @brief Airplane and MS21 class implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-09-25
 **********************************************************************/

#include <iostream>
#include <string>

/************ Class Prototypes ***********/
/// < Класс Airplane > ///
/**
 * @brief Класс самолета
 * @param model Модель самолета
 * @param max_speed Максимальная скорость
 * @param length Длина самолета
 */
class Airplane
{
protected:
    std::string m_model;
    unsigned m_max_speed{0};
    int m_length{0};

public:
    Airplane(const std::string &model, unsigned max_speed, int length);
    Airplane() = delete;

    const std::string &get_model() const;
    unsigned get_max_speed() const;
    int get_length() const;
};

/// < Класс MS21 > ///
/**
 * @brief Класс MS21 (дочерний от Airplane)
 * @param drive_model Модель двигателя
 * @param weight Вес самолета
 */
class MS21 : public Airplane
{
private:
    std::string m_drive_model;
    double m_weight{0.0};

public:
    MS21(const std::string &model, unsigned max_speed, int length,
         const std::string &drive_model, double weight);

    void get_info(std::string &drive, double &weight) const;
};

/************ Main Function ***********/
int main(void)
{
    MS21 ms21("MS 21", 1000, 212, "PD-14", 11.3);

    __ASSERT_TESTS__

    return 0;
}

/************ Function Implementations ***********/
/// < Airplane Implementation > ///
Airplane::Airplane(const std::string &model, unsigned max_speed, int length)
    : m_model(model), m_max_speed(max_speed), m_length(length)
{
}

const std::string &Airplane::get_model() const
{
    return m_model;
}

unsigned Airplane::get_max_speed() const
{
    return m_max_speed;
}

int Airplane::get_length() const
{
    return m_length;
}

/// < MS21 Implementation > ///
MS21::MS21(const std::string &model, unsigned max_speed, int length,
           const std::string &drive_model, double weight)
    : Airplane(model, max_speed, length), m_drive_model(drive_model), m_weight(weight)
{
}

void MS21::get_info(std::string &drive, double &weight) const
{
    drive = m_drive_model;
    weight = m_weight;
}