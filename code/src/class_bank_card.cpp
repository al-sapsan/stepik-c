
/************************************************************************
 * @file class_bank_card.cpp
 * @brief Класс BankCard для проверки и хранения номера банковской карты
 * @version 1.0 (Embedded C++ bare-metal/RTOS)
 * @date 2025-10-04
 *
 * @warning Не использовать без проверки формата!
 * @note Класс протестирован для платформ: ARM Cortex-M, RISC-V, Xtensa (ESP32), RP2040
 *************************************************************************/

#include <iostream>
#include <string>
#include <exception>

/********** Exception Classes **********/

// == < Class CardError > == //
/**
 * @brief Базовый класс исключения для ошибок банковской карты
 */
class CardError : public std::exception
{
protected:
    std::string m_msg; ///< Сообщение об ошибке
public:
    /**
     * @brief Конструктор исключения
     * @param error Сообщение об ошибке
     */
    explicit CardError(const char *error) : m_msg(error) {}
    /**
     * @brief Получить сообщение об ошибке
     */
    const char *what() const noexcept override { return m_msg.c_str(); }
};

// == < Class CardLengthError > == //
/**
 * @brief Исключение: некорректная длина номера карты
 */
class CardLengthError : public CardError
{
public:
    explicit CardLengthError(const char *error) : CardError(error) {}
};

// == < Class CardFormatError > == //
/**
 * @brief Исключение: некорректный формат номера карты
 */
class CardFormatError : public CardError
{
public:
    explicit CardFormatError(const char *error) : CardError(error) {}
};

// == < Class CardNumberError > == //
/**
 * @brief Исключение: номер карты содержит недопустимые символы
 */
class CardNumberError : public CardError
{
public:
    explicit CardNumberError(const char *error) : CardError(error) {}
};

/************ Class Definition ***********/

// == < Class BankCard > == //
/**
 * @brief Класс для проверки и хранения номера банковской карты
 */
class BankCard
{
    static constexpr int kLengthNumber{19}; ///< Длина номера карты
    std::string m_number;                   ///< Номер карты

    /**
     * @brief Проверить корректность номера карты
     * @param card Строка с номером карты
     * @throws CardLengthError, CardFormatError, CardNumberError
     */
    void verify_correct(const std::string &card) const
    {
        if (card.length() != kLengthNumber)
            throw CardLengthError("incorrect length card number");

        const char *p = card.c_str();
        for (int i = 0; i < kLengthNumber; ++i)
        {
            if (i == 4 || i == 9 || i == 14)
            {
                if (p[i] != '-')
                    throw CardFormatError("incorrect format");
            }
            else if (p[i] < '0' || p[i] > '9')
                throw CardNumberError("only numbers are allowed");
        }
    }

public:
    /**
     * @brief Установить номер карты
     * @param card Строка с номером карты
     * @throws CardLengthError, CardFormatError, CardNumberError
     */
    void set_number(const std::string &card)
    {
        verify_correct(card);
        m_number = card;
    }

    /**
     * @brief Получить номер карты
     * @return Строка с номером
     */
    const std::string &get_number() const { return m_number; }
};

/********** Main Function **********/

int main()
{
    BankCard card;

    try
    {
        card.set_number("123a-4567-1234-5678");
    }
    catch (const CardLengthError &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const CardFormatError &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const CardNumberError &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const CardError &e)
    {
        std::cout << "CardError: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}