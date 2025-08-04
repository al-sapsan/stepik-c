/**********************************************************************
 * @file emb_style_cpp.h
 * @brief Coding style for Embedded C++ (bare-metal/RTOS/robotics)
 *
 * Supported platforms: ARM Cortex-M, RISC-V, Xtensa (ESP32), RP2040
 *
 * @version 3.3
 * @date 2025-07-07
 *
 * @copyright Copyright (c) 2025
 **********************************************************************/

#ifndef EMB_STYLE_CPP_H
#define EMB_STYLE_CPP_H

#ifdef __cplusplus
extern "C"
{
#endif

    //==============================================================================
    //  Code Structure
    //==============================================================================

    /************************************************************************
     * 1. General Information (filename, purpose, platform, version, date)
     * Example:
        * @file motor_control.c
        * @brief Motor control driver (PID controller)
        * @version 1.1 (STM32F4xx HAL)
        * @date 2023-08-15
        *
        * @warning Do not use with DMA without buffer checks!
        * @note Maximum update rate: 1 kHz
    *************************************************************************

     // 2. Libraries used (grouped by purpose)
     * Example:
        / *** Core *** /
        #include <stdint.h>
        #include "stm32f4xx_hal.h"

        / *** Drivers *** /
        #include "encoder.h"
        #include "pwm.h"

        / *** RTOS *** /
        #include "FreeRTOS.h"
        #include "task.h"

     // 3. Data types
     * Example:
        / *** Typedefs *** /
        typedef int16_t i16_t;
        typedef uint32_t u32_t;

     // 4. Constants
     * Example:
        / *** Constants *** /
        constexpr u16_t MAX_BUFFER_SIZE = 128;
        constexpr u32_t TIMEOUT_MS_DEFAULT = 1000;
        constexpr f32_t PI_CONST = 3.1415926f;

     // 5. Function prototypes with Doxygen comments
     * Example:
        / *** Function Prototypes *** /
        * @brief Initialize PID controller
        * @param pid Pointer to the structure (must be valid)
        * @param kp Proportional coefficient [0.0 - 5.0]
        * @return HAL_StatusTypeDef Initialization status
        HAL_StatusTypeDef pid_init(pid_controller_t* pid, float kp);

     // 6. Main function
    * Example:
        / *** Main Function *** /
        * @brief  Точка входа в программу        *
        * @return Код завершения (0 — успешно, 1 — ошибка памяти)

         int main(void){
            ...
         }

    // 7. Function implementations
     * Example:
        / *** Function Implementation *** /
        void funct() {
            ...
        }
    // 8. Section headers use the following notation:
     * Example:
        /*** Header Text ***/
    //==============================================================================
    // Doxygen Documentation
    //==============================================================================

    /**
     * @brief Brief module/function description
     *
     * Detailed functionality description. Example:
     * @code
     * sensor_init(&sensor_cfg);
     * @endcode
     *
     * @param[in] param1 Input parameter description
     * @param[out] param2 Output parameter description
     * @return err_code_t Error code (see err_code_t)
     *
     * @note Important usage notes
     * @warning Safety warnings
     * @see Related functions
     */

    //==============================================================================
    // Variable Naming Conventions
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
    //  Data Types
    //==============================================================================

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

    // Base types
    typedef uint8_t u8_t;   ///< Unsigned 8-bit integer   [0, 255]
    typedef int8_t i8_t;    ///< Signed 8-bit integer     [-128, 127]
    typedef uint16_t u16_t; ///< Unsigned 16-bit integer  [0, 65_535]
    typedef int16_t i16_t;  ///< Signed 16-bit integer    [-32_768, 32_767]
    typedef uint32_t u32_t; ///< Unsigned 32-bit integer  [0, 4_294_967_295]
    typedef int32_t i32_t;  ///< Signed 32-bit integer    [-2_147_483_648, 2_147_483_647]
    typedef float f32_t;    ///< 32-bit float             [~±1.18e−38, ±3.4e+38] (approx)
    typedef double f64_t;   ///< 64-bit double            [~±2.23e−308, ±1.79e+308] (approx)
    typedef bool b_t;       ///< Boolean                  [false, true]

    // Volatile versions for register access
    typedef volatile uint8_t vu8_t;
    typedef volatile uint16_t vu16_t;
    typedef volatile uint32_t vu32_t;
    typedef volatile int32_t vi32_t;

    //==============================================================================
    //  Constants (prefer constexpr)
    //==============================================================================

    constexpr u16_t MAX_BUFFER_SIZE = 128; // Instead of #define
    constexpr u32_t TIMEOUT_MS_DEFAULT = 1000;
    constexpr f32_t PI_CONST = 3.1415926f;
    constexpr f32_t DEG_TO_RAD = 0.0174533f;

    //==============================================================================
    //  Robotics: Specialized Types
    //==============================================================================

    /// 2D coordinates (mm)
    typedef struct
    {
        f32_t x_mm;
        f32_t y_mm;
    } coord_2d_t;

    /// 3D coordinates (mm)
    typedef struct
    {
        f32_t x_mm;
        f32_t y_mm;
        f32_t z_mm;
    } coord_3d_t;

    /// Euler angles (degrees and radians)
    typedef struct
    {
        f32_t roll_deg;
        f32_t pitch_deg;
        f32_t yaw_deg;
    } euler_angles_t;

    /// Motor parameters
    typedef struct
    {
        f32_t rpm_target;
        f32_t current_limit_A;
        u8_t pwm_duty;
    } motor_params_t;

//==============================================================================
//  Safety: Checks
//==============================================================================

// Null pointer check
#define CHECK_NULL(ptr)    \
    do                     \
    {                      \
        if ((ptr) == NULL) \
        {                  \
            return;        \
        }                  \
    } while (0)

// Range check
#define CHECK_RANGE(val, min, max)          \
    do                                      \
    {                                       \
        if ((val) < (min) || (val) > (max)) \
        {                                   \
            return;                         \
        }                                   \
    } while (0)

// Range check with error return
#define CHECK_RANGE_ERR(val, min, max, err) \
    do                                      \
    {                                       \
        if ((val) < (min) || (val) > (max)) \
        {                                   \
            return (err);                   \
        }                                   \
    } while (0)

    //==============================================================================
    //  RTOS: Tasks and Synchronization
    //==============================================================================

    // Recommended stack sizes (in words)
    constexpr u16_t TASK_STACK_MINIMAL = 128; // Minimal (simple handler)
    constexpr u16_t TASK_STACK_SMALL = 256;   // Sensors, simple algorithms
    constexpr u16_t TASK_STACK_MEDIUM = 512;  // Moderate logic
    constexpr u16_t TASK_STACK_LARGE = 1024;  // Complex algorithms/protocols
    constexpr u16_t TASK_STACK_HUGE = 2048;   // Computer vision, etc.

    /// RTOS task template
    void task_template(void *pvParameters)
    {
        // Initialization
        (void)pvParameters; // Explicit unused warning suppression

        // Main task loop
        for (;;) // Prefer over while(1)
        {
            // Main task logic

            // Delay or wait for event
            vTaskDelay(pdMS_TO_TICKS(10));
        }

        // Should never reach here
        vTaskDelete(NULL);
    }

    //==============================================================================
    //  Example Structures (Extended)
    //==============================================================================

    typedef struct
    {
        coord_3d_t m_position;
        euler_angles_t m_orientation;
        motor_params_t m_motors[4];
        u32_t m_update_time_ms;
    } robot_state_t;

    /// @brief UART configuration
    typedef struct
    {
        u32_t m_baud_rate_u32;
        u8_t m_data_bits_u8;
        u8_t m_stop_bits_u8;
        b_t m_parity_enable_b;
    } uart_cfg_t;

    /// @brief Example sensor structure
    typedef struct
    {
        f32_t m_temperature_f32_C;
        u16_t m_adc_value_u16;
        b_t m_active_b;
    } sensor_t;

    /// @brief Example global variables
    extern u8_t g_device_id_u8;
    extern b_t g_data_ready_b;

    /// @brief Example static variable
    static u8_t s_rx_buffer_u8[MAX_BUFFER_SIZE];

    //==============================================================================
    //  Interrupts (ISR)
    //==============================================================================
    /*
     * - Use _isr prefix
     * - Minimal logic
     * - No dynamic memory
     * - Only volatile variables or flags
     * - May use __attribute__((interrupt)) if needed
     */

    // Example:
    void exti0_isr(void);

    //==============================================================================
    //  RTOS Conventions
    //==============================================================================
    /*
     * - enum class State_t : u8_t {} for FSMs
     * - Prefixes: task_, sem_, evt_, msg_, etc.
     * - volatile and atomic for synchronization
     */

    //==============================================================================
    //  Namespaces
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
//  Banned in Embedded C++ (Do Not Use)
//==============================================================================
/*
 * - std::shared_ptr, std::unique_ptr
 * - std::vector, std::string
 * - new/delete
 * - Exceptions (try/catch)
 * - RTTI (Run-Time Type Info)
 */

//==============================================================================
//  Example Safety Macro
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