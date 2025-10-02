/**********************************************************************
 * @file script7.cpp
 * @brief PhysicInterface, Car, Train, ModelCar, ModelTrain implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-02
 **********************************************************************/

#include <iostream>

/********** Class Definition **********/

// == < PhysicInterface > == //
class PhysicInterface
{
public:
    virtual void forward(int speed) = 0;
    virtual void stop() = 0;
    virtual void left(double angle) = 0;
    virtual void right(double angle) = 0;
    virtual ~PhysicInterface() = default;
};

// == < Car > == //
class Car
{
protected:
    int m_speed{0};
    int m_x{0}, m_y{0};
    int m_weight{0};
    double m_angle{0.0};

public:
    Car(int x, int y, int weight)
        : m_x(x), m_y(y), m_weight(weight) {}
    virtual ~Car() = default;

    void get_coords(int &x, int &y) const
    {
        x = m_x;
        y = m_y;
    }
    int get_speed() const { return m_speed; }
    int get_weight() const { return m_weight; }
    double get_angle() const { return m_angle; }
};

// == < Train > == //
class Train
{
protected:
    int m_speed{0};
    int m_x{0}, m_y{0};
    int m_weight{0};
    double m_power{0.0};

public:
    Train(int x, int y, int weight, double power)
        : m_x(x), m_y(y), m_weight(weight), m_power(power) {}
    virtual ~Train() = default;

    void get_coords(int &x, int &y) const
    {
        x = m_x;
        y = m_y;
    }
    int get_speed() const { return m_speed; }
    int get_weight() const { return m_weight; }
    double get_power() const { return m_power; }
};

// == < ModelCar > == //
class ModelCar : public Car, public PhysicInterface
{
public:
    ModelCar(int x, int y, int weight)
        : Car(x, y, weight) {}

    virtual void forward(int speed) override { m_speed = speed; }
    virtual void stop() override { m_speed = 0; }
    virtual void left(double angle) override { m_angle = angle; }
    virtual void right(double angle) override { m_angle = -angle; }
    virtual ~ModelCar() override = default;
};

// == < ModelTrain > == //
class ModelTrain : public Train, public PhysicInterface
{
public:
    ModelTrain(int x, int y, int weight, double power)
        : Train(x, y, weight, power) {}

    virtual void forward(int speed) override { m_speed = speed; }
    virtual void stop() override { m_speed = 0; }
    virtual void left(double /*angle*/) override {}
    virtual void right(double /*angle*/) override {}
    virtual ~ModelTrain() override = default;
};

/********** Main Function **********/

int main(void)
{
    PhysicInterface *obj_lst[] = {
        new ModelCar(0, 0, 1200),
        new ModelTrain(-5, 7, 534200, 574.33),
        new ModelCar(11, 24, 1920),
        new ModelCar(-1, 12, 945)};

    for (int i = 0; i < sizeof(obj_lst) / sizeof(obj_lst[0]); ++i)
    {
        obj_lst[i]->forward(7);
    }

    __ASSERT_TESTS__

    for (int i = 0; i < sizeof(obj_lst) / sizeof(obj_lst[0]); ++i)
    {
        delete obj_lst[i];
    }

    return 0;
}