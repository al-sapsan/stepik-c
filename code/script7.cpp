/**
 * @file    script7.cpp
 * @brief   Выводит отличников заданной группы и их средний возраст
 * @version 1.0
 * @date    2025-07-17
 */

#include <iostream>
#include <iomanip>
#include <string>

/*** Types ***/
struct Student
{
    std::string surname;
    std::string name;
    std::string group;
    int age;
    double avg;
};

/*** Main Function ***/
int main()
{
    const int N = 8;
    Student arr[N];
    for (int i = 0; i < N; ++i)
    {
        std::cin >> arr[i].surname >> arr[i].name >> arr[i].group >> arr[i].age >> arr[i].avg;
    }
    std::string search_group;
    std::cin >> search_group;
    int sum_age = 0;
    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        if (arr[i].group == search_group && arr[i].avg > 8.0)
        {
            std::cout << arr[i].surname << " " << arr[i].name << " " << arr[i].group << " " << arr[i].age << " " << arr[i].avg << std::endl;
            sum_age += arr[i].age;
            ++count;
        }
    }
    if (count > 0)
    {
        double avg_age = static_cast<double>(sum_age) / count;
        std::cout << std::fixed << std::setprecision(1) << avg_age << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
    return 0;
}
