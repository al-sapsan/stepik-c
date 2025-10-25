#include <stdio.h>

/**
 * @brief Информер по этажам здания.
 *
 * Пользователь вводит номер этажа, программа выводит, что находится на этом этаже.
 * Если этаж вне диапазона 1-10, выводится сообщение об ошибке.
 *
 * @return 0 при успешном завершении
 */
int main() {
    int number;
    printf("Введите номер этажа: ");
    scanf("%d", &number);

    switch (number) {
        case 1: case 2: case 3:
            printf("Торговый центр\n");
            break;
        case 4:
            printf("Фудкорт\n");
            break;
        case 5: case 6: case 7:
            printf("EPAM Systems\n");
            break;
        case 8:
            printf("Агенство недвижимости \"Столица\"\n");
            break;
        case 9: case 10:
            printf("Офисы различных компаний\n");
            break;
        default:
            printf("В здании только 10 этажей!\n");
    }
    return 0;
}
