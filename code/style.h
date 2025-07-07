/**
 * @file style.h
 * @brief Coding style reference for embedded C projects
 *
 * This header defines naming conventions, typedefs, and examples
 * to maintain consistency across embedded C codebases.
 */

#ifndef STYLE_H
#define STYLE_H

#ifdef __cplusplus
extern "C"
{
#endif

    //==============================================================================
    // 🧩 Типы данных (typedef для читаемости и сокращения)
    //==============================================================================

#include <stdint.h>
#include <stdbool.h>

    typedef uint8_t u8_t;   /**< Unsigned 8-bit integer  */
    typedef int8_t i8_t;    /**< Signed 8-bit integer    */
    typedef uint16_t u16_t; /**< Unsigned 16-bit integer */
    typedef int16_t i16_t;  /**< Signed 16-bit integer   */
    typedef uint32_t u32_t; /**< Unsigned 32-bit integer */
    typedef int32_t i32_t;  /**< Signed 32-bit integer   */
    typedef float f32_t;    /**< 32-bit floating point   */
    typedef double f64_t;   /**< 64-bit floating point   */
    typedef bool b_t;       /**< Boolean type            */
    typedef char ch_t;      /**< Character type          */

    //==============================================================================
    // 🔠 Константы (в SCREAMING_SNAKE_CASE)
    //==============================================================================

#define MAX_BUFFER_SIZE 128
#define TIMEOUT_MS_DEFAULT 1000
#define PI_CONST 3.1415926f

    //==============================================================================
    // 🧱 Соглашения по именованию переменных
    //==============================================================================

    /*
     * Формат:
     * [область_видимости][описание]_[тип][единица_измерения]
     *
     * Префиксы по области видимости:
     *   g_      -> global
     *   s_      -> static (в пределах модуля)
     *   l_      -> local (внутри функции)
     *   m_      -> member (член структуры)
     *
     * По назначению:
     *   buf_    -> буфер
     *   cnt_    -> счётчик
     *   flag_   -> флаг
     *   idx_    -> индекс
     *   reg_    -> регистр
     *   adc_    -> АЦП значение
     *   gpio_   -> GPIO пин
     *
     * Префиксы по типу:
     *   u8_     -> uint8_t
     *   i16_    -> int16_t
     *   f32_    -> float
     *   b_      -> bool
     *   ptr_    -> указатель
     *
     */

    //==============================================================================
    // 📘 Примеры структур и переменных
    //==============================================================================

    /// @brief Примеры переменных
    g_voltage_u16_mV             // Глобальная переменная, напряжение, uint16_t, милливольты
        m_current_f32_A          // Член структуры, ток, float32, амперы
            s_encoder_i32_pulses // Static-переменная, счётчик энкодера, int32_t, импульсы

        /// @brief Структура конфигурации UART
        typedef struct
    {
        u32_t m_baud_rate_u32;
        u8_t m_data_bits_u8;
        u8_t m_stop_bits_u8;
        b_t m_parity_enable_b;
    } uart_cfg_t;

    /// @brief Глобальные переменные (пример)
    extern u8_t g_device_id_u8;
    extern b_t g_data_ready_b;

    /// @brief Пример статической переменной (только внутри модуля .c)
    static u8_t s_rx_buffer_u8[MAX_BUFFER_SIZE];

    /// @brief Пример локальной переменной
    void example_function(void)
    {
        u16_t l_counter_u16 = 0;
        b_t l_ready_b = false;
    }

    /// @brief Пример структуры устройства
    typedef struct
    {
        f32_t m_temperature_f32_c;
        u16_t m_adc_value_u16;
        b_t m_active_b;
    } sensor_t;

    //==============================================================================
    // 🛠 Пример макроса обработки ошибок
    //==============================================================================

#define CHECK_NULL(ptr)    \
    do                     \
    {                      \
        if ((ptr) == NULL) \
        {                  \
            return;        \
        }                  \
    } while (0)

#ifdef __cplusplus
}
#endif

#endif /* STYLE_H */

// Использование style.h ссылка ниже:
// https://github.com/al-sapsan/stepik-c/wiki/4.-Использование-style.h-в-разработке