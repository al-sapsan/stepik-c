#include <stdio.h>
#include <string.h>

#define MAX_CITIES 6
#define MAX_LEN 51 // 50 символов + 1 для '\0'

int main(void) 
{
    char cities[MAX_CITIES][MAX_LEN];
    size_t lens[MAX_CITIES];

    // Считываем 6 городов и вычисляем длины
    for (int i = 0; i < MAX_CITIES; ++i) {
        scanf("%50s", cities[i]);
        lens[i] = strlen(cities[i]);
    }

    // Находим максимальную и вторую по длине длины
    int first = -1, second = -1;
    for (int i = 0; i < MAX_CITIES; ++i) {
        if (first == -1 || lens[i] > lens[first]) {
            second = first;
            first = i;
        } else if ((second == -1 || lens[i] > lens[second]) && lens[i] != lens[first]) {
            second = i;
        }
    }

    // Если есть несколько городов с одинаковой максимальной длиной, ищем второй по длине среди оставшихся
    // (но если есть два города с одинаковой максимальной длиной, выводим оба)
    // Сначала ищем все города с максимальной длиной
    size_t max_len = lens[first];
    size_t second_len = 0;
    for (int i = 0; i < MAX_CITIES; ++i) {
        if (lens[i] < max_len && lens[i] > second_len)
            second_len = lens[i];
    }

    // Выводим все города с максимальной длиной, затем с второй по длине, в порядке следования
    int printed = 0;
    for (int i = 0; i < MAX_CITIES; ++i) {
        if (lens[i] == max_len) {
            if (printed) printf(" ");
            printf("%s", cities[i]);
            printed = 1;
        }
    }
    for (int i = 0; i < MAX_CITIES; ++i) {
        if (lens[i] == second_len) {
            if (printed) printf(" ");
            printf("%s", cities[i]);
            printed = 1;
        }
    }
    printf("\n");
    return 0;
}
