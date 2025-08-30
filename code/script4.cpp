/**********************************************************************
 * @file script4.cpp
 * @brief Stack with object, push, print top-to-bottom
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

using st_unique_ptr = std::unique_ptr<object>;

void push(st_unique_ptr &top, short data)
{
    st_unique_ptr new_obj = std::make_unique<object>(data);
    new_obj->set_next(top.release());
    top.reset(new_obj.release());
}

/*** Main Function ***/
int main(void)
{
    st_unique_ptr top;
    for (int i = 1; i <= 7; ++i)
        push(top, i);
    object *curr = top.get();
    while (curr)
    {
        std::cout << curr->get_data();
        if (curr->get_next())
            std::cout << " ";
        curr = curr->get_next();
    }
    std::cout << std::endl;
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
        return 0;
}
