/**********************************************************************
 * @file script6.cpp
 * @brief Класс Graph: динамический массив, конструкторы, деструктор, set/get
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-10
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Class Definition ***/
/**
 * @brief Класс для хранения массива вещественных значений
 */
class Graph
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Graph() : data(nullptr), length(0) {}
    /**
     * @brief Конструктор с массивом
     * @param[in] ar массив double
     * @param[in] size размер массива
     */
    Graph(const double *ar, int size) : data(nullptr), length(0)
    {
        set_data(ar, size);
    }
    /**
     * @brief Деструктор: освобождает память
     */
    ~Graph()
    {
        delete[] data;
    }
    /**
     * @brief Передать данные в массив
     * @param[in] ar массив double
     * @param[in] size размер массива
     */
    void set_data(const double *ar, int size)
    {
        if (data)
            delete[] data;
        if (ar && size > 0)
        {
            data = new double[size];
            for (int i = 0; i < size; ++i)
                data[i] = ar[i];
            length = size;
        }
        else
        {
            data = nullptr;
            length = 0;
        }
    }
    /**
     * @brief Получить указатель на массив
     * @return double*
     */
    double *get_data() { return data; }
    /**
     * @brief Получить длину массива
     * @return int
     */
    int get_length() { return length; }

private:
    double *data;
    int length;
};

/*** Main Function ***/
int main(void)
{
    // создаём объект gr
    Graph gr;
    double coords[] = {5, 0.4, 2.7, -3.2};
    gr.set_data(coords, sizeof(coords) / sizeof(*coords));

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        return 0;
}
