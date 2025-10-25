#include <stdio.h>
#include <string.h>

int main(void)
{
    char ps[7][50];
    char ps_sort[7 * 50 + 6 + 1] = ""; // 7 фамилий, 6 пробелов, '\0'
    int idx[7];

    // Считываем 7 фамилий
    for (int i = 0; i < 7; ++i) {
        scanf("%49s", ps[i]);
        idx[i] = i;
    }

    // Сортировка индексов по длине фамилий (сортировка выбором)
    for (int i = 0; i < 6; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < 7; ++j) {
            if (strlen(ps[idx[j]]) < strlen(ps[idx[min_idx]]))
                min_idx = j;
        }
        // Обмен индексов
        if (min_idx != i) {
            int tmp = idx[i];
            idx[i] = idx[min_idx];
            idx[min_idx] = tmp;
        }
    }

    // Формируем строку ps_sort
    size_t pos = 0;
    for (int i = 0; i < 7; ++i) {
        size_t len = strlen(ps[idx[i]]);
        memcpy(ps_sort + pos, ps[idx[i]], len);
        pos += len;
        if (i < 6)
            ps_sort[pos++] = ' ';
    }
    ps_sort[pos] = '\0';

    printf("%s\n", ps_sort);

    return 0;
}