#include <iostream>
#include <iomanip>
using namespace std;

/**
 * @brief Calculates the area of a square
 * @param side Length of the square's side
 * @return Area of the square (side * side)
 */
double myArea(double side) 
{
    return side * side;  // Square area formula
}

/**
 * @brief Calculates the area of a rectangle
 * @param length Length of the rectangle
 * @param width Width of the rectangle
 * @return Area of the rectangle (length * width)
 */
double myArea(double length, double width) 
{
    return length * width;  // Rectangle area formula
}

int main() 
{
    double x, y, z;
    cin >> x >> y >> z;
    // Output square area (using x) and rectangle area (using y and z)
    cout << fixed << setprecision(4) << myArea(x) << " " << myArea(y, z);
    
    return 0;
}