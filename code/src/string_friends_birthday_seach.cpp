/**
 * @file    friend_lookup.cpp
 * @brief   Поиск и вывод информации о друге по фамилии. Строки выделяются динамически.
 * @version 1.4
 */

#include <cstdio>
#include <cstring>
#include <cstdint>

/*** Constants ***/
static constexpr int32_t MAX_NAME_LEN = 64;
static constexpr int32_t MAX_DATE_LEN = 32;

/*** Function Prototypes ***/

/**
 * @brief Выполняет бинарный поиск фамилии в отсортированном массиве строк
 * @param[in] arr Массив указателей на строки
 * @param[in] n Количество строк
 * @param[in] search_str Строка для поиска
 * @return Индекс найденной строки, либо -1 если не найдено
 */
int32_t binary_search(char **arr, size_t n, const char *search_str);

/**
 * @brief Выполняет линейный поиск фамилии в массиве строк
 * @param[in] arr Массив указателей на строки
 * @param[in] n Количество строк
 * @param[in] search_str Строка для поиска
 * @return Индекс найденной строки, либо -1 если не найдено
 */
int32_t linear_search(char **arr, size_t n, const char *search_str);

/**
 * @brief Сортировка массива строк по фамилии (выбором)
 * @param[in,out] arr Массив указателей на строки
 * @param[in] n Количество строк
 */
void sort_array(char **arr, size_t n);

/*** Main Function ***/
int main(void)
{
    size_t n = 0;
    std::scanf("%d", &n);

    char **arr_ptr = new char *[n];
    char surname[MAX_NAME_LEN], date[MAX_DATE_LEN];

    // Ввод и создание строк
    for (size_t i = 0; i < n; ++i)
    {
        std::scanf("%s %s", surname, date);
        size_t len = std::strlen(surname) + 1 + std::strlen(date) + 1;
        arr_ptr[i] = new char[len];
        std::snprintf(arr_ptr[i], len, "%s %s", surname, date);
    }

    // Сортировка по фамилии
    sort_array(arr_ptr, n);

    // Ввод искомой фамилии
    char search[MAX_NAME_LEN];
    std::scanf("%s", search);

    // Поиск (можно заменить на linear_search)
    int32_t index = binary_search(arr_ptr, n, search);

    if (index >= 0)
    {
        std::puts(arr_ptr[index]);
    }
    else
    {
        std::puts("No");
    }

    // Очистка
    for (size_t i = 0; i < n; ++i)
    {
        delete[] arr_ptr[i];
    }
    delete[] arr_ptr;

    return 0;
}

/*** Function Definitions ***/

int32_t binary_search(char **arr, size_t n, const char *search_str)
{
    int32_t left = 0, right = n - 1;

    while (left <= right)
    {
        int32_t mid = left + (right - left) / 2;
        char *space = std::strchr(arr[mid], ' ');
        int32_t name_len = space ? static_cast<int32_t>(space - arr[mid]) : static_cast<int32_t>(std::strlen(arr[mid]));

        int cmp = std::strncmp(search_str, arr[mid], name_len);
        if (cmp == 0 && search_str[name_len] == '\0')
        {
            return mid;
        }
        if (cmp < 0 || (cmp == 0 && search_str[name_len] != '\0'))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int32_t linear_search(char **arr, size_t n, const char *search_str)
{
    for (size_t i = 0; i < n; ++i)
    {
        char *space = std::strchr(arr[i], ' ');
        int32_t name_len = space ? static_cast<int32_t>(space - arr[i]) : static_cast<int32_t>(std::strlen(arr[i]));

        if (std::strncmp(search_str, arr[i], name_len) == 0 && search_str[name_len] == '\0')
        {
            return i;
        }
    }
    return -1;
}

void sort_array(char **arr, size_t n)
{
    for (size_t k = 0; k < n - 1; ++k)
    {
        int32_t min_idx = k;
        for (size_t i = k + 1; i < n; ++i)
        {
            char *space_min = std::strchr(arr[min_idx], ' ');
            char *space_i = std::strchr(arr[i], ' ');
            int32_t len_min = space_min ? static_cast<int32_t>(space_min - arr[min_idx]) : static_cast<int32_t>(std::strlen(arr[min_idx]));
            int32_t len_i = space_i ? static_cast<int32_t>(space_i - arr[i]) : static_cast<int32_t>(std::strlen(arr[i]));

            int cmp = std::strncmp(arr[i], arr[min_idx], len_min < len_i ? len_min : len_i);
            if (cmp == 0)
                cmp = len_i - len_min;

            if (cmp < 0)
                min_idx = i;
        }

        if (min_idx != k)
        {
            char *tmp = arr[k];
            arr[k] = arr[min_idx];
            arr[min_idx] = tmp;
        }
    }
}
