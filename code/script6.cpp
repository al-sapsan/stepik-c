/**********************************************************************
 * @file script6.cpp
 * @brief Класс StudentMarks: оператор сложения, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-15
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс StudentMarks: массив оценок, оператор сложения
 */
class StudentMarks
{
public:
    /**
     * @brief Конструктор
     * @param[in] ms массив оценок
     * @param[in] total количество оценок
     */
    StudentMarks(short *ms, int total);
    /**
     * @brief Получить массив оценок
     * @return const short*
     */
    const short *get_marks() const;
    /**
     * @brief Получить количество оценок
     * @return int
     */
    int get_count() const;
    /**
     * @brief Сложение двух объектов StudentMarks
     * @param[in] other другой объект
     * @return StudentMarks
     */
    StudentMarks operator+(const StudentMarks &other) const;
    /**
     * @brief Сложение с оценкой (StudentMarks + short)
     * @param[in] val оценка
     * @return StudentMarks
     */
    StudentMarks operator+(short val) const;
    /**
     * @brief Сложение с оценкой (short + StudentMarks)
     * @param[in] val оценка
     * @param[in] sm объект StudentMarks
     * @return StudentMarks
     */
    friend StudentMarks operator+(short val, const StudentMarks &sm);

private:
    enum
    {
        m_max_length = 100
    };
    short m_marks[m_max_length]{0}; ///< массив оценок
    int m_count{0};                 ///< количество оценок
};

/*** Methods Implementation ***/
StudentMarks::StudentMarks(short *ms, int total)
{
    m_count = (total > m_max_length) ? m_max_length : total;
    for (int i = 0; i < m_count; ++i)
        m_marks[i] = ms[i];
}

const short *StudentMarks::get_marks() const { return m_marks; }
int StudentMarks::get_count() const { return m_count; }

StudentMarks StudentMarks::operator+(const StudentMarks &other) const
{
    short res[m_max_length];
    int n = 0;
    for (int i = 0; i < m_count && n < m_max_length; ++i)
        res[n++] = m_marks[i];
    for (int i = 0; i < other.m_count && n < m_max_length; ++i)
        res[n++] = other.m_marks[i];
    return StudentMarks(res, n);
}

StudentMarks StudentMarks::operator+(short val) const
{
    short res[m_max_length];
    int n = 0;
    for (int i = 0; i < m_count && n < m_max_length; ++i)
        res[n++] = m_marks[i];
    if (n < m_max_length)
        res[n++] = val;
    return StudentMarks(res, n);
}

StudentMarks operator+(short val, const StudentMarks &sm)
{
    short res[StudentMarks::m_max_length];
    int n = 0;
    res[n++] = val;
    for (int i = 0; i < sm.m_count && n < StudentMarks::m_max_length; ++i)
        res[n++] = sm.m_marks[i];
    return StudentMarks(res, n);
}