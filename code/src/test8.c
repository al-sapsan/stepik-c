#include <stdio.h>
#define CENTIMETERS_PER_INCH 2.54

/**
 * @brief Преобразует расстояние между дюймами и сантиметрами.
 *
 * Пользователь выбирает направление преобразования:
 * 1 — дюймы в сантиметры, 2 — сантиметры в дюймы.
 * Затем вводит значение расстояния. Программа выводит результат
 * с точностью до двух знаков после запятой.
 *
 * @return 0 при успешном завершении
 */
int main() {

    int choice;      /**< Направление преобразования */
    double distance; /**< Введённое расстояние */

    if (scanf("%d %lf", &choice, &distance) != 2) {
        printf("Input error.\n"); ///< Проверка корректности ввода
        return 0;
    }
    if (choice == 1) {
        printf("%.2lf\n", distance *  CENTIMETERS_PER_INCH); ///< Перевод дюймов в сантиметры
    } else if (choice == 2) {
        printf("%.2lf\n", distance / CENTIMETERS_PER_INCH); ///< Перевод сантиметров в дюймы
    } else {
        printf("Invalid choice.\n"); ///< Проверка корректности выбора
        return 0;
    } 
    return 0;
}