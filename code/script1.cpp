/**********************************************************************
 * @file script1.cpp
 * @brief Object heap-only implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-02
 **********************************************************************/

#include <iostream>

/********** Class Definition **********/

class Object
{
private:
    ~Object() = default;

public:
    Object() = default;

    Object(const Object &) = delete;
    Object &operator=(const Object &) = delete;
    Object(Object &&) = delete;
    Object &operator=(Object &&) = delete;

    static void remove_object(Object *obj)
    {
        delete obj;
    }
};

/********** Main Function **********/

int main(void)
{
    Object *ptr_obj = new Object;

    __ASSERT_TESTS__

    return 0;
}