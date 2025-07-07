/**
 * @file emb_style_cpp.h
 * @brief Coding style for Embedded C++ (bare-metal/RTOS/robotics)
 *
 * Supported platforms: ARM Cortex-M, RISC-V, Xtensa (ESP32), RP2040
 *
 * @version 1.0
 * @date 2025-07-07
 *
 * @copyright Copyright (c) 2025
 */

#ifndef EMB_STYLE_CPP_H
#define EMB_STYLE_CPP_H

#ifdef __cplusplus
extern "C"
{
#endif

    //==============================================================================
    // 📚 Doxygen документация
    //==============================================================================

    /**
     * @brief Краткое описание модуля/функции
     *
     * Подробное описание функциональности. Пример:
     * @code
     * sensor_init(&sensor_cfg);
     * @endcode
     *
     * @param[in] param1 Описание входного параметра
     * @param[out] param2 Описание выходного параметра
     * @return err_code_t Код ошибки (см. err_code_t)
     *
     * @note Важные замечания по использованию
     * @warning Предупреждения о безопасности
     * @see Другие связанные функции
     */

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
    // 🧩 Типы данных
    //==============================================================================

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

    // Базовые типы
    typedef uint8_t u8_t;
    typedef int8_t i8_t;
    typedef uint16_t u16_t;
    typedef int16_t i16_t;
    typedef uint32_t u32_t;
    typedef int32_t i32_t;
    typedef float f32_t;
    typedef double f64_t;
    typedef bool b_t;
    typedef char ch_t;

    // Volatile версии для работы с регистрами
    typedef volatile uint8_t vu8_t;
    typedef volatile uint16_t vu16_t;
    typedef volatile uint32_t vu32_t;
    typedef volatile int32_t vi32_t;

    //==============================================================================
    // 🔠 Константы (предпочтительно constexpr)
    //==============================================================================

    constexpr u16_t MAX_BUFFER_SIZE = 128; // вместо #define
    constexpr u32_t TIMEOUT_MS_DEFAULT = 1000;
    constexpr f32_t PI_CONST = 3.1415926f;
    constexpr f32_t DEG_TO_RAD = 0.0174533f;

    //==============================================================================
    // 🤖 Робототехника: специализированные типы
    //==============================================================================

    /// 2D координаты (мм)
    typedef struct
    {
        f32_t x_mm;
        f32_t y_mm;
    } coord_2d_t;

    /// 3D координаты (мм)
    typedef struct
    {
        f32_t x_mm;
        f32_t y_mm;
        f32_t z_mm;
    } coord_3d_t;

    /// Углы (градусы и радианы)
    typedef struct
    {
        f32_t roll_deg;
        f32_t pitch_deg;
        f32_t yaw_deg;
    } euler_angles_t;

    /// Параметры двигателя
    typedef struct
    {
        f32_t rpm_target;
        f32_t current_limit_A;
        u8_t pwm_duty;
    } motor_params_t;

//==============================================================================
// 🛠 Безопасность: проверки
//==============================================================================

// Проверка указателя
#define CHECK_NULL(ptr)    \
    do                     \
    {                      \
        if ((ptr) == NULL) \
        {                  \
            return;        \
        }                  \
    } while (0)

// Проверка диапазона
#define CHECK_RANGE(val, min, max)          \
    do                                      \
    {                                       \
        if ((val) < (min) || (val) > (max)) \
        {                                   \
            return;                         \
        }                                   \
    } while (0)

// Проверка с возвратом ошибки
#define CHECK_RANGE_ERR(val, min, max, err) \
    do                                      \
    {                                       \
        if ((val) < (min) || (val) > (max)) \
        {                                   \
            return (err);                   \
        }                                   \
    } while (0)

    //==============================================================================
    // ⏱ RTOS: задачи и синхронизация
    //==============================================================================

    // Рекомендуемые размеры стэков (в словах)
    constexpr u16_t TASK_STACK_MINIMAL = 128; // Минимальный (простой обработчик)
    constexpr u16_t TASK_STACK_SMALL = 256;   // Датчики, простые алгоритмы
    constexpr u16_t TASK_STACK_MEDIUM = 512;  // Умеренная логика
    constexpr u16_t TASK_STACK_LARGE = 1024;  // Сложные алгоритмы/протоколы
    constexpr u16_t TASK_STACK_HUGE = 2048;   // Машинное зрение и т.п.

    /// Шаблон задачи RTOS
    void task_template(void *pvParameters)
    {
        // Инициализация
        (void)pvParameters; // Явное подавление предупреждения

        // Основной цикл задачи
        for (;;) // Предпочтительнее while(1)
        {
            // Основная логика задачи

            // Задержка или ожидание события
            vTaskDelay(pdMS_TO_TICKS(10));
        }

        // В нормальных условиях сюда не попадаем
        vTaskDelete(NULL);
    }

    //==============================================================================
    // 📘 Примеры структур (дополненные)
    //==============================================================================

    typedef struct
    {
        coord_3d_t m_position;
        euler_angles_t m_orientation;
        motor_params_t m_motors[4];
        u32_t m_update_time_ms;
    } robot_state_t;

    /// @brief Конфигурация UART
    typedef struct
    {
        u32_t m_baud_rate_u32;
        u8_t m_data_bits_u8;
        u8_t m_stop_bits_u8;
        b_t m_parity_enable_b;
    } uart_cfg_t;

    /// @brief Пример структуры датчика
    typedef struct
    {
        f32_t m_temperature_f32_C;
        u16_t m_adc_value_u16;
        b_t m_active_b;
    } sensor_t;

    /// @brief Пример глобальных переменных
    extern u8_t g_device_id_u8;
    extern b_t g_data_ready_b;

    /// @brief Пример статической переменной
    static u8_t s_rx_buffer_u8[MAX_BUFFER_SIZE];

    //==============================================================================
    // 🧠 Прерывания (ISR)
    //==============================================================================
    /*
     * - Использовать префикс _isr
     * - Минимум логики
     * - Никакой динамической памяти
     * - Только volatile переменные или флаги
     * - Можно использовать __attribute__((interrupt)) при необходимости
     */

    // Пример:
    void exti0_isr(void);

    //==============================================================================
    // ⏱ RTOS соглашения
    //==============================================================================
    /*
     * - enum class State_t : u8_t {} для FSM
     * - Префиксы: task_, sem_, evt_, msg_, etc.
     * - volatile и atomic для синхронизации
     */

    //==============================================================================
    // 🧮 Пространства имён
    //==============================================================================

    namespace hal
    {
        void gpio_write(u8_t pin, b_t value);
        b_t gpio_read(u8_t pin);
    }

    namespace ctrl
    {
        typedef struct
        {
            f32_t m_kp_f32;
            f32_t m_ki_f32;
            f32_t m_kd_f32;
            f32_t m_error_f32;
        } pid_t;

        void pid_reset(pid_t *ptr_pid);
        f32_t pid_compute(pid_t *ptr_pid, f32_t l_input_f32, f32_t l_target_f32);
    }

//==============================================================================
// ⚠ Исключено из соглашения (не использовать в embedded C++)
//==============================================================================
/*
 * - std::shared_ptr, std::unique_ptr
 * - std::vector, std::string
 * - new/delete
 * - Исключения (try/catch)
 * - RTTI (Run-Time Type Info)
 */

//==============================================================================
// 🛠 Пример безопасного макроса
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
} // extern "C"
#endif

#endif /* EMB_STYLE_CPP_H */