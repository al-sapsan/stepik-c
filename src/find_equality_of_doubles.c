#include <stdio.h>

int main() {
    double three = 3.0;
    double x, y, z;
    x = 1 / three;
    y = 4 / three;
    z = 5 / three;

    if (x + y == z) { // не рекомендуется использовать в C, 
                      // так как может привести к проблемам с точностью 
                      // используем if (abs(a - b) < 1e-6)
        printf("1/3 + 4/3 = 5/3\n");
    } else {
        printf("1/3 + 4/3 != 5/3\n");
    }

    return 0;
}