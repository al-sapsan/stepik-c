/**********************************************************************
 * @file script5.cpp
 * @brief Класс DataThree: максимум три уникальных объекта, get_new_data
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-12
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс DataThree: максимум три уникальных объекта
 */
class DataThree
{
public:
    /**
     * @brief Получить новый объект (до 3-х уникальных)
     * @return указатель на объект
     */
    static DataThree *get_new_data()
    {
        if (m_count < 3)
        {
            m_objs[m_count] = new DataThree();
            return m_objs[m_count++];
        }
        else
        {
            return m_objs[2];
        }
    }
    /**
     * @brief Удалить все уникальные объекты
     */
    static void delete_all()
    {
        for (int i = 0; i < 3; ++i)
        {
            delete m_objs[i];
            m_objs[i] = nullptr;
        }
        m_count = 0;
    }
    DataThree(const DataThree &) = delete;
    DataThree &operator=(const DataThree &) = delete;

private:
    static DataThree *m_objs[3];
    static int m_count;
    DataThree() = default;
};

/*** Static Members Initialization ***/
DataThree *DataThree::m_objs[3] = {nullptr, nullptr, nullptr};
int DataThree::m_count = 0;

/*** Main Function ***/
int main(void)
{
    DataThree *ptr_dates[5];
    for (int i = 0; i < 5; ++i)
    {
        ptr_dates[i] = DataThree::get_new_data();
    }

    // освобождаем только три уникальных объекта через публичный метод
    DataThree::delete_all();

    return 0;
}
