/**********************************************************************
 * @file script4.cpp
 * @brief Класс Memory и дружественные функции, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-15
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Types ***/
/**
 * @brief Тип памяти (производитель)
 */
enum type_memory
{
    mem_none = -1,
    mem_corsair = 1,
    mem_adata = 2,
    mem_kingston = 3
};

/*** Class Definition ***/
/**
 * @brief Класс Memory: оперативная память
 */
class Memory
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Memory();
    /**
     * @brief Конструктор с объёмом
     * @param[in] vol объём памяти
     */
    Memory(unsigned vol);
    /**
     * @brief Конструктор с объёмом и типом
     * @param[in] vol объём памяти
     * @param[in] tp тип памяти
     */
    Memory(unsigned vol, type_memory tp);
    /**
     * @brief Дружественная функция: установить данные памяти
     * @param[in,out] mem объект Memory
     * @param[in] vol объём
     * @param[in] tp тип
     */
    friend void set_memory_data(Memory &mem, unsigned vol, type_memory tp);
    /**
     * @brief Дружественная функция: получить данные памяти
     * @param[in] mem объект Memory
     * @param[out] vol объём
     * @param[out] tp тип
     */
    friend void get_memory_data(const Memory &mem, unsigned &vol, type_memory &tp);
    /**
     * @brief Оператор сложения двух Memory
     * @param[in] m1 первый объект
     * @param[in] m2 второй объект
     * @return Memory
     */
    friend Memory operator+(const Memory &m1, const Memory &m2);

private:
    type_memory m_type{mem_none};
    unsigned m_volume{0};
};

/*** Methods Implementation ***/
Memory::Memory() : m_type(mem_none), m_volume(0) {}
Memory::Memory(unsigned vol) : m_type(mem_none), m_volume(vol) {}
Memory::Memory(unsigned vol, type_memory tp) : m_type(tp), m_volume(vol) {}
void set_memory_data(Memory &mem, unsigned vol, type_memory tp)
{
    mem.m_volume = vol;
    mem.m_type = tp;
}
void get_memory_data(const Memory &mem, unsigned &vol, type_memory &tp)
{
    vol = mem.m_volume;
    tp = mem.m_type;
}
Memory operator+(const Memory &m1, const Memory &m2)
{
    if (m1.m_type == m2.m_type)
    {
        return Memory(m1.m_volume + m2.m_volume, m1.m_type);
    }
    else
    {
        return m1;
    }
}

/*** Main ***/
int main(void)
{
    Memory mem_1(8000, mem_adata);
    Memory mem_2(4000, mem_adata);
    Memory res = mem_1 + mem_2;
    __ASSERT_TESTS__
    return 0;
}
