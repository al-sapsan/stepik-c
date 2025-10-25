#include <stdio.h>

int main() {
    int h1, m1, s1, h2, m2, s2;
    scanf("%d-%d-%d %d-%d-%d", &h1, &m1, &s1, &h2, &m2, &s2);

    // Переводим оба времени в секунды
    int t1 = h1 * 3600 + m1 * 60 + s1;
    int t2 = h2 * 3600 + m2 * 60 + s2;

    // Если разговор закончился после полуночи
    if (t2 < t1)
        t2 += 24 * 3600;

    int duration = t2 - t1;

    // Количество полных (или неполных) минут
    int minutes = duration / 60;
    if (duration % 60 != 0)
        minutes += 1;

    double cost = minutes * 0.07;
    printf("%.2f\n", cost);

    return 0;
}