/**********************************************************************
 * @file script8.cpp
 * @brief Tag wrapping for strings (embedded C++ style)
 * @version 2.1
 * @date 2025-08-20
 **********************************************************************/

#include <iostream>
#include <string>

/*** Function Prototypes ***/
/**
 * @brief  Оборачивает строку в тег
 * @param  title    Строка для оборачивания (std::string, изменяется)
 * @param  tag      Тег для оборачивания (std::string, по умолчанию "h1")
 */
void set_tag(std::string &str, const std::string &tag = "h1");

/*** Main Function ***/
int main(void)
{
    std::string title;
    std::string tag;
    std::getline(std::cin, title);
    std::getline(std::cin, tag);

    std::string title1 = title;
    set_tag(title1);
    std::cout << title1 << std::endl;

    std::string title2 = title;
    set_tag(title2, tag);
    std::cout << title2 << std::endl;

    return 0;
}

/*** Function Implementation ***/
void set_tag(std::string &str, const std::string &tag)
{
    str = "<" + tag + ">" + str + "</" + tag + ">";
}
