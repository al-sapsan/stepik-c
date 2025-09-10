/**********************************************************************
 * @file script7.cpp
 * @brief Класс MotherBoard, структуры CPU и Memory с конструкторами
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-10
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Struct Definition ***/
/**
 * @brief Структура CPU
 */
struct CPU
{
    std::string model; ///< модель CPU
    double fr;         ///< тактовая частота (ГГц)
    /**
     * @brief Конструктор по умолчанию
     */
    CPU() : model(""), fr(0.0) {}
    /**
     * @brief Конструктор с параметрами
     * @param[in] m модель
     * @param[in] f частота
     */
    CPU(const std::string &m, double f) : model(m), fr(f) {}
};

/**
 * @brief Структура Memory
 */
struct Memory
{
    std::string name;          ///< наименование
    unsigned long long volume; ///< размер памяти (байты)
    /**
     * @brief Конструктор по умолчанию
     */
    Memory() : name(""), volume(0) {}
    /**
     * @brief Конструктор с параметрами
     * @param[in] n наименование
     * @param[in] v размер
     */
    Memory(const std::string &n, unsigned long long v) : name(n), volume(v) {}
};

/*** Class Definition ***/
class MotherBoard
{
public:
    MotherBoard(const CPU &cpu, const Memory &mem_1, const Memory &mem_2)
        : cpu(cpu), mems{mem_1, mem_2}
    {
    }
    CPU &get_cpu() { return cpu; }
    Memory *get_mems() { return mems; }

private:
    CPU cpu;
    Memory mems[2];
};

/*** Main Function ***/
int main(void)
{
    // создаём объект MotherBoard через new
    CPU cpu("CORE i5", 1.7);
    Memory mem1("Samsung", 4000000000ULL);
    Memory mem2("Kingston", 8000000000ULL);
    MotherBoard *ptr_mb = new MotherBoard(cpu, mem1, mem2);

    delete ptr_mb;
    ptr_mb = nullptr;

    return 0;
}
