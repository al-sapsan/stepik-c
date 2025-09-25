/**********************************************************************
 * @file script6.cpp
 * @brief Классы SmartPhone и IPhone (embedded C++ style)
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-25
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Class Definition ***/
/**
 * @brief Класс SmartPhone
 */
class SmartPhone
{
protected:
    std::string model;
    double weight;

public:
    SmartPhone(const std::string &m, double w) : model(m), weight(w) {}
    const std::string &get_model() const { return model; }
    double get_weight() const { return weight; }
};

/**
 * @brief Класс IPhone (наследник SmartPhone)
 */
class IPhone : public SmartPhone
{
private:
    int memory_volume;
    int display_size;

public:
    IPhone(const std::string &m, double w, int mem, int size)
        : SmartPhone(m, w), memory_volume(mem), display_size(size) {}
    void get_info(int &memory, int &size)
    {
        memory = memory_volume;
        size = display_size;
    }
};

/*** Main ***/
int main(void)
{
    IPhone iPhone12("iPhone12", 0.17, 64000, 11);

    __ASSERT_TESTS__ // макроопределение для тестирования
        return 0;
}
