/**********************************************************************
 * @file script5.cpp
 * @brief Класс ExtensionFilter, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-22
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/*** Class Definition ***/
/**
 * @brief Класс ExtensionFilter: фильтр по расширениям файлов
 */
class ExtensionFilter
{
public:
    /**
     * @brief Конструктор
     * @param[in] ext_str строка расширений через '|'
     */
    ExtensionFilter(const std::string &ext_str);
    /**
     * @brief Фильтрация файлов по расширениям
     * @param[in] lst массив файлов
     * @param[in] size_lst размер массива lst
     * @param[out] flt_lst массив для результата
     * @param[in] max_count максимальный размер flt_lst
     * @return int число отобранных файлов
     */
    int operator()(const std::string *lst, int size_lst, std::string *flt_lst, int max_count) const;

private:
    std::vector<std::string> extensions;
    static std::string get_extension(const std::string &filename);
};

/*** Methods Implementation ***/
ExtensionFilter::ExtensionFilter(const std::string &ext_str)
{
    std::stringstream ss(ext_str);
    std::string ext;
    while (std::getline(ss, ext, '|'))
    {
        extensions.push_back(ext);
    }
}
std::string ExtensionFilter::get_extension(const std::string &filename)
{
    size_t pos = filename.rfind('.');
    if (pos == std::string::npos || pos == filename.length() - 1)
        return "";
    return filename.substr(pos + 1);
}
int ExtensionFilter::operator()(const std::string *lst, int size_lst, std::string *flt_lst, int max_count) const
{
    int count = 0;
    for (int i = 0; i < size_lst && count < max_count; ++i)
    {
        std::string ext = get_extension(lst[i]);
        for (const auto &allowed : extensions)
        {
            if (ext == allowed)
            {
                flt_lst[count++] = lst[i];
                break;
            }
        }
    }
    return count;
}
