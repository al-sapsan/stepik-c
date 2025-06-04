#include <stdio.h>
/**
 * @brief 
 * 
 * @return int 
 */
int main() {
    int distance, minutes, seconds;

    if (scanf("%d %d:%d", &distance, &minutes, &seconds) != 3) {
        printf("Input error.\n");
        return 0;
    }

    // Переводим время в часы
    double time_hours = minutes / 60.0 + seconds / 3600.0;
    // Переводим дистанцию в километры
    double distance_km = distance / 1000.0;
    // Вычисляем скорость
    double speed = distance_km / time_hours;

    printf("%.2f\n", speed);

    return 0;
}