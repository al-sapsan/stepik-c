/**********************************************************************
 * @file script9.cpp
 * @brief Object, ObjectFly, ObjectOperators, Plane implementation
 * @version 1.0
 * @date 2025-10-02
 **********************************************************************/

#include <iostream>

/********** Class Definition **********/

class Object
{
protected:
    int m_x{0}, m_y{0};
    int m_speed{0};

public:
    Object(int x = 0, int y = 0, int speed = 0) : m_x(x), m_y(y), m_speed(speed) {}
    virtual ~Object() = default;

    void set_speed(int speed) { m_speed = speed; }
    int get_speed() const { return m_speed; }
    int get_x() const { return m_x; }
    int get_y() const { return m_y; }
};

// == < ObjectFly > == //
class ObjectFly : virtual public Object
{
protected:
    int m_z{0};
    double m_angle{0.0};

public:
    ObjectFly() : Object(), m_z(0), m_angle(0.0) {}
    ObjectFly(int z) : Object(), m_z(z), m_angle(0.0) {}
    ObjectFly(int z, double angle) : Object(), m_z(z), m_angle(angle) {}
    virtual ~ObjectFly() = default;

    int get_z() const { return m_z; }
    double get_angle() const { return m_angle; }
    void set_angle(double angle) { m_angle = angle; }
};

// == < ObjectOperators > == //
class ObjectOperators : virtual public Object
{
public:
    ObjectOperators() : Object() {}
    ObjectOperators(int x, int y) : Object(x, y) {}
    ObjectOperators(int x, int y, int speed) : Object(x, y, speed) {}
    virtual ~ObjectOperators() = default;

    void operator+=(int delta) { m_speed += delta; }
    void operator-=(int delta) { m_speed -= delta; }
};

// == < Plane > == //
class Plane : public ObjectOperators, public ObjectFly
{
public:
    Plane() : Object(), ObjectOperators(), ObjectFly() {}
    Plane(int x, int y, int z)
        : Object(x, y), ObjectOperators(x, y), ObjectFly(z) {}

    // Inherits set_speed, operator+=, etc.
    virtual ~Plane() = default;
};

/********** Main Function **********/

int main(void)
{
    Plane pl(20, 43, 100);
    pl.set_speed(10);
    pl += 5;

    __ASSERT_TESTS__

    return 0;
}