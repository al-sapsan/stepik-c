/**
 * @file style.h
 * @brief Coding style rules for Embedded/Robotics projects (C99/C++11)
 * @details Strict naming conventions for reliability and maintainability
 */

#pragma once

/**************************************
 *         GENERAL PRINCIPLES         *
 **************************************/
// 1. Names MUST be self-descriptive
// 2. Avoid abbreviations (unless standardized)
// 3. Follow project-wide consistency

/**************************************
 *            VARIABLES               *
 **************************************/
// Format: [scope_][description]_[type][unit]

// Scope prefixes (optional but recommended):
#define VAR_GLOBAL(NAME) g_##NAME // Global variables
#define VAR_MEMBER(NAME) m_##NAME // Struct/class members
#define VAR_STATIC(NAME) s_##NAME // Static variables

// Type suffixes (mandatory for primitive types):
#define VAR_U8(NAME) NAME##_u8   // uint8_t
#define VAR_I16(NAME) NAME##_i16 // int16_t
#define VAR_F32(NAME) NAME##_f32 // float

// Physical units (when applicable):
#define UNIT_DEG(NAME) NAME##_deg // Degrees
#define UNIT_MS(NAME) NAME##_ms   // Milliseconds
#define UNIT_MA(NAME) NAME##_mA   // Milliamperes

// Example declarations:
// uint16_t VAR_GLOBAL(voltage)_u16_mV = 0;
// static int32_t VAR_STATIC(encoder)_i32_pulses = 0;

/**************************************
 *             CONSTANTS              *
 **************************************/
// Format: [MODULE_][DESCRIPTION]_[TYPE]
#define CONST_U16(NAME, MODULE) MODULE##_##NAME##_U16
#define CONST_F32(NAME, MODULE) MODULE##_##NAME##_F32

// Examples:
// #define CONST_U16(MAX_SPEED, MOTOR)  3000  // MOTOR_MAX_SPEED_U16
// #define CONST_F32(KP, PID)           1.5f  // PID_KP_F32

/**************************************
 *           STRUCTURES               *
 **************************************/
// Format: [module]_t or [module]_[desc]_t
typedef struct
{
    VAR_MEMBER(angle)
    _f32_deg; // Current angle
    VAR_MEMBER(speed)
    _u16_rpm; // Rotation speed
} motor_state_t;

/**************************************
 *             FUNCTIONS              *
 **************************************/
// Format: [module]_[action]_[result]
// Return type as suffix (optional for simple types)

// Control functions:
#define FUNC_INIT(MODULE) MODULE##_init
#define FUNC_SET(MODULE, PARAM) MODULE##_set_##PARAM

// Examples:
// void FUNC_INIT(motor)(void);
// int8_t FUNC_SET(motor)(speed, u16)(uint16_t rpm);

/**************************************
 *              MACROS                *
 **************************************/
// Format: [MODULE_][ACTION]_[PARAM]
#define MACRO_ENABLE(MODULE) MODULE##_ENABLE
#define MACRO_DISABLE(MODULE) MODULE##_DISABLE

// Example:
// #define MACRO_ENABLE(PID)  do { ... } while(0)

/**************************************
 *            ENUMERATIONS            *
 **************************************/
// Format: [module]_[desc]_e
typedef enum
{
    STATE_IDLE,
    STATE_CALIBRATING,
    STATE_RUNNING
} motor_state_e;

/**************************************
 *              BIT FIELDS            *
 **************************************/
// Format: [MODULE_][DESCRIPTION]_[MASK|POS|BIT]
#define BIT_POS(NAME, MODULE) MODULE##_##NAME##_POS
#define BIT_MASK(NAME, MODULE) MODULE##_##NAME##_MASK

// Example:
// #define BIT_POS(READY, STATUS)  0
// #define BIT_MASK(ERROR, STATUS) (0x3 << 4)

/**************************************
 *           SPECIAL CASES            *
 **************************************/
// 1. Registers: Match datasheet names exactly
// 2. ISRs: Prefix with module name
//    Example: void TIM2_IRQ_Handler(void);

#endif // STYLE_H

// Использование style.h ссылка ниже:
// https://github.com/al-sapsan/stepik-c/wiki/4.-Использование-style.h-в-разработке