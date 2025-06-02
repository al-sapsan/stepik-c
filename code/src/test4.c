#include <stdio.h>
#include <math.h>

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);

    double c = sqrt(a*a + b*b);

    printf("%.3f\n", c);

    return 0;
}