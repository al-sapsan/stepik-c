/**
 * @file lambda_equivalence.c
 * @brief Программа для проверки эквивалентности двух булевых функций
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_VARS 10      ///< Максимальное количество переменных
#define MAX_EXPR_LEN 256 ///< Максимальная длина выражения

typedef struct
{
    char name;
    bool value;
} Variable;

/**
 * @brief Пропускает пробелы в строке
 * @param[in] s Входная строка
 * @return Указатель на первый непробельный символ
 */
const char *skip_spaces(const char *s)
{
    while (isspace(*s))
        s++;
    return s;
}

/**
 * @brief Извлекает имена переменных из лямбда-функции
 * @param[in] lambda Строка с лямбда-функцией
 * @param[out] vars Массив для сохранения переменных
 * @return Количество найденных переменных
 */
int extract_variables(const char *lambda, Variable vars[MAX_VARS])
{
    int count = 0;
    const char *ptr = strchr(lambda, ' ') + 1; // После "lambda "

    while (*ptr != ':')
    {
        if (isupper(*ptr))
        {
            vars[count].name = *ptr;
            count++;
            if (count >= MAX_VARS)
                break;
        }
        ptr++;
    }
    return count;
}

/**
 * @brief Вычисляет значение переменной
 * @param[in] vars Массив переменных
 * @param[in] count Количество переменных
 * @param[in] name Имя переменной
 * @return Значение переменной
 */
bool get_var_value(Variable vars[MAX_VARS], int count, char name)
{
    for (int i = 0; i < count; i++)
    {
        if (vars[i].name == name)
        {
            return vars[i].value;
        }
    }
    return false;
}

/**
 * @brief Вычисляет булево выражение
 * @param[in] expr Выражение для вычисления
 * @param[in] vars Массив переменных
 * @param[in] var_count Количество переменных
 * @param[inout] pos Позиция в выражении (будет обновляться)
 * @return Результат вычисления
 */
bool evaluate_expr(const char *expr, Variable vars[MAX_VARS], int var_count, int *pos)
{
    expr = skip_spaces(expr + *pos);
    bool result = false;

    if (expr[0] == '(')
    {
        (*pos)++;
        result = evaluate_expr(expr, vars, var_count, pos);
        expr = skip_spaces(expr + *pos);
        if (expr[0] == ')')
        {
            (*pos)++;
        }
    }
    else if (strncmp(expr, "not ", 4) == 0)
    {
        *pos += 4;
        result = !evaluate_expr(expr, vars, var_count, pos);
    }
    else if (isupper(expr[0]))
    {
        result = get_var_value(vars, var_count, expr[0]);
        (*pos)++;
    }

    expr = skip_spaces(expr + *pos);

    if (strncmp(expr, "or ", 3) == 0)
    {
        *pos += 3;
        result = result || evaluate_expr(expr, vars, var_count, pos);
    }
    else if (strncmp(expr, "and ", 4) == 0)
    {
        *pos += 4;
        result = result && evaluate_expr(expr, vars, var_count, pos);
    }

    return result;
}

/**
 * @brief Проверяет эквивалентность двух булевых функций
 * @param[in] func1 Первая функция
 * @param[in] func2 Вторая функция
 * @retval true Функции эквивалентны
 * @retval false Функции не эквивалентны
 */
bool check_equivalence(const char *func1, const char *func2)
{
    Variable vars[MAX_VARS];
    int var_count = extract_variables(func1, vars);

    const char *expr1 = strchr(func1, ':') + 1;
    const char *expr2 = strchr(func2, ':') + 1;

    for (int mask = 0; mask < (1 << var_count); mask++)
    {
        for (int i = 0; i < var_count; i++)
        {
            vars[i].value = (mask >> i) & 1;
        }

        int pos1 = 0, pos2 = 0;
        bool res1 = evaluate_expr(expr1, vars, var_count, &pos1);
        bool res2 = evaluate_expr(expr2, vars, var_count, &pos2);

        if (res1 != res2)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char func1[MAX_EXPR_LEN];
    char func2[MAX_EXPR_LEN];

    fgets(func1, MAX_EXPR_LEN, stdin);
    fgets(func2, MAX_EXPR_LEN, stdin);

    func1[strcspn(func1, "\n")] = '\0';
    func2[strcspn(func2, "\n")] = '\0';

    if (check_equivalence(func1, func2))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}