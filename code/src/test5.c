#include <stdio.h>
#define PI 3.14159265358979323846

int main() {
    double r1, r2, r3;
    scanf("%lf %lf %lf", &r1, &r2, &r3);

    double l1 = 2 * PI * r1;
    double l2 = 2 * PI * r2;
    double l3 = 2 * PI * r3;

    printf("%7.2f\n", l1);
    printf("%7.2f\n", l2);
    printf("%7.2f\n", l3);

    return 0;
}