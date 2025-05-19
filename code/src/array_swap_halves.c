#include <stdio.h>

#define SIZE_BUFFER     128

int main(void)
{
    int buffer[SIZE_BUFFER];
    size_t count = 0;
    size_t sz_ar = sizeof(buffer) / sizeof(*buffer);

    while(count < sz_ar && scanf("%d", &buffer[count]) == 1)
        count++;

    // Меняем местами первую и вторую половины массива
    size_t half = count / 2;
    for (size_t i = 0; i < half; ++i) {
        // Для нечетного count центральный элемент не трогаем
        int tmp = buffer[i];
        buffer[i] = buffer[half + (count % 2) + i];
        buffer[half + (count % 2) + i] = tmp;
    }

    // Выводим первые count элементов массива
    for (size_t i = 0; i < count; ++i)
        printf("%d ", buffer[i]);

    return 0;
}