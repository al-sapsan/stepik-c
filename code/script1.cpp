/**********************************************************************
 * @file script1.cpp
 * @brief Структура volume с методом get_volume (embedded C++ style)
 * @version 1.0 (Stepik exercise)
 * @date 2025-08-26
 **********************************************************************/

#include <iostream>

struct volume
{
    int width;
    int height;
    int depth;
    /**
     * @brief Вычисляет объем
     * @return Объем (целое число)
     */
    int get_volume(void) const
    {
        return width * height * depth;
    }
};

/*** Main Function ***/
/**
 * @brief  Точка входа в программу
 * @return Код завершения (0 — успешно, 1 — ошибка памяти)
 */
int main(void)
{
    volume data;
    std::cin >> data.width >> data.height >> data.depth;
    std::cout << data.get_volume() << std::endl;
    return 0;
}
