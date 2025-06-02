#include <stdio.h>
#include <math.h>

int main() {
    double x;
    scanf("%lf", &x);

    double y = pow(cos(x), 2) + 0.5 * pow(cos(x), 4);

    printf("%.3f\n", y);

    return 0;
}