#include <stdio.h>
#define PI 3.14159

/**
 * @brief  Calculate the area and circumference of a circle. 
 * 
 * @param r  Radius of the circle. 
 * @param length   Pointer to store the circumference of the circle.
 * @return double  Area of the circle
 */
double circle(double r, double *length) {
    double square = PI * r * r;
    *length = 2 * PI * r;
    return square;
}

int main() {
    double r, square, length;
    scanf("%lf", &r);
    square = circle(r, &length);
    printf("%.2lf %.2lf\n", square, length);
    return 0;
}