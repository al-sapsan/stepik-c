/**********************************************************************
 * @file script6.cpp
 * @brief GeneralView mixin pattern implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-02
 **********************************************************************/

#include <string> // for std::string

enum request_method
{
    method_get = 1,
    method_post = 2,
    method_put = 3,
    method_delete = 4
};

struct Request
{
    request_method method{method_get};
    std::string url;
    std::string data;
};

class RetriveMixin
{
    request_method m_method{method_get};

public:
    RetriveMixin(request_method *ms, int index) { ms[index] = m_method; }
    virtual ~RetriveMixin() = default;
    std::string get(const Request &request) { return "GET: " + request.url; }
};

class CreateMixin
{
    request_method m_method{method_post};

public:
    CreateMixin(request_method *ms, int index) { ms[index] = m_method; }
    virtual ~CreateMixin() = default;
    std::string post(const Request &request) { return "POST: " + request.url; }
};

class UpdateMixin
{
    request_method m_method{method_put};

public:
    UpdateMixin(request_method *ms, int index) { ms[index] = m_method; }
    virtual ~UpdateMixin() = default;
    std::string put(const Request &request) { return "PUT: " + request.url; }
};

// == < GeneralView > == //
/**
 * @brief Класс GeneralView (миксины для обработки запросов)
 * @details Поддерживает методы GET и POST, реализует паттерн mixin.
 * @note Использует RetriveMixin и CreateMixin для расширения функционала.
 */
class GeneralView : public RetriveMixin, public CreateMixin
{
    enum
    {
        max_methods = 4
    };
    int m_count_methods{2};
    request_method m_allowed_methods[max_methods]{method_get, method_post};

    bool is_method_exists(request_method method)
    {
        for (int i = 0; i < m_count_methods; ++i)
            if (m_allowed_methods[i] == method)
                return true;
        return false;
    }

public:
    GeneralView()
        : RetriveMixin(m_allowed_methods, 0), CreateMixin(m_allowed_methods, 1) {}

    std::string render_request(const Request &request)
    {
        if (!is_method_exists(request.method))
            return "";
        if (request.method == method_get)
            return get(request);
        if (request.method == method_post)
            return post(request);
        return "";
    }
};

/********** Main Function **********/

int main(void)
{
    GeneralView gw;
    Request req{
        method_post,
        "https://proproprogs.ru/cpp_oop/cpp-oop-mnozhestvennoe-nasledovanie-poryadok-vyzova-konstruktorov-i-destruktorov",
        "<h1>Множественное наследование</h1>"};
    std::string res = gw.render_request(req);

    __ASSERT_TESTS__

    return 0;
}