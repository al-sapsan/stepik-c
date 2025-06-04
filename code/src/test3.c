#include <stdio.h>

/**
 * @brief Вычисляет минимальное количество топлива для дозаправки в пункте В.
 *
 * @return 0 при успешном завершении
 */
int main() {
    double ab, bc, weight;
    scanf("%lf %lf %lf", &ab, &bc, &weight);

    double rate;
    if (weight < 0 || weight > 2000) {
        printf("ERROR\n");
        return 0;
    } else if (weight <= 500) {
        rate = 1;
    } else if (weight <= 1000) {
        rate = 4;
    } else if (weight <= 1500) {
        rate = 7;
    } else {
        rate = 9;
    }

    double fuel_ab = ab * rate;
    double fuel_bc = bc * rate;

    // Проверка: самолет не может преодолеть участок на одном баке
    if (fuel_ab > 300 || fuel_bc > 300) {
        printf("ERROR\n");
        return 0;
    }

    // Сколько топлива останется после первого участка
    double remain = 300 - fuel_ab;
    // Сколько нужно дозаправить в В, чтобы хватило до С
    double refill = (fuel_bc > remain) ? (fuel_bc - remain) : 0.0;

    printf("%.2f\n", refill);
    return 0;
}