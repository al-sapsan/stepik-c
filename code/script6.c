#include <stdio.h>
/**
 * @brief  Function to average two double values. 
 * 
 */
void usred(double *x, double *y) {
    double average = (*x + *y) / 2.0;
    *x = average;
    *y = average;
}

int main() {
    double x, y;
    scanf("%lf %lf", &x, &y);
    usred(&x, &y);
    printf("%.1lf %.1lf\n", x, y);
    return 0;
}