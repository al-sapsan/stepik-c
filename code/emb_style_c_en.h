/********************************************************************
 * @file emb_style_c.h
 * @brief Embedded C coding style for robotics and real-time systems
 * @version 3.3
 * @date 2025-07-07
 *
 * @copyright Copyright (c) 2025
 ********************************************************************/

#ifndef STYLE_H
#define STYLE_H

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
        * @brief  Точка входа в программу
        *         Генерирует массив из 11 случайных значений, добавляя их динамически
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
     *   s_      -> static
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
    for (size_t i = 0; i < 10; i++)
    { // Standard loop index
        arr_waypoints_f32[i] = 0.0f;
    }

    for (size_t row = 0; row < 4; row++)
    { // Multi-Dimensional Loops
        for (size_t col = 0; col < 4; col++)
        {
            matrix[row][col] = 0;
        }
    }

    //==============================================================================
    //  Data Types and Peripherals
    //==============================================================================

#include <stdint.h>
#include <stdbool.h>
#include <stdatomic.h>

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

    // Peripherals and registers
    typedef volatile u8_t vu8_t;   ///< Volatile 8-bit
    typedef volatile u16_t vu16_t; ///< Volatile 16-bit
    typedef volatile u32_t vu32_t; ///< Volatile 32-bit
    typedef atomic_uint au32_t;    ///< Atomic 32-bit

    // Register bitfields
    typedef union
    {
        u32_t word;
        struct
        {
            u32_t enable : 1;
            u32_t mode : 2;
            u32_t : 5; // Reserved
        } bits;
    } ctrl_reg_t;

    //==============================================================================
    // Robotics: Types and Constants
    //==============================================================================

    // Coordinates and motion
    typedef struct
    {
        f32_t x_mm;      ///< X position (mm)
        f32_t y_mm;      ///< Y position (mm)
        f32_t theta_rad; ///< Angle (rad)
    } pose2d_t;

    /// PID controller parameters
    typedef struct
    {
        f32_t kp;             ///< Proportional coefficient
        f32_t ki;             ///< Integral coefficient
        f32_t kd;             ///< Derivative coefficient
        f32_t integral_limit; ///< Integrator limit
    } pid_params_t;

    // Constants
    static const f32_t WHEEL_DIAMETER_MM = 65.0f;     ///< Wheel diameter
    static const f32_t ENCODER_PPR = 1024.0f;         ///< Pulses per revolution
    static const f32_t ROBOT_MAX_SPEED_MMPS = 500.0f; ///< Max speed (mm/s)

    // Function `printf()` usage
    (void)printf("%.2f\n", number); ///< Always add (void) before printf()
//==============================================================================
// Safety and Checks
//==============================================================================

// Null pointer check
#define CHECK_NULL(ptr)          \
    do                           \
    {                            \
        if (!(ptr))              \
            return ERR_NULL_PTR; \
    } while (0)

// Alignment check
#define CHECK_ALIGN(ptr, align)         \
    do                                  \
    {                                   \
        if ((uintptr_t)(ptr) % (align)) \
            return ERR_ALIGN;           \
    } while (0)

// Safe volatile access
#define VOL_ACCESS(addr) (*(volatile typeof(addr) *)&(addr))

// Value clamping
#define CLAMP(val, min, max) \
    ((val) < (min) ? (min) : ((val) > (max) ? (max) : (val)))

    //==============================================================================
    // RTOS and Tasks
    //==============================================================================

    /// FreeRTOS task priorities
    typedef enum
    {
        TASK_PRIO_IDLE = 0,   ///< Background task
        TASK_PRIO_LOW = 1,    ///< Low priority
        TASK_PRIO_NORMAL = 3, ///< Medium priority
        TASK_PRIO_HIGH = 5,   ///< High priority
    } task_prio_t;

    /// RTOS task template
    void task_template(void *params)
    {
        // 1. Initialization
        (void)params; // Suppress unused warnings

        // 2. Main loop
        for (;;)
        {
            // Task logic
            vTaskDelay(pdMS_TO_TICKS(10));
        }

        // 3. Exit (should never be reached)
        vTaskDelete(NULL);
    }

    //==============================================================================
    // Error Handling
    //==============================================================================

    /// Error codes
    typedef enum
    {
        ERR_OK = 0,      ///< Success
        ERR_INVALID_ARG, ///< Invalid argument
        ERR_TIMEOUT,     ///< Operation timeout
        ERR_HW_FAULT,    ///< Hardware fault
        ERR_BUSY,        ///< Resource busy
        ERR_NOT_INIT     ///< Module not initialized
    } err_code_t;

/// Error handling macro
#define RETURN_IF_ERR(expr)        \
    do                             \
    {                              \
        err_code_t __err = (expr); \
        if (__err != ERR_OK)       \
            return __err;          \
    } while (0)

//==============================================================================
// Interrupts (ISR)
//==============================================================================

// Compiler-specific attributes
#ifdef __GNUC__
#define ISR_ATTR __attribute__((interrupt))
#else
#define ISR_ATTR
#endif

    /// Interrupt handler template
    void TIM2_IRQHandler(void) ISR_ATTR
    {
        // 1. Check interrupt source
        // 2. Clear flags
        // 3. Minimal processing
        // 4. Exit
    }

    //==============================================================================
    // Usage Example
    //==============================================================================

    /**
     * @brief Initialize motor
     * @param[in] cfg Motor configuration
     * @param[out] handle Pointer to handle
     * @return err_code_t Initialization result
     *
     * @warning Do not call before PWM initialization!
     */
    err_code_t motor_init(const motor_cfg_t *cfg, motor_handle_t *handle)
    {
        CHECK_NULL(cfg);
        CHECK_NULL(handle);

        // ... implementation ...

        return ERR_OK;
    }

#ifdef __cplusplus
}
#endif

#endif /* STYLE_H */