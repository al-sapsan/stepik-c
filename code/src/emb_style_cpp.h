/**
 * @file emb_style_cpp.h
 * @brief Coding style for Embedded C++ (bare-metal/RTOS/robotics)
 *
 * Supported platforms: ARM Cortex-M, RISC-V, Xtensa (ESP32), RP2040
 *
 * @version 3.3
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
    // 📘 Структура кода
    //==============================================================================

    /**
     * 1. Общие сведения (имя файла, назначение, платформа, версия, дата)
     Пример:
        * @file motor_control.c
        * @brief Драйвер управления двигателями (ПИД-регулятор)
        * @version 1.1 (STM32F4xx HAL)
         * @date 2023-08-15
        *
        * @warning Не использовать с DMA без проверки буферов!
        * @note Максимальная частота обновления - 1 кГц

     * 2. Используемые библиотеки (группировать по назначению)
    Пример:
        // === Core ===
        #include <stdint.h>
        #include "stm32f4xx_hal.h"

        // === Drivers ===
        #include "encoder.h"
        #include "pwm.h"

        // === RTOS ===
        #include "FreeRTOS.h"
        #include "task.h"

     * 3. Типы данных
    Пример:
        * typedef int16_t i16_t;
        * typedef uint32_t u32_t;
     * 4. Константы
    Пример:
        * constexpr u16_t MAX_BUFFER_SIZE = 128;
        * constexpr u32_t TIMEOUT_MS_DEFAULT = 1000;
        * constexpr f32_t PI_CONST = 3.1415926f;
     * 5. Прототипы функций с doxygen комментариями
    Пример:
        * @brief Инициализация ПИД-регулятора
        * @param pid Указатель на структуру (должен быть валидным)
        * @param kp Коэффициент пропорциональный [0.0 - 5.0]
        * @return HAL_StatusTypeDef Статус инициализации
        HAL_StatusTypeDef pid_init(pid_controller_t* pid, float kp);

     * 6. Главная функция
     * 7. Реализация функций
     *
     * Указанные заголовки выводятся в следующей нотации
     * Пример:
     * /*** Текст заголовка ***/

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
    // 🧱 Variable Naming Conventions
    //==============================================================================

    /*
     * Format:
     * [scope][description]_[type][unit]
     *
     * Scope prefixes:
     *   g_      -> global
     *   s_      -> static (module-local)
     *   m_      -> member (struct/class)
     *   ptr_    -> pointer
     *   vptr_   -> volatile pointer
     *   ref_    -> reference (C++)
     *   arr_    -> array (C++)
     *
     * Type suffixes:
     *   _u8     -> uint8_t
     *   _i8     -> int8_t
     *   _u16    -> uint16_t
     *   _i16    -> int16_t
     *   _u32    -> uint32_t
     *   _i32    -> int32_t
     *   _f32    -> float
     *   _f64    -> double
     *   _b      -> bool
     *
     *   _vu8    -> volatile u8_t
     *   _vu16   -> volatile u16_t
     *   _vu32   -> volatile u32_t
     *   _au32   -> atomic_uint
     */
    // Example:
    volatile u32_t g_system_ticks_vu32 = 0; // Volatile global (e.g., SysTick counter)
    f32_t g_battery_voltage_f32;            // Global float (accessible across modules)
    static i16_t s_error_count_i16 = 0;     // Static (file-scoped) counter
    u8_t *ptr_buffer_u8;                    // Pointer to uint8_t buffer
    pid_params_t *ptr_pid;                  // Pointer to PID struct
    volatile i16_t *vptr_sensor_data_i16;   // Pointer to volatile sensor data
    u16_t (*ptr_arr_matrix_u16)[4];         // Pointer to 4-element array of u16_t
    f32_t &ref_offset_f32 = 1.25f;          // Reference parameter
    f32_t arr_waypoints_f32[10];            // Array of waypoint coordinates

    /** Loop variables:
     *  i, j, k  -> simple loops
     *  row, col -> matrix/array loops
     *  full names -> other cases
     */
    // Example:
    for (u8_t i_u8 = 0; i_u8 < 10; i_u8++)
    { // Standard loop index
        arr_waypoints_f32[i_u8] = 0.0f;
    }

    for (u8_t row_u8 = 0; row_u8 < 4; row_u8++)
    { // Multi-Dimensional Loops
        for (u8_t col_u8 = 0; col_u8 < 4; col_u8++)
        {
            matrix[row_u8][col_u8] = 0;
        }
    }

    //==============================================================================
    // 🧩 Типы данных
    //==============================================================================

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

    // Базовые типы
    typedef uint8_t u8_t;   ///< Unsigned 8-bit integer   [0, 255]
    typedef int8_t i8_t;    ///< Signed 8-bit integer     [-128, 127]
    typedef uint16_t u16_t; ///< Unsigned 16-bit integer  [0, 65_535]
    typedef int16_t i16_t;  ///< Signed 16-bit integer    [-32_768, 32_767]
    typedef uint32_t u32_t; ///< Unsigned 32-bit integer  [0, 4_294_967_295]
    typedef int32_t i32_t;  ///< Signed 32-bit integer    [-2_147_483_648, 2_147_483_647]
    typedef float f32_t;    ///< 32-bit float             [~±1.18e−38, ±3.4e+38] (approx)
    typedef double f64_t;   ///< 64-bit double            [~±2.23e−308, ±1.79e+308] (approx)
    typedef bool b_t;       ///< Boolean                  [false, true]

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