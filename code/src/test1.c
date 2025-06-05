#include <stdio.h>

int main() {
    int option, a, b;
    scanf("%d %d %d", &option, &a, &b);

    // Проверка корректности варианта
    if (option < 1 || option > 3) {
        printf("ERROR\n");
        return 0;
    }

    switch (option) {
        case 1: {
            // Вариант 1: Расчет минимального количества строк
            int desired = a;
            int late = b;
            int penalty = (late / 3) * 20;
            int needed_payment = desired + penalty;
            
            // Расчет минимального количества сотен строк
            int hundreds = (needed_payment + 49) / 50;
            if (hundreds * 50 - penalty < desired) {
                hundreds++;
            }
            printf("%d\n", hundreds * 100);
            break;
        }
        
        case 2: {
            // Вариант 2: Расчет максимального числа опозданий
            int lines = a;
            int desired = b;
            int base_payment = (lines / 100) * 50;
            
            // Проверка возможности достичь желаемого дохода
            if (base_payment < desired) {
                printf("ERROR\n");
                break;
            }
            
            // Расчет допустимого штрафа
            int allowed_penalty = base_payment - desired;
            int max_late_triplets = allowed_penalty / 20;
            int max_late = max_late_triplets * 3;
            
            // Корректировка для граничного случая
            if ((base_payment - ((max_late + 1) / 3 * 20)) >= desired) {
                max_late += 2;
            }
            printf("%d\n", max_late);
            break;
        }
        
        case 3: {
            // Вариант 3: Расчет итоговой зарплаты
            int lines = a;
            int late = b;
            int payment = (lines / 100) * 50;
            int penalty = (late / 3) * 20;
            int result = payment - penalty;
            printf("%d\n", result > 0 ? result : 0);
            break;
        }
    }

    return 0;
}