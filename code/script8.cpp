/**********************************************************************
 * @file script8.cpp
 * @brief Printer, PrinterJet, PrinterLaser class implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-09-25
 **********************************************************************/

#include <iostream>
#include <string>

/********** Class Prototypes **********/
// == < Printer > == //
/**
 * @brief Класс принтера
 * @param model Модель принтера
 * @param type Тип принтера
 */
class Printer
{
public:
    enum type_printer
    {
        pr_none = 0,
        pr_needle = 1,
        pr_jet = 2,
        pr_laser = 3
    };

protected:
    std::string m_model;
    type_printer m_type{pr_none};

public:
    Printer(const std::string &model, type_printer type);
    Printer() = delete;

    const std::string &get_model() const;
    type_printer get_type() const;
};

// == < PrinterJet > == //
/**
 * @brief Класс струйного принтера
 * @param color Цветной принтер
 * @param speed Скорость печати
 */
class PrinterJet : public Printer
{
private:
    bool m_color{false};
    short m_speed{0};

public:
    PrinterJet(const std::string &model, bool color, short speed);

    void get_data(std::string &model, type_printer &type, bool &color, short &speed) const;
};

// == < PrinterLaser > == //
/**
 * @brief Класс лазерного принтера
 * @param color Цветной принтер
 * @param speed Скорость печати
 */
class PrinterLaser : public Printer
{
private:
    bool m_color{false};
    short m_speed{0};

public:
    PrinterLaser(const std::string &model, bool color, short speed);

    void get_data(std::string &model, type_printer &type, bool &color, short &speed) const;
};

/********** Main Function **********/
int main(void)
{
    Printer *pr_lst[4];

    pr_lst[0] = new PrinterJet("Brother Jet 600", true, 5);
    pr_lst[1] = new PrinterLaser("Canon Laser 10", false, 10);
    pr_lst[2] = new PrinterJet("Samsung Jet 100", true, 7);
    pr_lst[3] = new PrinterLaser("BaLaser 1 Pro", true, 21);

    __ASSERT_TESTS__

    for (int i = 0; i < 4; ++i)
    {
        delete pr_lst[i];
    }

    return 0;
}

/********** Function Implementations **********/
// == < Printer Implementation > == //
Printer::Printer(const std::string &model, type_printer type)
    : m_model(model),
      m_type(type)
{
}

const std::string &Printer::get_model() const
{
    return m_model;
}

Printer::type_printer Printer::get_type() const
{
    return m_type;
}

// == < PrinterJet Implementation > == //
PrinterJet::PrinterJet(const std::string &model, bool color, short speed)
    : Printer(model, pr_jet), m_color(color), m_speed(speed)
{
}

void PrinterJet::get_data(std::string &model, type_printer &type, bool &color, short &speed) const
{
    model = m_model;
    type = m_type;
    color = m_color;
    speed = m_speed;
}

// == < PrinterLaser Implementation > == //
PrinterLaser::PrinterLaser(const std::string &model, bool color, short speed)
    : Printer(model, pr_laser), m_color(color), m_speed(speed)
{
}

void PrinterLaser::get_data(std::string &model, type_printer &type, bool &color, short &speed) const
{
    model = m_model;
    type = m_type;
    color = m_color;
    speed = m_speed;
}
