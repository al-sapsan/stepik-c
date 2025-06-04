#include <stdio.h>
#define MASK (1 << 2) // Маска для 2-го бита (третий справа)

int main() {
    char ch;
    if (scanf("%c", &ch) != 1) {
        printf("Input error.\n");
        return 0;
    }
    // Декодируем исходный символ
    unsigned char bits = ch ^ '$';

    // Проверяем третий справа бит
    printf("%s", ((bits & MASK) == MASK) ? "Наступаем" : "Ожидаем");

    return 0;
}