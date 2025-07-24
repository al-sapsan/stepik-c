/*******************************************************************************
 * @file script1.c
 * @brief Вариадическая функция для квадратичной нормы вектора
 * @version 1.0
 * @date 2025-07-23
 ******************************************************************************/
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/*** Function Prototype ***/
/**
 * @brief Quadratic norm of vector (variadic)
 * @param ptr_type Строка с типом вектора
 * @return Квадратичная норма
 * @details Вычисляет норму для vector2, vector3, vector4, иначе 0.0
 */
double v_norm2(const char *ptr_type, ...);

/*** Main Function ***/
int main(void)
{
    double res = v_norm2("vector2", 1.0, 2.0);
    printf("%.1f\n", res);
    return 0;
}

/*** Function Implementation ***/
double v_norm2(const char *ptr_type, ...)
{
    int n = 0;
    if (strcmp(ptr_type, "vector2") == 0)
        n = 2;
    else if (strcmp(ptr_type, "vector3") == 0)
        n = 3;
    else if (strcmp(ptr_type, "vector4") == 0)
        n = 4;
    else
        return 0.0;
    double norm2 = 0.0;
    va_list args;
    va_start(args, ptr_type);
    for (int i = 0; i < n; ++i)
    {
        double val = va_arg(args, double);
        norm2 += val * val;
    }
    va_end(args);
    return norm2;
}
