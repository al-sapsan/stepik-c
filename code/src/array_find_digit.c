#include <stdio.h>

#define TOTAL     10

int main(void)
{
    int digs[TOTAL] = {0};
    size_t count = 0;
    size_t sz_ar = sizeof(digs) / sizeof(*digs);

    while(count < sz_ar && scanf("%d", &digs[count]) == 1)
        count++;

    int inserted = 0;
    for (size_t i = 0; i < count; ++i) {
        printf("%d ", digs[i]);
        if (!inserted && digs[i] == 5) {
            // Если есть место для вставки, сдвигаем элементы вправо
            if (count < sz_ar) {
                for (size_t j = count; j > i + 1; --j)
                    digs[j] = digs[j - 1];
                digs[i + 1] = -5;
                ++count;
            } else {
                // Если массив заполнен, сдвигаем элементы вправо, последний теряется
                for (size_t j = sz_ar - 1; j > i + 1; --j)
                    digs[j] = digs[j - 1];
                digs[i + 1] = -5;
            }
            printf("-5 ");
            inserted = 1;
        }
    }

    return 0;
}