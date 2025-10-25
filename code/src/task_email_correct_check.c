#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char str[100] = {0};
    fgets(str, sizeof(str), stdin);
    
    // Удаляем символ новой строки
    str[strcspn(str, "\n")] = '\0';
    int len = strlen(str);
    
    // Проверяем минимальную длину (a@b.c - 5 символов)
    if (len < 5) {
        printf("0\n");
        return 0;
    }

    int at_pos = -1, at_count = 0;
    int valid = 1;

    // Проверяем все символы на допустимость
    for (int i = 0; i < len && valid; ++i) {
        char c = str[i];
        if (!(isalnum(c) || c == '.' || c == '_' || c == '-' || c == '@')) {
            valid = 0;
            break;
        }
        
        if (c == '@') {
            at_count++;
            at_pos = i;
        }
    }

    // Должен быть ровно один '@', не первый и не последний
    if (at_count != 1 || at_pos == 0 || at_pos == len - 1) {
        valid = 0;
    }

    // Проверяем часть после @
    if (valid) {
        int has_dot = 0;
        // Точка не может быть сразу после @
        if (str[at_pos + 1] == '.') {
            valid = 0;
        }
        else {
            // Ищем хотя бы одну точку после @ (не в конце)
            for (int i = at_pos + 1; i < len - 1; ++i) {
                if (str[i] == '.') {
                    has_dot = 1;
                    break;
                }
            }
            if (!has_dot) {
                valid = 0;
            }
        }
    }

    // Дополнительная проверка: не должно быть двух точек подряд
    if (valid) {
        for (int i = 1; i < len; ++i) {
            if (str[i] == '.' && str[i-1] == '.') {
                valid = 0;
                break;
            }
        }
    }

    // Проверяем, что точка не последняя
    if (valid && str[len-1] == '.') {
        valid = 0;
    }

    printf("%d\n", valid);
    return 0;
}