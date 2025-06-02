#include <stdio.h>
#include <string.h>

#define MAXLEN 20

int main() {
    char key = 'Y';
    char str[MAXLEN];

    printf("Введите строку не более %d символов: ", MAXLEN - 1);
    fgets(str, MAXLEN, stdin);

    // Шифрование
    for (int i = 0; i < strlen(str); i++) {
        str[i] = str[i] ^ key;
    }
    printf("Зашифрованная строка: %s\n", str);

    // Дешифрование
    for (int i = 0; i < strlen(str); i++) {
        str[i] = str[i] ^ key;
    }
    printf("Восстановленная строка: %s\n", str);

    return 0;
}