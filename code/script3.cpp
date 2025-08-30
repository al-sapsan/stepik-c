/**********************************************************************
 * @file script3.cpp
 * @brief object struct with methods, smart pointers, linking
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-30
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <memory>

struct object
{
private:
    short data;
    object *next;

public:
    object(short d) : data(d), next(nullptr) {}
    object *get_next() { return next; }
    short get_data() { return data; }
    void set_next(object *ptr) { next = ptr; }
    void set_data(short d) { data = d; }
};

/*** Main Function ***/
int main(void)
{
    std::unique_ptr<object> ptr = std::make_unique<object>(1), top = std::make_unique<object>(2);
    top->set_next(ptr.get());
    ptr->set_next(nullptr);
    ptr->set_data(1);
    top->set_data(2);
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
