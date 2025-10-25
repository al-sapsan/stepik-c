#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 // Максимальная длина строки

int main() {
    char input[MAX_LENGTH]; // Буфер для ввода

    // 1. Ввод строки с клавиатуры
    printf("Введите строку (не более %d символов):\n", MAX_LENGTH - 1);
    fgets(input, MAX_LENGTH, stdin);

    // 2. Удаление символа новой строки '\n' (если он есть)
    // fgets сохраняет '\n' в буфере, если хватает места
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0'; // Заменяем '\n' на терминатор
    }

    // 3. Вывод результата
    printf("Вы ввели: \"%s\"\n", input);

    return 0;
}