/**********************************************************************
 * @file script8.cpp
 * @brief Класс Notebook: конструкторы, set/get, информация о ноутбуке
 * @version 1.0 (Embedded C++ style)
 * @date 2025-09-10
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <string>

/*** Class Definition ***/
/**
 * @brief Класс для хранения информации о ноутбуке
 */
class Notebook
{
public:
    /**
     * @brief Конструктор по умолчанию
     */
    Notebook() : model(""), cpu_model(""), memory(0), disk_volume(0) {}
    /**
     * @brief Конструктор с моделью
     * @param[in] model модель ноутбука
     */
    Notebook(const std::string &model) : model(model), cpu_model(""), memory(0), disk_volume(0) {}
    /**
     * @brief Конструктор с моделью (C-строка)
     * @param[in] model модель ноутбука (C-строка)
     */
    Notebook(const char *model) : model(model), cpu_model(""), memory(0), disk_volume(0) {}
    /**
     * @brief Конструктор с моделью и CPU
     * @param[in] model модель ноутбука
     * @param[in] cpu модель CPU
     */
    Notebook(const std::string &model, const std::string &cpu) : model(model), cpu_model(cpu), memory(0), disk_volume(0) {}
    /**
     * @brief Конструктор с моделью, CPU и памятью
     * @param[in] model модель ноутбука
     * @param[in] cpu модель CPU
     * @param[in] mem объем памяти
     */
    Notebook(const std::string &model, const std::string &cpu, unsigned mem) : model(model), cpu_model(cpu), memory(mem), disk_volume(0) {}
    /**
     * @brief Конструктор с моделью, CPU, памятью и диском
     * @param[in] model модель ноутбука
     * @param[in] cpu модель CPU
     * @param[in] mem объем памяти
     * @param[in] disk объем диска
     */
    Notebook(const std::string &model, const std::string &cpu, unsigned mem, unsigned disk) : model(model), cpu_model(cpu), memory(mem), disk_volume(disk) {}
    /**
     * @brief Установить данные
     * @param[in] model модель ноутбука
     * @param[in] cpu модель CPU
     * @param[in] memory объем памяти
     * @param[in] disk объем диска
     */
    void set_data(const std::string &model, const std::string &cpu, unsigned memory, unsigned disk)
    {
        this->model = model;
        this->cpu_model = cpu;
        this->memory = memory;
        this->disk_volume = disk;
    }
    /**
     * @brief Получить модель ноутбука
     * @return std::string&
     */
    std::string &get_model() { return model; }
    /**
     * @brief Получить модель CPU
     * @return std::string&
     */
    std::string &get_cpu() { return cpu_model; }
    /**
     * @brief Получить память и диск
     * @param[out] mem память
     * @param[out] disk объем диска
     */
    void get_info(unsigned &mem, unsigned &disk)
    {
        mem = memory;
        disk = disk_volume;
    }

private:
    std::string model;       ///< модель ноутбука
    std::string cpu_model;   ///< модель CPU
    unsigned memory{0};      ///< объем памяти (Мб)
    unsigned disk_volume{0}; ///< объем диска (Гб)
};

/*** Main Function ***/
int main(void)
{
    // создаём объект note с нужными данными
    Notebook note;
    note.set_data("HP", "Core i7", 16000, 512);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

        return 0;
}
